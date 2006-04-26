clear
nc=input('Entre com o ganho do controlador: ');
dc=[1];
np=[1 1];
dp=[1 8 22 20];
ns=[1];
ds=[1 1];
num_ramo_direto=conv(nc,np);
den_ramo_direto=conv(dc,dp);
G=tf(num_ramo_direto,den_ramo_direto);
H=tf(ns,ds);
MF=feedback(G,H);
step(MF)
va=input('Entre o valor de steady state: ');
mais_5porcento=1.05*va
menos_5porcento=0.95*va
offset=1-va
