function [y,n]=reflexao(x,n)
% Implementa y(n)=x(-n)
%---------------------------------------
% [y,n]=reflexao(x,n)
%
y=fliplr(x); n=-fliplr(n);