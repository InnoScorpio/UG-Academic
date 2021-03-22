equation(X,Y,Z):- var(X),X is Z-Y.
equation(X,Y,Z):- var(Y),Y is Z-X.
equation(X,Y,Z):- var(Z),Z is X+Y.