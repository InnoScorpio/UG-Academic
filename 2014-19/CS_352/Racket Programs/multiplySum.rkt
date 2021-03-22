#lang racket
(define (multiply-list a b)
  (if (empty? a)
      empty
      (cons (* (car a) (car b))
            (multiply-list (cdr a) (cdr b)))))
