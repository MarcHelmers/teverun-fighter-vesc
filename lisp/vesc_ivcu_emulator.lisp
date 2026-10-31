;; ============================================================================
;;  vesc_ivcu_emulator.lisp   v1.1   (Bench-Validierung erforderlich!)
;;  Teverun-IVCU-Ersatz auf VESC (LispBM, FW >= 6.05)
;;  ---------------------------------------------------------------------------
;;  Zweck: Motorregelung + Telemetrie mit den Teverun-Originalkennwerten,
;;         optional Display-Emulation. Display-/App-/LED-Protokolle sind in
;;         AWIVCU_APP_R3_4_13_Kennlinien_und_Datenbereiche.md dokumentiert.
;;
;;  MODI (MODE):
;;    0 = BRIDGE    : VESC-UART <-> "Teverun-IO-Bridge" (ESP32: Display, BLE-
;;                    Modul, LEDs). EMPFOHLEN - vollstaendigstes Verhalten.
;;    1 = STANDALONE: VESC-UART direkt = Stock-Display (9600). Kein App/BLE.
;;
;;  WICHTIG: API-Namen (buf*/uart*/get-*/set-*) je FW-Stand pruefen; alles ist
;;  in Abschnitt 2 gekapselt. Dies ist ein Startpunkt, kein erprobtes Produkt.
;; ============================================================================

;; ---------------------------------------------------------------------------
;; 1) KONFIGURATION
;; ---------------------------------------------------------------------------
(def MODE 0)

(def WHEEL_MM 254.0)                       ; Radumfang-Durchmesser (10"=254)
(def CIRC_MM (* 3.14159265358979 WHEEL_MM))
(def POLE_PAIRS 15)                        ; Polpaare; KALIBRIEREN gegen Display!
(def PACK_S 16)                            ; 13/14/16/20 fuer 48/52/60/72 V

;; Gaenge: Limit km/h | Phasenstrom A | Anlauf ms | EABS A
(def GEAR_LIMIT_KMH (list 15 20 25 35 45))
(def GEAR_CURRENT_A (list 15 20 25 30 55))
(def GEAR_RAMP_MS   (list 900 700 550 400 300))
(def GEAR_EABS_A    (list 8 12 16 22 30))

;; ADC: Kanal 0 = Gas, Kanal 1 = Bremse (COMM-Port)
(def ADC_THR_CH 0) (def ADC_BRK_CH 1)
(def THR_MIN 0.60) (def THR_MAX 3.00)
(def BRK_MIN 0.60) (def BRK_MAX 2.60)
(def THR_DEADBAND 0.04)
(def THR_CURVE_EXP 1.35)                   ; >1 = zahmer unten
(def ECO_FACTOR 0.60)
(def POWER_LIMIT 1.00)
(def TEMP_MOT_MAX 120) (def TEMP_FET_MAX 85)

(def LOOP_MS 20)                           ; Regelzyklus
(def CNT_DISP 5)                           ; alle 5 Zyklen = 100 ms
(def CNT_TEL 10)                           ; alle 10 Zyklen = 200 ms
(def CLAMP_SCALE_BIT 0)                    ; R3: offen; R5/eKFV-Bit hier setzen

;; ---------------------------------------------------------------------------
;; 2) LispBM-KAPSELUNG (Namen je FW pruefen!)
;; ---------------------------------------------------------------------------
(defun buf-new (n)         (bufcreate n))
(defun buf-put (b i v)     (bufset-u8 b i v))
(defun buf-get (b i)       (bufget-u8 b i))
(defun buf-put16be (b i v) (progn (buf-put b i (/ (round v) 256))
                                  (buf-put b (+ i 1) (mod (round v) 256))))
(defun buf-put24be (b i v) (progn (buf-put b i (/ (round v) 65536))
                                  (buf-put b (+ i 1) (mod (/ (round v) 256) 256))
                                  (buf-put b (+ i 2) (mod (round v) 256))))
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

;; SOC-Kennlinie @0x0801DC78 (21 Stuetzstellen)
(def SOC_MV (list 3000 3100 3200 3266 3330 3400 3458 3511 3570 3624 3672
                  3720 3760 3810 3858 3911 3955 3999 4045 4091 4150))
(def SOC_PC (list 0 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 100))
(defun soc-from-mv (mv)
  (if (<= mv (ix SOC_MV 0)) 0
    (if (>= mv (ix SOC_MV 20)) 100
      (let ((i 0))
        (loopwhile (>= mv (ix SOC_MV (+ i 1))) (setq i (+ i 1)))
        (+ (ix SOC_PC i) (/ (* 5 (- mv (ix SOC_MV i)))
                            (- (ix SOC_MV (+ i 1)) (ix SOC_MV i))))))))

