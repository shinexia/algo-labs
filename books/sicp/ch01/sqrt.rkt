#lang racket

(provide sqrt)

(define (sequare x)
  (* x x))

(define (improve guess y)
    (/ (+ guess (/ y guess)) 2))

;; guess^2 - y = guess^2 - (guess + dx)^2 = - (2 * guess *dx + dx^2)
;; => dx ~= (guess^2 -y) / (2 * guess)
(define (loss guess y fn)
  (define v (abs (/ (- (fn guess) y) (* 2 guess))))
  (display guess)
  (display " ")
  (display v)
  (display "\n")
  v)

(define (good-enough? guess y)
    (< (loss guess y sequare) 0.001))

(define (sqrt-iter guess y)
    (if (good-enough? guess y)
        guess
        (sqrt-iter (improve guess y) y)))

(define (sqrt x)
  (sqrt-iter 1.0 x))
