;; ============================================================================
;;  vesc_esc_emulator.lisp   v1.0   (BENCH-VALIDIERUNG ERFORDERLICH!)
;;  Weg 2: Der VESC emuliert den Original-ESC der Teverun-IVCU.
;;  ---------------------------------------------------------------------------
;;  Die Stock-IVCU bleibt unveraendert (Display/App/EEPROM wie ab Werk);
;;  der VESC haengt am ESC-Port der IVCU (USART2, 9600 Bd, 3,3 V):
;;     IVCU -> VESC : '4A'-Frames (Settings: Gang, Limits, Stroeme, Flags)
;;     VESC -> IVCU : '71'-Statusframes, Subtyp 3A/3B (Alive <= 600 ms je Typ!)
;;
;;  Gas + Bremse haengen NICHT an der IVCU (dort kein ADC) -> direkt an die
;;  ADC-Eingaenge des VESC. VESC App = "None", dieses Skript regelt.
;;
;;  UART-BAUD: 9600!  (uart-start 9600 unten; ausserdem empfiehlt es sich,
;;  die UART-Rate im VESC-Tool passend zu stellen, falls die FW sie nicht
;;  ueber das Skript setzt.)
;;
;;  Frame-Layouts + offene Punkte: ../ESC_Emulation_VESC.md  (Byte [1] und die
;;  Datenbyte->Anzeigefeld-Zuordnung per Sniffer klaeren!)
;;
;;  WICHTIG: API-Namen (uart*/buf*/get-*/set-*) je VESC-FW-Stand pruefen.
;; ============================================================================

;; ---------------------------------------------------------------------------
;; 1) KONFIGURATION
;; ---------------------------------------------------------------------------
(def WHEEL_MM 254.0)                       ; 10"=254
(def CIRC_MM (* 3.14159265358979 WHEEL_MM))
(def WHEEL_CODE 100)                       ; Zoll*10 (muss zu WHEEL_MM passen)
(def ROT_RAW_SHIFT 16.0)                   ; HYPOTHESE: ESC[10] = rot/16 (Bench!)
(def POLE_PAIRS 15)
(def PACK_S 16)

;; Default-Gangtabelle (wird durch die '4A'-Frames der IVCU live ersetzt)
(def GEAR_LIMIT_KMH (list 15 20 25 35 45))
(def GEAR_CURRENT_A (list 15 20 25 30 55))
(def GEAR_RAMP_MS   (list 900 700 550 400 300))
(def GEAR_EABS_A    (list 8 12 16 22 30))

;; ADC: Kanal 0 = Gas, Kanal 1 = Bremse (COMM-Port); anpassen!
(def ADC_THR_CH 0) (def ADC_BRK_CH 1)
(def THR_MIN 0.60) (def THR_MAX 3.00)
(def BRK_MIN 0.60) (def BRK_MAX 2.60)
(def THR_DEADBAND 0.04)
(def THR_CURVE_EXP 1.35)
(def ECO_FACTOR 0.60)
(def POWER_LIMIT 1.00)
(def TEMP_MOT_MAX 120) (def TEMP_FET_MAX 85)

;; Takte
(def LOOP_MS 10)                           ; Regelzyklus
(def CNT_71 10)                            ; alle 10 Zyklen = 100 ms -> 3A/3B
(def IVCU_TIMEOUT_CNT 200)                 ; 200*10 ms = 2 s ohne 0x4A -> Defaults
(def DUAL 0)                               ; 0=Single (Antwort[11].B0=0 -> 0x11-Protokoll), 1=Dual
(def CAN_SLAVE_ID 1)                       ; Weg 2 Dual: Controller-ID des 2. ESC (VESC Tool, CAN)

;; ---------------------------------------------------------------------------
;; 2) LISPBM-KAPSELUNG (Namen je FW pruefen!)
;; ---------------------------------------------------------------------------
(defun buf-new (n)         (bufcreate n))
(defun buf-put (b i v)     (bufset-u8 b i v))
(defun buf-get (b i)       (bufget-u8 b i))
(defun buf-put16be (b i v) (progn (buf-put b i (/ (round v) 256))
                                  (buf-put b (+ i 1) (mod (round v) 256))))
(defun pow2 (n) (if (= n 0) 1 (* 2 (pow2 (- n 1)))))
(defun bit? (v n) (= 1 (mod (/ v (pow2 n)) 2)))
(defun xor8 (a b)                          ; portables Byte-XOR
  (let ((x 0) (i 0) (p 1))
    (loopwhile (< i 8)
      (progn (if (not (= (bit? a i) (bit? b i))) (setq x (+ x p)) nil)
             (setq p (* 2 p)) (setq i (+ i 1)))) x))
(defun xor-buf (b n) (let ((x 0) (i 0))
    (loopwhile (< i n) (progn (setq x (xor8 x (buf-get b i))) (setq i (+ i 1)))) x))
(defun clamp (v lo hi) (if (< v lo) lo (if (> v hi) hi v)))

