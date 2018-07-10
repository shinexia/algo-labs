#lang racket

(require "sqrt.rkt")

(define (sqrt-iter-cond guess x)
  (cond ((good-enough? guess x) guess)
        (else (sqrt-iter-cond (improve guess x) x))))

(sqrt-iter-cond 1.0 9)
