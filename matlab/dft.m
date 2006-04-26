function [Xk]=dft(xn,N)
% Rotina para computar a transformada discreta de Fourier
%---------------------------------------
% [Xk] = dft(xn,N)
% Xk = coeficientes da DFS sobre 0 <= k <= N-1
% xn = sequencia finita de N-pontos
% N = Comprimento da sequencia

n = [0:N-1];
k = n;
WN = exp(-j*2*pi/N);
nk = n'*k;
WNnk = WN .^ nk;
Xk = xn*WNnk;
