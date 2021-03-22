symmetricDifference([], X, X).

symmetricDifference([H|T1],Set,Z):-
 member(H, Set),       
 !, delete(T1, H, T2), 
 delete(Set, H, Set2), 
 symmetricDifference(T2, Set2, Z).

symmetricDifference([H|T], Set, [H|Set2]) :-
 symmetricDifference(T,Set,Set2).