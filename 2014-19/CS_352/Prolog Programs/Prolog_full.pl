% The first argument is the instructor.
class1(Stokjovic,Michael).
class1(Stokjovic,Daniel).
class1(Tannouri,Mathhew).
class2(Sakk,William).
class2(Sakk,Bruce).
class2(Willoughby,Samuel).
class3(Small,Bill).
class3(Small,Vernon).
class3(Small,George).
class(x, y) :- class1(x,y).
class(x, y) :- class2(x,y).
class(x, y) :- class3(x,y).
salute :-
	write('salutations,') ,tab(2), write('master').
greet1(hamish):-
write('How are you doing, pal?').
greet2(amelia):-
write('How awfully nice to see you!').
greet3(mike):-
write('Hi there').
salute1 :-
	write('Hi'), tab(2), write('pal!').
salute2 :-
	write('Hi'), tab(2), write('pal!').
greet4(Name):-
	write('Hello, '), write(Name).
greet5(hamish):-
	write('How are you doing, pal?').
greet6(amelia):-
	write('How awfully nice to see you!').
greet7(mike):-
write('Hi there').
greet8(Name):-
write('Hello, '), write(Name).
bigger1(N, M):-
N < M, write('Bigger number is '),tab(1), write(M).
bigger2(N, M) :-
M < N, write('Bigger number is '), tab(1), write(N).
bigger3(N, M) :-
write('Numbers are the same').
bigger4(N, M):-
write('Trying clause 1'), nl,
N < M, write('Bigger number is '),tab(1), write(M).
bigger5(N, M) :-
write('Trying clause 2'), nl,
M < N, write('Bigger number is '), tab(1), write(N).
bigger6(N, M) :-
write('Numbers are the same'), nl.
larger1(N, M, M):-
N < M.
larger2(N, M, N) :-
M < N.
larger3(N, M, M).
man(paul).
man(david).
man(peter).
woman(louise).
woman(helen).
woman(mandy).
wifeof(paul, louise).
wifeof(peter, helen).
sonof(paul, peter).
daughterof(peter, mandy).
parentof(Person1, Person2):-
daughterof(Person1, Person2).
parentof(Person1, Person2):-
sonof(Person1, Person2).
grandparent(OldPerson, YoungerPerson):-
parentof(OldPerson, Another), parentof(Another, YoungerPerson).
person('Dave the Dude', '58 Broadway', 36).
valuable(gold).
female(jane).
owns(jane, gold).
father(john, mary).
gives(john,book, mary).
address(23, 140, 2122).
address(flat(23), streetnumber(140), postcode(2122)).
may_steal(P,T) :- thief(P), likes(P,T).
thief(john).
likes(mary,chocolate).
likes(mary,wine).
likes(john,X):- likes(X, wine).
may_steal(X,Y):-thief(X),likes(X,Y).
father(X,Y).
mother(X,Y).
male(X).
female(X).
parent(X,Y).
diff(X,Y).
aunt(X,Y) :- female(X), sibling(X,Z), parent(Z,Y).
wrote(roger, sam).
wrote(gottlob, begriffsschrift).
wrote(bertrand, principia).
wrote(alfred, principia).
book(begriffsschrift).
book(principia).
program(lunar).
program(sam).
program(shrdlu).
author(Person) :-
book(Book),
wrote(Person, Book).
professor(terry).
professor(roger).
professor(bertrand).
professor(gottlob).
concerns(shrdlu, blocks).
concerns(lunar, rocks).
concerns(sam, stories).
concerns(principia, logic).
concerns(principia, mathematics).
concerns(begriffsschrift, logic).
author_of(Person, Book) :-
book(Book),
wrote(Person, Book).
parent(katherine, bertrand). parent(amberley, bertrand).
parent(katherine, frank). parent(amberley, frank).
parent(katherine, rachel). parent(amberley, rachel).
parent(dora, kate). parent(bertrand, kate).
parent(dora, john). parent(bertrand, john).
parent(peter, conrad). parent(bertrand, conrad).
parentof(Person1, Person2):-
daughterof(Person1, Person2).
parentof(Person1, Person2):-
sonof(Person1, Person2).
female(katherine). male(amberley).
female(rachel). male(frank).
female(dora). male(bertrand).
female(peter). male(conrad).
female(kate). male(john).
ancestor(Old, Young) :-
parent(Old, Young).
ancestor(Old, Young) :-
parent(Old, Middle),
parent(Middle, Young).
ancestor(Old, Young) :-
parent(Old, Middle),
parent(Middle, Middle2),
parent(Middle2, Young).
ancestor(Old,Young) :-
parent(Old,Young).
ancestor(Old,Young) :-
	parent(Old,Middle),
ancestor(Middle,Young).
s(P0, P) :- np(P0, P1), vp(P1, P).
np(P0, P) :- det(P0, P1), n(P1, P2), optrel(P2, P).
np(P0, P) :- pn(P0, P).
vp(P0, P) :- tv(P0, P1), np(P1, P).
vp(P0, P) :- iv(P0, P).
optrel(P, P).
optrel(P0, P) :- connects(that, P0, P1), vp(P1, P).
pn(P0, P) :- connects(terry, P0, P).
pn(P0, P) :- connects(shrdlu, P0, P).
iv(P0, P) :- connects(halts, P0, P).
det(P0, P) :- connects(a, P0, P).
n(P0, P) :- connects(program, P0, P).
tv(P0, P) :- connects(writes, P0, P).
connects(a, 0, 1).
connects(program, 1, 2).
connects(halts, 2, 3).
par(lloyd, james).
par(lloyd, janet).
par(ruth, james).
par(ruth, janet).
par(emma, lloyd).
par(katherine, ruth).
par(adolph, lloyd).
par(edgar, ruth).
p(a, b, X).
capital_of(salem, oregon).
q(b).
p(X) :- q(X), r(X), s(X).
parentOf(X, Y) :- motherOf(X, Y).
parentOf(X, Y) :- fatherOf(X, Y).
wrote(roger, sam).
wrote(gottlob, begriffsschrift).
wrote(bertrand, principia).
wrote(alfred, principia).
book(begriffsschrift).
book(principia).
program(lunar).
program(sam).
program(shrdlu).
sentence(N,X,Z) :- noun_phrase(N,X,Y), verb_phrase(N,Y,Z).