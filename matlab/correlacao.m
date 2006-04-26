function correlacao(s,y)

T1=size(y,2);
T2=size(s,2);
aux=[];
padrao=zeros(1,T1+200);    
padrao(101:(T2+100))=s;    
mpad=mean(s);
mat=mean(y);
corre=0;
f2 = y - mat;
for ii=1:200
    f1=padrao(ii:ii+T1-1)-mpad;
    aux=sum((f1).*(f2))/sqrt((sum((f1).^2)*sum((f2).^2)));
    if corre < aux
        corre=aux;
    end
end
c=num2str(corre);
disp(' O valor da correlacao e: ')
c