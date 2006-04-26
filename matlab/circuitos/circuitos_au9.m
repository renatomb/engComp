vce=[2 4 6 8 9.8];
te=[5.61 11.71 20.47 36.00 95.54];
e=10;
for id=1:5
tal_e(id)=-te(id)/(log(1-(vce(id)/e)));
end
disp(['Constante de tempo do circuito = ' num2str(sum(tal_e)/5)]);
r=10000;
c=2200*10^-6;
tal=r*c;
t=1:150;
for id=1:150
vc(id)=e*(1-exp(-t(id)/tal));
end
figure;hold on;xlabel('t(s)');ylabel('Vc(V)');axis([0 150 0 10]);title('Fase de carga')
plot(t,vc);
plot(te,vce,'rd');
legend('Curva teórica','Pontos experimentais');
ie=[0.75 0.5 0.25 0.125 0.05]*-10^-3;
tempo_e=[6.04 14.83 30.07 45.51 65.28];
for id=1:150
corrente(id)=(-e/r)*exp(-t(id)/tal);
end
figure;hold on;xlabel('t(s)');ylabel('I(mA)');axis([0 150 -10^-3 0]);title('Fase de descarga')
plot(t,corrente)
plot(tempo_e,ie,'rd')
legend('Curva teórica','Pontos experimentais')
clear all
