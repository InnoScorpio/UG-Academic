len([], 0).
len([_|T], N) :- len(T, N1), N is N1+1.

sum([], 0).
sum([H|T], S) :- sum(T, S1), S is S1 + H.

append([], List, List).
append([Head|[]], List, [Head|List]).
append([Head|Tail], List, Concat) :- append(Tail, List, C), append([Head], C, Concat).

reverse([],[]). 
reverse([H|T],R) :- reverse(T,RevT), append(RevT,[H],R).

last([E], E).
last(L, E) :- reverse(L, [E|Tail]). 

