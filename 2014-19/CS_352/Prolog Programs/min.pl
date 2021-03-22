min_numlist([H|T], Min) :- min_numlist(T, H, Min).
min_numlist([], Min, Min). 
min_numlist([H|T], Min0, Min) :- Min1 is min(H, Min0), min_numlist(T, Min1, Min).
