clear all
clc
x=input('Entre com o vetor de x[inicial final]: ');
p=input('Entre com o numero de partes: ');
y=input(['Entre com o valor y(' num2str(x(1)) ')= ']);
h=(x(2)-x(1))/p;
for k=1:p
   x(k+1)=x(1)+h*(k);
   %%%%%%%%%%%%%%%%%%%%
   s1=h*f_rk(x(k),y(k));
   s2=h*f_rk(x(k)+0.5*h,y(k)+0.5*s1);
   s3=h*f_rk(x(k)+0.5*h,y(k)+0.5*s2);
   s4=h*f_rk(x(k)+h,y(k)+s3);
   y(k+1)=y(k)+(1/6)*(s1+2*s2+2*s3+s4);
end
disp(sprintf('Solucao y(%f)=%f',x(k+1),y(k+1)));
