function retorno=backprop(l,x,d,n,f,li,neta)
%Use: backprop(l,x,d,n,f,lim,ne)
%l = Quantidade de camadas
%x = Matriz de entradas
%d = Saidas desejadas
%n = Vetor contendo a quantidade de neuronios nas camadas (exceto ultima)
%f = Vetor de funcoes sendo 1 funcao para cada camada conforme a tabela abaixo:
%0 - Linear; 1 - Sigmoide unipolar; 2 - Sigmoide bipolar; 3 - ArcTangente
%lim - Limite de iteracoes
%ne - Neta
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
        w{1}=rand(n(1),size(x,2));
    else
        w{cont}=rand(n(cont),n(cont-1)+1);
    end
end
while (iteracao<=li)
    lin_ale=randperm(size(x,1));
    x=x(lin_ale,:);
    d=d(lin_ale,:);
    for exemplo=1:size(x,1)
        for forw=1:l
            if(forw == 1)
                estimulo{forw}=w{forw}*x(exemplo,:)';
            else
                
                estimulo{forw}=w{forw}*[1; y];
            end
            y=fativacao(f(forw),estimulo{forw});
            yt{forw}=y;
        end
        e_local_local(exemplo,:)=d(exemplo,:)-y';
        for bckp=l:-1:1
            if (bckp == l)
                erl=e_local_local(exemplo,:);
                dfa=dfativacao(f(bckp),estimulo{bckp});
                dlt{bckp}=erl.*dfa;
            else
                dfa=dfativacao(f(bckp),estimulo{bckp})
                tempw=w{bckp+1};
                soma=dlt{bckp+1}*tempw(:,2:size(tempw,2))
                dlt{bckp}=dfa.*soma;
            end
        end
        for atuw=1:l
            delt=dlt{atuw}'
            x(exemplo,:)
            if (atuw == 1)
                w{atuw}=w{atuw}+neta*delt*x(exemplo,:);
            else
                w{atuw}=w{atuw}+neta*delt*yt{atuw-1};
            end
        end
        %for 1 ate c - calcular os w 
        %erro local
    end
    iteracao=iteracao+1;
    %erro global
end
retorno = yt;