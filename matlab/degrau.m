function [x,n]=degrau(no,ni,nf)
% Gera a funçao degrau x(n)=u(n-no)
% onde ni<=n<=nf
%---------------------------------------
% [x,n]=degrau(no,ni,nf)
%
n=[ni:nf]; x=[(n-no)>=0];