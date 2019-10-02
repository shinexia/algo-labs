#lang racket

(define (fast-expt-rec b n)
  (cond ((= n 0) 1)
        ((even? n) (square (fast-expt-rec b (/ n 2))))
        (else (* b (fast-expt-rec b (- n 1))))))

(define (square x)
  (* x x))

(define (fast-expt-iter acc b n)
  (cond ((= n 0) acc)
        ((even? n) (fast-expt-iter acc (square b) (/ n 2)))
        (else (fast-expt-iter (* acc b) b (- n 1)))))

(define (fast-expt b n)
  (fast-expt-iter 1 b n))
