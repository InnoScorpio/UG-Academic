solve(Left=Right) :-
   free_in(Left=Right,X),
   !,
   define_dif(X,Left=Right),
   solve_for(X).

free_in(X,X) :-
    var(X).

free_in(Term,X) :-
    Term \== [[]],
    Term =.. [_,Arg|Args],
    (free_in(Arg,X) ; free_in(Args,X)).




define_dif(X,Left=Right) :-
   abolish(dif,2),
   assert((dif(X,Dif) :- Dif is Left-Right)).


solve_for(Variable) :-
   dif(1,Dif1),
   solve_aux(Variable,1,Dif1,2,1).


solve_aux(_,_,_,_,100) :-
   !,
   write('[Gave up at 100th iteration]'),nl,
   fail.

solve_aux(Guess2,Guess1,_,Guess2,_) :-
   close_enough(Guess1,Guess2),
   !,
   write('[Found a satisfactory solution]'),nl.

solve_aux(Variable,Guess1,Dif1,Guess2,Iteration) :-
   write([Guess2]),nl,
   dif(Guess2,Dif2),
   Slope is (Dif2-Dif1) / (Guess2-Guess1),
   write(slope(Slope)),nl,
   adjust(Slope,NewSlope),
   Guess3 is Guess2 - (Dif2/NewSlope),
   NewIteration is Iteration + 1,
   solve_aux(Variable,Guess2,Dif2,Guess3,NewIteration).


adjust(Slope,10) :- Slope > 1E6, !.

adjust(Slope,-10) :- Slope < -1E6, !.

adjust(Slope,0.1) :- 0 < Slope, Slope < 0.0001.

adjust(Slope,-0.1) :- 0 > Slope, Slope > -0.0001.

adjust(Slope,Slope).

close_enough(X,Y) :-  Quot is X/Y, Quot > 0.999999, Quot < 1.000001.