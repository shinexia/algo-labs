#lang racket

(define (tree-sum exp)
  (match exp
    [(? number? x) x]
    [`(,a, b ...) (+ (tree-sum a) (tree-sum b))]
    [_ 0]))

(define (calc exp)
  (match exp
    [(? number? x) x]
    [`(,op, a, b)
     ((match op
        ['+ +]
        ['- -]
        ['* *]
        ['/ /]) (calc a) (calc b))]
    [_ 0]))
