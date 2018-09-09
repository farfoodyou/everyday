prologues:=3;
outputformat:="svg";
outputtemplate:="%j-%c.%o";
beginfig(0)
    draw (200,200)--(0,0)--(0,30)--(30,0)--(0,0);
    draw (200,100)--(100,100);
    draw (200,100)..(150,150)..(200,200)..(250,150)..(200,100);
endfig;
beginfig(2);
u=1cm;
draw (2u,2u)--(0,0)--(0,3u)--(3u,0)--(0,0);
pickup pencircle scaled 4pt;
for i=0 upto 2:
for j=0 upto 2: drawdot (i*u,j*u); endfor
endfor
endfig;
end
