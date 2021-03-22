sq([X], [Y]):-
  Y is X ^ 2.
sq([X|Xs], [Y|Ys]):-
  Y is X ^ 2,
  sq(Xs, Ys).
  sq([], []).
sq([X|Xs], [Y|Ys]):-
  Y is X ^ 2,
  sq(Xs, Ys).