;; ---------------------------------------------------------------------------
;; 3) ZUSTAND
;; ---------------------------------------------------------------------------
(def gear 2) (def eco 0) (def soc 80) (def speed_kmh 0.0)
(def pack_v 60.0) (def t_mot 30) (def t_fet 30) (def cur_now 0.0)
(def cur_cmd 0.0) (def odo_m 0.0) (def cnt 0)
(def sub71 0)                              ; 0/1 -> sendet 3A/3B abwechselnd

;; Link-Zustand (aus '4A'-Frames der IVCU)
(def lk_gear 2) (def lk_start 0) (def lk_limit 0) (def lk_cur 0)
(def lk_valid 0) (def lk_miss 0) (def lk_bad 0)   ; lk_bad = Checksum-Mismatches

(def rx (buf-new 32))
(def uart-tx (buf-new 32))
(uart-start 9600)

;; ---------------------------------------------------------------------------
;; 4) IVCU-EMPFANG: '4A'-Settingsframes (11 3A/3B = 17 B, 14 3A/3B = 20 B)
;; ---------------------------------------------------------------------------
(defun read-rest (n start)                 ; (n-1) weitere Bytes nach rx[start-1]
  (let ((got 1))
    (loopwhile (< got n)
      (setq got (+ got (uart-read rx (- n got) (+ start got -1) nil nil 0.05))))
    got))
(defun rd-esc-4a ()
  ;; erstes Byte (0x4A) liegt bereits in rx[0]; jetzt Laengenbyte rx[1]:
  (if (= 1 (uart-read rx 1 1 nil nil 0.05))
    (let ((len (buf-get rx 1)))
      (let ((n (if (= len 0x14) 20 17)))
        (if (= n (read-rest n 2))
          (progn
            ;; Checksumme nur diagnostisch (0x11-Eigenheit: XOR ueber 19 Puffer-
            ;; bytes, gesendet aber 16+ck -> Mismatch moeglich und toleriert)
            (if (not (= (buf-get rx (- n 1)) (xor-buf rx (- n 1))))
                (setq lk_bad (+ lk_bad 1)) nil)
            ;; Feldtabelle siehe ../ESC_Emulation_VESC.md Abschnitt 1.1
            (setq lk_gear  (buf-get rx 4))          ; Gang 0-basiert
            (setq lk_start (buf-get rx 9))          ; Start-Level
            (setq lk_limit (buf-get rx 10))         ; Speed-Limit km/h
            (setq lk_cur   (buf-get rx 12))         ; Phasenstrom A
            (setq lk_valid 1)
            (setq lk_miss 0)))))))
(defun poll-uart ()
  (if (> (uart-read rx 1 nil nil 0) 0)
    (if (= (buf-get rx 0) 0x4A) (rd-esc-4a) nil)))

;; ---------------------------------------------------------------------------
;; 5) SENDER: '71'-Statusframes (13 B; [2]=3A/3B, [12]=XOR ueber [0..11])
;;    OHNE diese Frames > 600 ms setzt die IVCU Alive-Fehler!
;; ---------------------------------------------------------------------------
(defun esc-send-71 (subtype)
  (progn
    (buf-put uart-tx 0 0x71)
    (buf-put uart-tx 1 0x00)                    ; unbekannt -> Sniffer!
    (buf-put uart-tx 2 subtype)
    (buf-put uart-tx 3 0x00)                    ; Status (0 = OK)
    (buf-put uart-tx 4 0x00)
    (buf-put16be uart-tx 5 (clamp (round (* pack_v 10.0)) 0 0xFFFF))  ; 0,1 V
    (buf-put uart-tx 7 (clamp (round (+ t_mot 40)) 0 255))            ; Temp
    (buf-put16be uart-tx 8 (clamp (round (* cur_now 10.0)) 0 0xFFFF)) ; 0,1 A
    ;; [10] = Rot-Rohwert (1 Byte! FW: ESC[10] -> RAM 0x200002E4; Skalierung
    ;;        rot/ROT_RAW_SHIFT = HYPOTHESE -> per Bench kalibrieren)
    ;; [11] = Flags, Bit0 = Dual-Motorfaehigkeit (nur die 3A-Antwort setzt
    ;;        0x20000398 und steuert damit 0x11/0x14; DUAL oben konfigurieren)
    (let ((rot (if (< speed_kmh 0.5) 0
                 (clamp (round (/ (* WHEEL_CODE 287.0) speed_kmh)) 1 3000))))
      (progn
        (buf-put uart-tx 10 (if (= rot 0) 0
                              (clamp (round (/ rot ROT_RAW_SHIFT)) 1 255)))
        (buf-put uart-tx 11 (if (= DUAL 0) 0 1))))
    (buf-put uart-tx 12 (xor-buf uart-tx 12))
    (uart-write uart-tx)))

