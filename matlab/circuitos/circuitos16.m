%%%%%%%%%%%%%%%% Valores expermentais
amplitude=[2.5 4.8 22 36 40 40 38 34 32 28 23 12 2.4 1.2]*10^-3;
frequencias=[0.5 1 5 10 15 20 25 30 35 40 50 100 500 1000]*10^3;
dois_a=[6 25 22 18 20 20 19 17 32 28 23 24 12 6];
dois_b=[6 24 18 9 2 5 9 10 23 22 19 22 12 6];
defasagem=deg(asin(dois_b./dois_a));
defasagem(1:5)=defasagem(1:5)*(-1);  %% Correção da defasagem para angulos positivos e negativos
c=0.1*10^-6; %% Capacitor usado
l=680*10^-6; %% Indutor usado
r=100; %% Resistor usado

%%%%%%%%%%%%%%%% Valores matemáticos
f=logspace(1,6,1000); %% Vetor F, espacado logaritmicamente de 10^1 até 10^6 com 1000 pontos
xl=2.*pi.*f.*l; %% Calculo da reatancia indutiva
xc=1./(2.*pi.*f.*c); %% Calculo da reatancia capacitiva
im=10./sqrt((r^2)+((xl-xc).^2)); %% Calculo da amplitude
ang=deg(atan((xl-xc)./r)); %% Calculo da defasagem

%%%%%%%%%%%%%%%% Plotagem dos graficos
figure
semilogx(f,im);
axis on
hold on
axis([10 10^6 0 0.1])
xlabel('Frequencia (Hz)');
ylabel('Corrente (A)');
plot(frequencias,amplitude,'r')
legend('Valores matemáticos','Valores experimentais');
figure
semilogx(f,ang);
axis on
hold on
axis([10 10^6 -100 100])
xlabel('Frequencia (Hz)');
ylabel('Defasagem (º)');
plot(frequencias,defasagem,'r')
legend('Valores matemáticos','Valores experimentais');
