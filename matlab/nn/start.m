disp('UNP - Universidade Potiguar');
disp('Multilayer neural network solve');
disp('© 2003 - Renato Monteiro Batista');
disp('rmb@unp.br / (84) 9451-0685');
disp('-------------------------------------');
saudacao=clock;
saudacao=saudacao(4);
if (saudacao < 12) 
   saudacao = 'Bom dia';
elseif (saudacao < 18)
   saudacao = 'Boa tarde';
elseif (saudacao > 18)
   saudacao = 'Boa noite';
end
disp([saudacao ' usuario, bem vindo ao MNNS.']);
clear
l=input('Por favor informe o número de camadas da rede: ');
for i=1:l
   perc(i)=-1;
   while(perc(i) < 1)
      perc(i)=input(['Por favor informe o número de perceptrons para a ' num2str(i) 'ª camada da rede: ']);
   end
end   
clear i;
disp('Funcoes de ativacao disponiveis:');
disp('1 - Funcao sigmoide');
disp('2 - Funcao degrau unitario');
disp('3 - Funcao linear');
for i=1:l
   fatv(i)=-1;
   while(fatv(i) < 1 | fatv(i) > 3)
      fatv(i)=input(['Por favor informe a função de ativação para a ' num2str(i) 'ª camada da rede: ']);
   end
end   
disp('Preparando psicologicamente para treinamento da rede...');
x=[];
d=[];
while (size(x,2) ~= perc(1))
   x=input('Por favor entre com O VETOR contendo as entradas da rede: ');
end
while (size(d,2) ~= perc(l))
   d=input('Por favor entre com A MATRIZ de valores desejados para as saidas, para o conjunto de entradas fornecido: ');
end
