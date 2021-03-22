sum_lists([], [], []).
sum_lists([], [H2|T2], [L|Ls]) :-
  L = H2,
  sum_lists([], T2, Ls).
sum_lists([H1|T1], [], [L|Ls]) :-
  L = H1,
sum_lists(T1, [], Ls).
sum_lists([H1|T1], [H2|T2], [L|Ls]) :-
  L is H1 + H2,
sum_lists(T1, T2, Ls).