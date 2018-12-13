function [x,n]=impulso(no,ni,nf)
% Gera a fun�ao impulso x(n)=delta(n-no)
% onde ni<=n<=nf
%---------------------------------------
% [x,n]=impulso(no,ni,nf)
%
n=[ni:nf]; x=[(n-no)==0];