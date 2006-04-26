vetor=input('Entre com o vetor: ');
maior=max(vetor);
cont=zeros(2,maior);
for i=1:maior
   cont(1,i)=i;
end
for i=1:size(vetor,2)
   numero=vetor(i);
   cont(2,numero)=cont(2,vetor(i))+1;
end
for i=1:size(cont,2)
   if(cont(2,i) > 0)
         disp([num2str(cont(2,i)) ' numeros ' num2str(cont(1,i))])
   end
end

      