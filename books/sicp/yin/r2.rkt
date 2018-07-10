#lang racket

(define env0 '())

(define (ext-env x v env)
  (cons `(, x . ,v) env))

(define (lookup x env)
  (let ((p (assq x env)))
    (cond ((not p) #f)
          (else (cdr p)))))

