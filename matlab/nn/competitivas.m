x=input('Entre com o vetor X: ');
c=size(x,1)+1;
while(c>size(x,1))
    c=input('Informe a quantidade de saidas: ');
end
w=x(1:c,1:size(x,2));
alfa=input('Entre com o o alfa: ');
tal=input('Entre com o tal: ');
continua=1;
%plot(w(:,1),w(:,2),'g+')
%hold on
while(continua<100)
%    plot(w(:,1),w(:,2),'r+')
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
%plot(x(:,1),x(:,2),'x')
%plot(w(:,1),w(:,2),'o')