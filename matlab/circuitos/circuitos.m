tensoes=0:2:10;
i100=[0 17.5 38.1 58.2 78.3 99.0];
i470=[0 4.17 8.4 12.7 16.9 21.2];
i1k=[0 2.02 4 6 8 10.1];
figure
plot(tensoes,i100,'k');
hold on
plot(tensoes,i470,'b');
plot(tensoes,i1k,'r');
legend('100 Ohms','470 Ohms','1k Ohm');
xlabel('Tensão (V)');
ylabel('Corrente (mA)');
title('Aula 2 - Primeira lei de Ohh, Potencia e Energia');
figure
count=1;
for i=tensoes
p470(count)=i*i470(count);
p1k(count)=i*i1k(count);
count=count+1;
end
plot(i1k,p1k,'r');
hold on
plot(i470,p470);
legend('1k Ohm','470 Ohms');
xlabel('Corrente (mA)');
ylabel('Potência (mW)');
title('Aula 2 - Primeira lei de Ohh, Potencia e Energia');
