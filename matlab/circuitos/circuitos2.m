r=[2 4 6 8 10];
v=[1.82 3.06 3.94 4.59 5.10];
i=[0.907 0.754 0.647 0.565 0.501];
for id=1:5
p(id)=v(id)*i(id);
end
pthc=4.55*0.569;
rthc=7.930;
rtht=7.40328;
etht=9.10;
vtor=2:0.01:10;
for rl=1:size(vtor,2)
pt(rl)=vtor(rl)*((etht/(rtht+vtor(rl)))^2);
end
plot(vtor,pt)
hold on
plot(r,p,'d')
plot(rthc,pthc,'dr')
xlabel('Resistência (ohms)')
ylabel('Potência (mW)')
legend('Curva matemática','Pontos experimentais','Resistência de Thevenin')
diary off
