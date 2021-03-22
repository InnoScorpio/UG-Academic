list_sum([],[],[]).
list_sum([H1|T1],[H2|T2],[X|L3]):-list_sum(T1,T2,L3), X is H1+H2.
