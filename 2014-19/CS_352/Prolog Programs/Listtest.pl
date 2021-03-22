intersectionTR(_, [], []).
intersectionTR([], _, []).
intersectionTR([H1|T1], L2, [H1|L]):-
    member(H1, L2),
    intersectionTR(T1, L2, L), !.
intersectionTR([_|T1], L2, L):-
    intersectionTR(T1, L2, L).

intersection(L1, L2):-
    intersectionTR(L1, L2, L),
    write(L).


unionTR([], [], []).
unionTR([], [H2|T2], [H2|L]):-
    intersectionTR(T2, L, Res),
    Res = [],
    unionTR([], T2, L),
    !.
unionTR([], [_|T2], L):-
    unionTR([], T2, L),
    !.

unionTR([H1|T1], L2, L):-
    intersectionTR([H1], L, Res),
    Res \= [],
    unionTR(T1, L2, L).
unionTR([H1|T1], L2, [H1|L]):-
    unionTR(T1, L2, L).

union(L1, L2):-
    unionTR(L1, L2, L),
    write(L).