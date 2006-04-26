t=-4*pi:0.1:4*pi;
am=10/5;
V=1*5;
am=am*10;V=V*10;
figure
plot(V*sin(t));
hold on
grid on
plot(am*sin(t),'r');
legend('Tensao (V / 5)','Corrente (mA x 5)');
title('Grafico do resistor');
figure
plot(V*sin(t+rad(90)));
hold on
grid on
plot(am*sin(t),'r');
legend('Tensao (V / 5)','Corrente (mA x 5)');
title('Grafico do indutor');
figure
plot(V*sin(t));
hold on
grid on
plot(am*sin(t+rad(90)),'r');
legend('Tensao (V / 5)','Corrente (mA x 5)');
title('Grafico do capacitor');
