#lang racket

(define (fact-iter acc n)
  (if (<= n 1)
      acc
      (fact-iter (* acc n) (- n 1))))

(define (fact n)
  (fact-iter 1 n))

