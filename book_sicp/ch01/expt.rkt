#lang racket

(define (expt-rec x n)
  (if (= n 0)
      1
      (* x (expt-rec x (- n 1)))))

(define (expt-iter acc x n)
  (if (= n 0)
      acc
      (expt-iter (* acc x) x (- n 1))))

(define (expt x n)
  (expt-iter 1 x n))
