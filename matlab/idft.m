function [xn] = idft(Xk,N)
% Rotina para computar a transformada discreta de Fourier inversa
%---------------------------------------
% [xn n] = idft(Xk,N)
% Xk = coeficientes da DFS sobre 0 <= k <= N-1
% N  = Comprimento da sequencia
% xn = sequencia finita de N-pontos
% n  = vetor de tempo

n = [0:N-1];
k = n;
WN = exp(-j*2*pi/N);
nk = n'*k;
WNnk = WN .^(-nk);
xn = (Xk*WNnk)/N;
