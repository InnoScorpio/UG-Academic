        p([],[]).
    reverse([],[],[]).
  		p(A,B):-
    reverse(A,[],B).
    reverse([],B,B).

    reverse([H|T],L1,L2):-
        reverse(T,[H|L1],L2).