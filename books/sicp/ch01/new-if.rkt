#lang racket
(require "sqrt.rkt")

(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
        (else else-clause)))

(new-if (= 2 3) 0 5)

(new-if (= 1 1) 0 5)

(define (sqrt-iter2 guess x)

  (new-if (good-enough? guess x)

          guess

          (sqrt-iter2 (improve guess x) x)))

