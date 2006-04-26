x=input('Entre com o vetor X: ');
c=size(x,1)+1;
while(c>size(x,1))
    c=input('Informe a quantidade de saidas: ');
end
for i=1:c
    for j=1:size(x,2)
        w=x(i,j);
    end
end
alfa=input('Entre com o o alfa: ');
tal=input('Entre com o tal: ');
continua=1;
while(continua<100)
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
