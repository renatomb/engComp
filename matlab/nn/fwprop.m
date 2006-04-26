function retorno=backprop(l,x,d,n,f,li)
%Use: backprop(l,x,d,n,f,lim)
%l = Quantidade de camadas
%x = Matriz de entradas
%d = Saidas desejadas
%n = Vetor contendo a quantidade de neuronios nas camadas (exceto ultima)
%f = Vetor de funcoes sendo 1 funcao para cada camada conforme a tabela abaixo:
%0 - Linear; 1 - Sigmoide unipolar; 2 - Sigmoide bipolar; 3 - ArcTangente
%lim - Limite de iteracoes
%
%(C) 2003 - RMB
x=[ones(size(x,1),1) x];
if (size(n,2) ~= (l-1))
    disp('Erro: A quantidade de neuronios fornecida nao e compativel com a quantidade de camadas.');
    break;
else
    n(l)=size(d,2);
end
if (size(f,2) ~= l)
    disp('Erro: A quantidade de funcoes fornecida nao e compativel com a quantidade de camadas.');
    break;
end
if (size(d,1) ~= size(x,1))
    disp('Erro: A quantidade de exemplos fornecida e diferente da quantidade de saidas desejadas.');
    break;
end
if ((min(f) < 0) | (max(f) > 3))
    disp('Erro: Foi fornecido um codigo de funcao invalido.');
    break;
end
iteracao=1;
%% Geracao dos W aleatorios.
for cont=1:l
    if (cont == 1)
        w{1}=rand(size(x,2),n(1));
    else
        w{cont}=rand(n(cont-1)+1,n(cont));
    end
end
while (iteracao<li)
    lin_ale=randperm(size(x,1));
    x=x(lin_ale,:);
    d=d(lin_ale,:);
    for exemplo=1:size(x,1)
        %%for 1 ate c - forward
        for forw=1:l
            if(forw == 1)
                y=processa_camada(x(exemplo,:),w{forw},f(forw));
            else
                y=processa_camada([1 y],w{forw},f(forw));
            end
        end
        e_local_local(exemplo,:)=d(exemplo,:)-y;
        for bckp=l:-1:1
            if (bckp == l)
                delta(bckp)=e_local_local(exemplo,:)*dfativacao(v(exemplo))
            end
        end
        %for de c ate 1 - back
        %for 1 ate c - calcular os w 
        %erro local
    end
    iteracao=iteracao+1;
    %erro global
end
retorno = e_local_local;