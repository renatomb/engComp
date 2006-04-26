function [xp,xi,m]=parimpar(x,n)
% Decomposiçao de um sinal real em suas componetes par e impar
%---------------------------------------
% [xp,xi,m]=parimpar(x,n)
%
if any(imag(x)~=0)
    error('x nao e uma sequencia real')
end
m=-fliplr(n);
m1=min([m,n]); m2=max([m,n]); m=m1:m2;
nm=n(1)-m(1); n1=1:length(n);
x1=zeros(1,length(m));
x1(n1+nm)=x; x=x1;
xp=0.5*(x+fliplr(x1));
xi=0.5*(x-fliplr(x1));