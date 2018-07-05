#lang racket

(define (cc amount n)
  (cond ((= n 0) 0)
        ((= amount 0) 1)
        ((< amount 0) 0)
        (else (+ (cc amount (- n 1))
                 (cc (- amount (first-denomination n)) n)))))

(define (first-denomination n)
  (cond ((= n 1) 1)
        ((= n 2) 5)
        ((= n 3) 10)
        ((= n 4) 25)
        ((= n 5) 50)))

(define (count-change amount) (cc amount 5))
