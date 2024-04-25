male(bikash).
male(roman).
male(mani).
male(james).
female(ramila).
female(shila).
female(anu).
female(shweta).

parent_of(bikash,anu).
parent_of(bikash,shweta).
parent_of(ramila,anu).
parent_of(ramila,shweta).
parent_of(roman,james).
parent_of(shila,james).
parent_of(anu,simon).
parent_of(mani,simon).
parent_of(shweta,shekhar).
parent_of(james,shekhar).

husband_of(X,Y):- parent_of(X,Z),parent_of(Y,Z),male(X),X\=Y.
wife_of(X,Y):- parent_of(X,Z),parent_of(Y,Z),female(X),X\=Y.
father_of(X,Y):- male(X),parent_of(X,Y).
mother_of(X,Y):- female(X),parent_of(X,Y).
grandfather_of(X,Y):- male(X),parent_of(X,Z),parent_of(Z,Y).
grandmother_of(X,Y):- female(X),parent_of(X,Z),parent_of(Z,Y).
sister_of(X,Y):-female(X),father_of(F, Y), father_of(F,X),X \= Y.
sister_of(X,Y):- female(X),mother_of(M, Y), mother_of(M,X),X \= Y.
aunt_of(X,Y):- parent_of(Z,Y), sister_of(Z,X).
aunt_of(X,Y):-parent_of(Z,Y),brother_of(Z,A),wife_of(X,A).
brother_of(X,Y):-male(X),father_of(F, Y), father_of(F,X),X \= Y.
brother_of(X,Y):- male(X),mother_of(M, Y), mother_of(M,X),X \= Y.
uncle_of(X,Y):-parent_of(Z,Y),brother_of(Z,X).
uncle_of(X,Y):-parent_of(Z,Y),sister_of(Z,A),husband_of(X,A).
ancestor_of(X,Y):- parent_of(X,Y).
ancestor_of(X,Y):- parent_of(X,Z),ancestor_of(Z,Y).

















