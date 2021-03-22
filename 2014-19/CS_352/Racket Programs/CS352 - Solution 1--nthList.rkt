#lang racket

(define (nthList n l)
  (if (or (> n (length l)) (< n 0))
    (error "Index out of bounds.")
    (if (eq? n 0)
      (car l)
      (nthList (- n 1) (cdr l)))))

(nthList 0 '(a b c d))
(nthList 1 '(a b c d))
(nthList 2 '(a b c d))
