adjacent(1,2).
adjacent(1,3).
adjacent(1,4).
adjacent(1,5).
adjacent(2,3).
adjacent(2,4).
adjacent(3,4).
adjacent(4,5).

touching(X,Y):-adjacent(X,Y);adjacent(Y,X).

color(1,red,a).
color(2,blue,a).
color(3,green,a).
color(4,yellow,a).
color(5,blue,a).

color(1,blue,b).
color(2,blue,b).
color(3,green,b).
color(4,yellow,b).
color(5,blue,b).

conflict(Coloring):-
    touching(X,Y),
    color(X,Color,Coloring),
    color(Y,Color,Coloring),
    X \= Y.

alt_conflict(R1,R2,Coloring):-
    touching(R1,R2),
    color(R1,Color,Coloring),
    color(R2,Color,Coloring).




