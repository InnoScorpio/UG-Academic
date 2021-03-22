symDifftest([], X, X).

symDifftest([H|T1],Y,Z):-
 member(H, Y),       % NOTE: arguments swapped!
 !, delete(T1, H, T2), % avoid duplicates in first list
 delete(Y, H, W), % remove duplicates in second list
 symDifftest(T2, W, Z).

symDifftest([H|T], Y, [H|W]) :-
 symDifftest(T,Y,W).