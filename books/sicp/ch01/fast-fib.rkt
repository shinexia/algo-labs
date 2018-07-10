#lang racket

(define (square x)
  (* x x))

(define (next-a a b p q)
  (+ (* b q) (* a q) (* a p)))

(define (next-b a b p q)
  (+ (* b p) (* a q)))

(define (next-p p q)
  (+ (square p) (square q)))

(define (next-q p q)
  (+ (square q) (* 2 p q)))

(define (fast-fib-iter a b p q n)
  (cond ((= n 0) b)
      ((even? n) (fast-fib-iter a b (next-p p q) (next-q p q) (/ n 2)))
      (else (fast-fib-iter (next-a a b p q) (next-b a b p q) p q (- n 1)))))

(define (fast-fib n)
  (fast-fib-iter 1 0 0 1 n))




                                     