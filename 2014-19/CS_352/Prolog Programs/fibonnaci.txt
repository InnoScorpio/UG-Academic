f(0,0).
f(1,1).
f(X,Y) :-
X > 1,
X2 is X-2, f(X2,Y2),
X1 is X-1, f(X1,Y1),
Y is Y1+Y2.