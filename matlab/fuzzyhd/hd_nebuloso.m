function teta=hd_nebuloso(teta_ref)
teta=0; erro_anterior=0;
faixa_u=[-12,-6.0,0.0,6.0,12.0];
R=[
[4,4,4,4,3];
[4,4,4,3,3];
[4,4,3,2,2];
[3,3,2,1,1];
[2,2,1,0,0]];
contador=4;
laco=1;
while (laco)
   y=[0,0,0]; u=[0,0,0];
   produto=0; soma=0;
	[teta,y]=planta(contador,y,u); %%Linha adaptada pois a funcao planta nao reconhece a variavel y e u;
	erro=-(teta_ref-teta);
   if(contador<=4)
      derro=0;
   else
      derro=erro-erro_anterior;
   end
	mie(1)=trig(1,-50.0,-1.0,0.0,erro)
	mie(2)=trig(2,-50.0,0.0,-1.0,erro)
	mie(3)=trig(2,-1.0,1.4,0.0,erro)
	mie(4)=trig(2,0.0,50.0,1.4,erro)
	mie(5)=trig(0,1.4,50.0,0.0,erro)
   
   mide(1)=trig(1,-1.8,-1.0,0.0,derro)
	mide(2)=trig(2,-1.8,0.0,-1.0,derro)
	mide(3)=trig(2,-1.0,1.0,0.0,derro)
	mide(4)=trig(2,0.0,1.8,1.0,derro)
	mide(5)=trig(0,1.0,1.8,0.0,derro)
	for j=1:5
      for i=1:5
         if mie(i)<mide(j)
            mir(j,i)=mie(i)
         else
            mir(j,i)=mide(j)
         end
      end
   end
	for j=1:5
      for i=1:5
         produto=produto+mir(i,j)*faixa_u(R(i,j))
         soma=soma+mir(i,j);
      end
   end
	u(contador)=produto/soma;
	erro_anterior=erro;
   contador=contador+1;
   if (contador>100)
      loop=0;
   end
end