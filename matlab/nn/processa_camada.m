function saida=processa_camada(v,f)
%Calcula as saidas da rede para um dado conjunto de entrada e pesos.
%Use: processa_camada(v,f)
%v - Estimulo (entrada * pesos)
%f - Funcao de ativacao dos perceptrons
%
%
%(C) 2003 - RMB
for n=1:size(v,2)
    s(n)=fativacao(f,v(n));
end
s
saida=s