;; ---------------------------------------------------------------------------
;; 4) UART / SENDER
;; ---------------------------------------------------------------------------
(def uart-tx (buf-new 64))
(if (= MODE 1) (uart-start 9600) (uart-start 115200))

;; Bridge-Rahmen: 'T'(0x54) cmd p0..p4 XOR  (8 Byte)
(defun bridge-send (cmd p0 p1 p2 p3 p4)
  (progn (buf-put uart-tx 0 0x54) (buf-put uart-tx 1 cmd)
         (buf-put uart-tx 2 p0) (buf-put uart-tx 3 p1) (buf-put uart-tx 4 p2)
         (buf-put uart-tx 5 p3) (buf-put uart-tx 6 p4)
         (buf-put uart-tx 7 (xor-buf uart-tx 7))
         (uart-write uart-tx)))

;; Display 0x35 (39 B, XOR ueber 0..37) - VERIFIZIERTES Layout
;;   [12]=Spiegelflags, [13]=Speed, [14]=SOC, [15]/[16]=0x35E/0x35F,
;;   Rotationskandidaten [17..18]/[20..21]/[22..23]/[24..25], [19]=0x2F2&0x5F,
;;   [26..28]=Odometer/10, [29]=Status, [30]=Wheel, [31]=Pack, [32]=Polpaare
(def disp (buf-new 48))
(def WHEEL_CODE 100)                              ; 10.0" (muss zu WHEEL_MM passen)
(defun rot-time ()                                ; 0,1-ms-Einheiten (speedRaw)
  ;; Community-verifiziert (App: speedRaw = 55 72 t[15..16]; >=3000 => Anzeige 0)
  (if (< speed_kmh 1.0) 0xFFFF
    (clamp (round (/ (* WHEEL_CODE 287.0) speed_kmh)) 1 0xFFFF)))
(defun display-send-35 (subtype)
  (progn
    (buf-put disp 0 0x35) (buf-put disp 1 0x27) (buf-put disp 2 subtype)
    (buf-put disp 3 0) (buf-put disp 4 CLAMP_SCALE_BIT)
    (buf-put16be disp 5 0) (buf-put disp 7 0) (buf-put disp 10 0)
    (buf-put disp 11 gear)
    (buf-put disp 12 0)                                  ; Spiegelflags
    (buf-put disp 13 (clamp (round speed_kmh) 0 255))    ; Speed-Feld
    (buf-put disp 14 (clamp (round soc) 0 100))          ; SOC
    (buf-put disp 15 0) (buf-put disp 16 0)              ; 0x35E / 0x35F
    (let ((rot (rot-time)))
      (progn
        (buf-put16be disp 8 rot)                         ; [8..9]=Rotationszeit (FW-verifiziert!)
        (buf-put disp 19 0)))                            ; [19]=0x2F2&0x5F
    (buf-put24be disp 26 (/ odo_m 100.0))                ; Odometer 3B BE
    (buf-put disp 29 0x09)                               ; Statusbyte
    (buf-put disp 30 WHEEL_CODE)
    (buf-put disp 31 (clamp (round pack_v) 0 255))
    (buf-put disp 32 POLE_PAIRS)
    (buf-put disp 33 (clamp (/ (- t_mot 80) 5) 0 255))
    (buf-put disp 34 (ix GEAR_RAMP_MS (- gear 1)))
    (buf-put disp 35 (ix GEAR_LIMIT_KMH (- gear 1)))
    (buf-put disp 36 (round (* 100 POWER_LIMIT)))
    (buf-put disp 37 (clamp (round cur_now) 0 255))      ; Rear-Strom
    (buf-put disp 38 (xor-buf disp 38))
    (uart-write disp)))

(def ka (buf-new 10))
(defun keepalive-send () (progn (looprange i 0 10 (buf-put ka i i)) (uart-write ka)))

;; ---------------------------------------------------------------------------
;; 5) EMPFANG
;; ---------------------------------------------------------------------------
(def rx (buf-new 32))
(defun read-rest (n start)                  ; (n-1) weitere Bytes nach rx[start]
  (let ((got 1))
    (loopwhile (< got n)
      (setq got (+ got (uart-read rx (- n got) (+ start got -1) nil nil 0.05))))
    got))
(defun rd-bridge ()
  (if (= 8 (read-rest 8 1))
    (let ((c (buf-get rx 1)))
      (progn
        (if (= c 0x02) (setq gear (clamp (buf-get rx 2) 1 5)) nil)
        (if (= c 0x03) (setq eco (clamp (buf-get rx 2) 0 1)) nil)))))
