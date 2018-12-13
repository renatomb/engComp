function [y,ny]=conv_m(x,nx,h,nh)
% Rotina de convolu�ao modificada para processamento de sinais
%---------------------------------------
% [y,ny] = conv_m(x,nx,h,nh)
% [y,ny] = resultado da convolu�ao
% [x,nx] = primeiro sinal
% [h,nh] = segundo sinal
%
nyb = nx(1) + nh(1); nye = nx(length(x)) + nh(length(h));
ny = [nyb:nye];
y = conv(x,h);
