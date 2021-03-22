#lang racket
(define (make-graph graph)
(cond [(empty? graph)] 
[(cons? graph) ((first (first graph))
(second (first graph)) 
(make-graph (rest graph)))])) 

(define (neighbors a-node a-graph)
(cond [(empty? a-graph) (error "Node not in graph")] 
[(symbol=? a-node (first (first a-graph))) (second (first a-graph))] 
[else (neighbors a-node (rest a-graph))])) 

(define (find-route origination destination graph)
(cond [(symbol=? origination destination) (list origination)]
      [else (local [(define nbrs (neighbors origination graph)) 
(define route (find-route/list nbrs destination graph))] 
(cond [(false? route) route] 
[else (cons origination route)]))]))  

(define (find-route/list los destination graph)
(cond [(empty? los) false] 
[else (local [(define route (find-route (first los) destination graph))]  
(cond [(false? route) (find-route/list (rest los) destination graph)] 
[else route]))])) 

