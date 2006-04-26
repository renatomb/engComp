function erro = emq(sinal,sinalfilt);

M = size(sinal,1);

for ii=1:M
    erro(ii)=abs(sinal(ii)-sinalfilt(ii))^2;
end

erro=(1/M)*sum(erro);