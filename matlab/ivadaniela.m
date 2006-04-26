A=input('Entre com a matriz: ')
[m n]=size(A);
if (m ~= n)
   disp('Essa sua matriz nao possui inversa. UNA! :P');
elseif det(A) == 0
   disp('Essa sua matriz nao possui inversa. UNA! :P');
else
	X=eye(m);
   for i=1:m %% Percorre as linhas
	   if A(i,i) ~= 1 %% Este bloco é para igualar o elemento da diagonal a 1.
   	   aux=0;
      	for j=1:n %% Este for é para percorrer as colulas dividindo pelo elemento da diagonal da linha.
         	if aux==0
	            aux=A(i,i);
		      end
	   	   A(i,j)=A(i,j)/aux;
	   	   X(i,j)=X(i,j)/aux;
	      end
	   end
	   for k=1:m  %Este bloco ira percorrer as linhas que nao forem a 'linha pivotal'
	      if k == i
	         k=k+1;
	      end
	      if k > m
   	      break
      	end
	      aux2=A(k,i);
   	   for j=1:n
   		 	  A(k,j)=A(k,j)-aux2*A(i,j);
   		 	  X(k,j)=X(k,j)-aux2*X(i,j);
      	end
      end
   end
disp('A matriz inversa eh: ');
disp(X);
end