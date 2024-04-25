adjacent(a,b).
adjacent(a,e).
adjacent(a,d).
adjacent(b,a).
adjacent(b,c).
adjacent(b,e).
adjacent(b,d).
adjacent(c,d).
adjacent(c,b).
adjacent(c,e).
adjacent(d,a).
adjacent(d,b).
adjacent(d,c).
adjacent(d,e).

touching(X,Y):- adjacent(X,Y);adjacent(Y,X).

color(a,red,1).
color(b,blue,1).
color(c,red,1).
color(d,brown,1).
color(e,yellow,1).

color(a,red,2).
color(b,blue,2).
color(c,red,2).
color(d,brown,2).
color(e,red,2).


conflict(Coloring):-
    touching(X,Y),
    color(X,Color,Coloring),
    color(Y,Color,Coloring),
    X \= Y.

alt_conflict(S1,S2,Coloring):-
    touching(S1,S2),
    color(S1,Color,Coloring),
    color(S2,Color,Coloring).
