s(L,S) :- p(L, S), is_s(S).

p(L, [H|T]) :- d(H,L,R), p(R,T).
p([], []).

d(X, [X|T], T).
d(X, [H|T], [H|R]) :- d(X,T,R).

is_s([]).
is_s([_]).
is_s([X,Y|T]) :- X =< Y, is_s([Y|T]).