(defun rd-display-4c ()
  (if (= 19 (read-rest 19 1))
    (if (= 0x35 (buf-get rx 2))
      (let ((cmd (buf-get rx 3)))
        (progn
          (if (= cmd 1) (setq gear (clamp (buf-get rx 4) 1 5)) nil)
          (if (= cmd 3) (setq eco (if (bit? (buf-get rx 6) 0) 1 0)) nil))))))
(defun poll-uart ()
  (if (> (uart-read rx 1 nil nil 0) 0)
    (let ((b0 (buf-get rx 0)))
      (if (= b0 0x54) (rd-bridge)
        (if (= b0 0x4C) (rd-display-4c)
          (if (= b0 0x8A) (read-rest 11 1)
            (if (= b0 0x8B) (read-rest 8 1)
              (if (= b0 0x8C) (read-rest 8 1) nil))))))))

;; ---------------------------------------------------------------------------
;; 6) REGELUNG (Original-Kennwerte)
;; ---------------------------------------------------------------------------
(defun thr-in ()
  (clamp (/ (- (get-adc ADC_THR_CH) THR_MIN) (- THR_MAX THR_MIN)) 0 1))
(defun brk-in ()
  (clamp (/ (- (get-adc ADC_BRK_CH) BRK_MIN) (- BRK_MAX BRK_MIN)) 0 1))
(defun gear-val (lst) (ix lst (- gear 1)))
(defun erpm-limit ()                        ; km/h -> ERPM (Direktantrieb)
  (/ (* (gear-val GEAR_LIMIT_KMH) 16666.67 POLE_PAIRS) CIRC_MM))
(defun control-step (dt)
  (let* ((thr (thr-in))
         (brk (brk-in))
         (maxa (* (gear-val GEAR_CURRENT_A) POWER_LIMIT
                  (if (= eco 1) ECO_FACTOR 1.0)))
         (target (* (pow thr THR_CURVE_EXP) maxa))
         (slew (/ (* maxa dt) (gear-val GEAR_RAMP_MS))))
    ;; Slew-Limiter (Anlaufverhalten)
    (setq cur_cmd (+ cur_cmd (clamp (- target cur_cmd) (- 0 slew) slew)))
    ;; Drehzahl-Clamp (wie Original): ueber Limit -> Strom sanft zuruecknehmen
    (if (> (get-rpm) (erpm-limit)) (setq cur_cmd (* cur_cmd 0.2)) nil)
    ;; Temperatur-/Fault-Schutz (VESC-Config zusaetzlich aktiv lassen!)
    (if (or (> t_mot TEMP_MOT_MAX) (> t_fet TEMP_FET_MAX) (> (get-fault) 0))
        (setq cur_cmd 0.0) nil)
    (if (> brk 0.05)
        (set-brake (* brk (gear-val GEAR_EABS_A)))
        (set-current cur_cmd))
    (timeout-reset)                          ; Motor-Timeout halten
    (setq cur_now cur_cmd)))

;; ---------------------------------------------------------------------------
;; 7) TELEMETRIE
;; ---------------------------------------------------------------------------
(defun telemetry-update ()
  (progn
    (setq pack_v (get-vin))
    (setq t_mot (round (get-temp-mot)))
    (setq t_fet (round (get-temp-fet)))
    (setq cur_now (get-current))
    (setq soc (clamp (round (soc-from-mv (/ (* pack_v 1000.0) PACK_S))) 0 100))
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
      (if (= (mod cnt CNT_DISP) 0)
          (if (= MODE 0)
              (bridge-send 0x01 (clamp (round speed_kmh) 0 255) soc
                           (clamp (round pack_v) 0 255) gear eco)
              (display-send-35 0x3A)) nil)
      ;; Telemetrie-Extras (Bridge-Protokoll v2, Cmd 0x05):
      ;;   p0=t_mot p1=t_fet p2=Strom p3/p4=Odometer km (HI/LO)
      (if (= (mod cnt CNT_TEL) 0)
          (bridge-send 0x05 (clamp t_mot 0 255) (clamp t_fet 0 255)
                       (clamp (round cur_now) 0 255)
                       (mod (round (/ odo_m 1000.0)) 256)
                       (mod (round (/ odo_m 256000.0)) 256)) nil)
      (if (= (mod cnt CNT_DISP) 0) (keepalive-send) nil)
      (if (= (mod cnt 50) 0) (bridge-send 0x04 0 0 0 0 0) nil)   ; Heartbeat 1 s
      (sleep (/ LOOP_MS 1000.0))
      (setq cnt (+ cnt 1)))))
(main)