;; Dual (2. ESC): Strom per CAN an den Slave. VESC-Pakete:
;;   SET_CURRENT=1, SET_CURRENT_BRAKE=2; CAN-ID = (Paket<<8)|Controller-ID;
;;   Daten = 4 Byte big-endian, Skalierung 1000 (A*1000).
;; Hinweis: Bei Dual-Hardware auf EINER Platine (ein MCU) alternativ die
;; LispBM-Funktion (select-motor 1/2) statt CAN nutzen.
(defun can-cur (pid amps)
  (let ((v (clamp (round (* amps 1000.0)) 0 2000000)))
    (can-send-sid (+ (* pid 256) CAN_SLAVE_ID)
                  (list (/ v 16777216) (mod (/ v 65536) 256)
                        (mod (/ v 256) 256) (mod v 256)))))

;; ---------------------------------------------------------------------------
;; 6) REGELUNG (Gas/Bremse DIREKT am VESC-ADC; Limits ggf. von der IVCU)
;; ---------------------------------------------------------------------------
(defun thr-in ()
  (clamp (/ (- (get-adc ADC_THR_CH) THR_MIN) (- THR_MAX THR_MIN)) 0 1))
(defun brk-in ()
  (clamp (/ (- (get-adc ADC_BRK_CH) BRK_MIN) (- BRK_MAX BRK_MIN)) 0 1))
(defun gear-lim ()                         ; IVCU-Limit, sonst Defaulttabelle
  (if (and (= lk_valid 1) (> lk_limit 0)) lk_limit (ix GEAR_LIMIT_KMH (- gear 1))))
(defun gear-cur ()
  (if (and (= lk_valid 1) (> lk_cur 0)) lk_cur (ix GEAR_CURRENT_A (- gear 1))))
(defun erpm-limit ()                       ; km/h -> ERPM (Direktantrieb)
  (/ (* (gear-lim) 16666.67 POLE_PAIRS) CIRC_MM))
(defun control-step (dt)
  (let* ((thr (thr-in))
         (brk (brk-in))
         (maxa (* (gear-cur) POWER_LIMIT (if (= eco 1) ECO_FACTOR 1.0)))
         (target (* (pow thr THR_CURVE_EXP) maxa))
         (slew (/ (* maxa dt) (ix GEAR_RAMP_MS (- gear 1)))))
    (setq cur_cmd (+ cur_cmd (clamp (- target cur_cmd) (- 0 slew) slew)))
    (if (> (get-rpm) (erpm-limit)) (setq cur_cmd (* cur_cmd 0.2)) nil)
    (if (or (> t_mot TEMP_MOT_MAX) (> t_fet TEMP_FET_MAX) (> (get-fault) 0))
        (setq cur_cmd 0.0) nil)
    (if (> brk 0.05)
        (set-brake (* brk (ix GEAR_EABS_A (- gear 1))))
        (set-current cur_cmd))
    ;; Dual: zweiten ESC spiegeln (CAN); siehe can-cur-Hinweis oben
    (if (= DUAL 1)
        (if (> brk 0.05)
            (can-cur 2 (* brk (ix GEAR_EABS_A (- gear 1))))
            (can-cur 1 cur_cmd))
        nil)
    (timeout-reset)
    (setq cur_now cur_cmd)))

;; ---------------------------------------------------------------------------
;; 7) TELEMETRIE (Quelle fuer die 0x71-Felder)
;; ---------------------------------------------------------------------------
(defun telemetry-update ()
  (progn
    (setq pack_v (get-vin))
    (setq t_mot (round (get-temp-mot)))
    (setq t_fet (round (get-temp-fet)))
    (setq cur_now (get-current))
    (setq soc (clamp (round (* 100.0 (/ (- pack_v (* 3.0 PACK_S))
                                         (* 1.25 PACK_S)))) 0 100))  ; grob
    (setq speed_kmh (clamp (* (get-speed) 3.6) 0 199))
    (setq odo_m (* (get-dist-abs) 1.0))))

;; ---------------------------------------------------------------------------
;; 8) HAUPTLOOP
;; ---------------------------------------------------------------------------
(defun main ()
  (loopwhile t
    (progn
      (poll-uart)
      (telemetry-update)
      (control-step LOOP_MS)
      ;; 0x71 abwechselnd 3A/3B alle 100 ms (Alive-Grenze 600 ms je Typ)
      (if (= (mod cnt CNT_71) 0)
          (progn
            (setq sub71 (if (= sub71 0) 1 0))
            (esc-send-71 (if (= sub71 0) 0x3A 0x3B)))
          nil)
      ;; Link-Timeout: ohne IVCU-Frames > 2 s -> Defaulttabelle, sicher fahren
      (setq lk_miss (+ lk_miss 1))
      (if (> lk_miss IVCU_TIMEOUT_CNT) (setq lk_valid 0) nil)
      (setq gear (+ (clamp lk_gear 0 4) 1))
      (sleep (/ LOOP_MS 1000.0))
      (setq cnt (+ cnt 1)))))
(main)
