(define (Sum a b)
    (+ a b))
(display (Sum 9 8))

(define (abs x)
    (cond ((> x 0) x)
          ((= x 0) 0)
          ((< x 0) (- x))))
(display (abs 1))
(display (abs -1))
(display (abs 0))

(printf "ans is ~a ...\n" 12)
(printf "Hi \n")
