function retorno=qvetorial(x,c,alfa,tal,graf)
%Use: qvetorial(x,c,alfa,tal,g)
%x = Vetor X
%c = Quantidade de saidas
%alfa = Fator alfa
%tal = Fator tal
%g = 0 para nao plotar grafico, 1 para plotar grafico.
%
%
%(C) 2003 - RMB
try
    if (graf == 1)
        graf=1;
    else
        graf=0;
    end
catch
    graf=0;
end
if (c>size(x,1))
    disp('Erro, quantidade de saidas maior do que o numero de linhas do vetor X.');
    break;
end
w=x(1:c,1:size(x,2));
continua=1;
if (graf == 1)
    plot(w(:,1),w(:,2),'g+');hold on;
end
while(continua<100)
    if (graf == 1)
        plot(w(:,1),w(:,2),'g+');
    end
    x_aleatorio=0;
    while(x_aleatorio == 0)
        x_aleatorio=round(rand(1)*size(x,1));
    end
    for t=1:c
        dist(t)=sum((x(x_aleatorio,:)-w(t,:)).^2);
    end
    [ans,posicao]=min(dist);
    w(posicao,:)=w(posicao,:)+alfa*(x(x_aleatorio,:)-w(posicao,:));
    alfa=alfa*tal;
    continua=continua+1;
end
retorno=w;
if (graf == 1)
    plot(x(:,1),x(:,2),'x')
    plot(w(:,1),w(:,2),'or')
end