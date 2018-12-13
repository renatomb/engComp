r=[2 4 6 8 10];
v=[]; %%Insira aqui os valores das tens�es medidas
i=[]; %%Insira aqui os valores das correntes medidas (em mA)
for id=1:5
p(id)=v(id)*i(id);
end
rtht=7.4033; %%RTH matem�tico;
etht=9.10; %%ETH matem�tico;
vtor=2:0.01:10;
for rl=1:size(vtor,2)
pt(rl)=vtor(rl)*((etht/(rtht+vtor(rl)))^2);
end
plot(vtor,pt)
hold on
plot(r,p,'d')
xlabel('Resist�ncia (ohms)')
ylabel('Pot�ncia (mW)')
legend('Pontos te�ricos','Pontos experimentais')
