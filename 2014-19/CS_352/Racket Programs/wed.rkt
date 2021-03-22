#lang racket
(define (len l)
  (if (eq? l null) 0 (+ 1 (len (cdr l)))))

(define (memb x l)
  (if (eq? l null) #f
      (if (eq? x (car l)) #t (memb x (cdr l)))))

(define (app x y)
  (if (eq? x null) y (cons (car x) (app (cdr x) y))))
