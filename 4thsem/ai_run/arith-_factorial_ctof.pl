sum(X,Y):-C is X+Y,write(C).
divide(X,Y):-C is X/Y,write(C).
mul(X,Y):-C is X*Y,write(C).
intdiv(X,Y):-C is X//Y,write(C).
diff(X,Y):-C is X-Y,write(C).
pow(X,Y):-C is X^Y,write(C).
positive(X):- X>=0.
negative(X):- X<0.
equal(X,Y):- X =:= Y.
notequal(X,Y):- X =\= Y.

factorial(0,1).
factorial(I,O):-
    I>0,
    S is I - 1,
    factorial(S,O2),
    O is I *O2.

modulous(X,Y):-C is X mod Y,write(C).
c_to_f(C,F):- F is C * 9/5 + 32.
freezing(F):- F<33.
