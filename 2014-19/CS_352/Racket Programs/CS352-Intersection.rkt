#lang racket
(define (intersection l1 l2)
  (remove-duplicates
   (filter (λ (x) (member x l1))  
           l2)))

(define (setIntersection l1 l2)
  (let loop ((l1 l1)
             (l2 l2)
             (ol '()))
    (cond
      [(empty? l1) (reverse ol)]
      [(member (first l1) l2)        
       (loop (rest l1)              
             (remove (first l1) l2) 
             (cons (first l1) ol))] 
      [else
       (loop (rest l1)
             l2
             ol)])))

(setIntersection '(a b c d) '(x b c y))
(setIntersection '(nil) '(1 2 3))
(setIntersection '(1 2) '(a b c d))

