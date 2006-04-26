function [y,n]=mult(x1,n1,x2,n2)
% Implementa y(n)=x1(n)*x2(n)
%---------------------------------------
% [y,n]=mult(x1,n1,x2,n2)
% y(n) e o produto sobre n, que inclui n1 e n2
% x1 e a primeira seqeuncia sobre n1
% x2 e a primeira seqeuncia sobre n2 (podendo n1 ser diferente de n2)
%
n=min(min(n1),min(n2)):max(max(n1),max(n2)); % duraçao de y(n)
y1=zeros(1,length(n)); y2=y1; 
y1(find((n>=min(n1))&(n<=max(n1))==1))=x1; % deixando x1 com a duraçao de y(n)
y2(find((n>=min(n2))&(n<=max(n2))==1))=x2; % deixando x2 com a duraçao de y(n) 
y=y1.*y2;                                   % soma  
