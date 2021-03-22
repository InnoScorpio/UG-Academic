#lang racket
(define (sumListPairs lst1 lst2)
  (let loop ((l1 lst1) (l2 lst2))
    (cond ((and (null? l1) (null? l2)) null)
          ((null? l1))
          ((null? l2))
          (else (cons (+ (car lst1) (car lst2))
                      (loop (cdr l1) (cdr l2)))))))