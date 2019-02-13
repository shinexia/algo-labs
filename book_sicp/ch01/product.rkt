#lang racket

(define (product-iter acc a b)
  (if (= b 0)
      acc
      (product-iter (+ acc a) a (- b 1))))

(define (fast-product-iter acc a b)
  (cond ((= b 0) acc)
        ((even? b) (fast-product-iter acc (* 2 a) (/ b 2)))
        (else (fast-product-iter (+ acc a) a (- b 1)))))

(define (product a b)
  (fast-product-iter 0 a b))
