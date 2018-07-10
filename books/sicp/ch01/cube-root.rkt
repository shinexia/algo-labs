#lang racket

(define (improve guess y)
  (/ (+ (/ y (square guess)) (* 2 guess)) 3))

(define (square x)
  (* x x))

;; (guess + dx)^3 -guess^3 ~= 3*guess^2*dx
;; => dx = (guess^3 - y) / (3 * guess * guess)
(define (loss guess y)
  (define v (/ (abs (- (cube guess) y)) (* 3 guess guess)))
  (display guess)
  (display " ")
  (display v)
  (display "\n")
  v)

(define (cube x)
  (* x x x))

(define (good-enough? guess y)
  (< (loss guess y) 0.001))

(define (cube-root-iter guess y)
  (if (good-enough? guess y)
      guess
      (cube-root-iter (improve guess y) y)))

(define (cube-root x)
  (cube-root-iter 1.0 x))
