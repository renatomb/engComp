a=input('Entre com a matriz: ');
cont=0;
for i=1:size(a,1)
   for j=1:size(a,2)
      if a(i,j) > 0
         cont=cont+1;
      end
   end
end
disp([num2str(cont) ' elementos sao positivos']);