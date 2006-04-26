r=[2 4 6 8 10];
v=[]; %%Insira aqui os valores das tensões medidas
i=[]; %%Insira aqui os valores das correntes medidas (em mA)
for id=1:5
p(id)=v(id)*i(id);
end
rtht=7.4033; %%RTH matemático;
etht=9.10; %%ETH matemático;
vtor=2:0.01:10;
for rl=1:size(vtor,2)
pt(rl)=vtor(rl)*((etht/(rtht+vtor(rl)))^2);
end
plot(vtor,pt)
hold on
plot(r,p,'d')
xlabel('Resistência (ohms)')
ylabel('Potência (mW)')
legend('Pontos teóricos','Pontos experimentais')
