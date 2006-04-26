%% UNP - Universidade Potiguar
%% Disciplina: Laboratório de Matemática para Engenharia
%% Professor: Allan Medeiros
%% -----------------------------------------------------
%% Trabalho de Matlab - 2ª. Unidade
%% Algorítimo desenvolvido por:
%% - RENATO MONTEIRO BATISTA
%% - WEBER CUNHA LIMA


vetor=input('Entre com o vetor: ');
vetor=sort(vetor);
cont=0;
c=vetor(1);
for i=1:size(vetor,2)
   if(c == vetor(i))
      cont=cont+1;
   else
      disp([num2str(cont) ' numeros ' num2str(vetor(i-1))]);
      c=vetor(i);
      cont=1;
   end
end
disp([num2str(cont) ' numeros ' num2str(vetor(i))]);
