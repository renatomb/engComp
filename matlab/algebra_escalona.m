%UnP - Universidade Potiguar
%Curso de Engenharia de Computacao - 1º Ano
%Disciplina de Álgebra Linear - Prof. Barney
%-------------------------------------------
%Algoritimo para escalonamento de matrizes.
%Desenvolvido por:
%- EDCARLOS MARINHO S. DE ALMEIDA
%- IVA FERNANDES DA SILVA MEDEIROS
%- RENATO MONTEIRO BATISTA
%- ROGÉRIO GLAIDSON MOURA GAMA
%-------------------------------------------

clear all
%m=input('Entre com o numero de linhas: ')
%n=input('Entre com o numero de colunas: ')
A=input('Entre com a matrix: ');
[m,n]=size(A);
%for i=1:m
%   for j=1:n
%      A(i,j)=input(['Entre com os elementos da posicao ',num2str(i),',',num2str(j),': ']);
%   end
%end

for i=1:m
   if A(i,i) ~= 1
      aux=0;
      for j=1:n
         if aux==0
            aux=A(i,i);
	      end
	      A(i,j)=A(i,j)/aux;
      end
   end
   for k=1:m
      if k == i
         k=k+1;
      end
      if k > m
         break
      end
      aux2=A(k,i);
      for j=1:n
   	 	  A(k,j)=A(k,j)-aux2*A(i,j);
	   end
   end
end
