declare c[20,20]
input "Entre com o numero de linhas " to n
input "Entre com o numero de colunas " to m
for i=1 to n step 1
   for j=1 to m step 1
      input "Informe o elemento da posicao "+alltrim(str(i))+"x"+alltrim(str(j))+" " to c[i,j]
   next
next
pi=1
pj=1
maior=c[1,1]
for i=1 to n step 1
   for j=1 to m step 1
      if (c[i,j] > maior)
         maior = c[i,j]
         pi=i
         pj=j
       endif
   next
next
? "Maior elemento: "
?? maior
? "Sua posicao na matriz: "
?? pi
?? "x"
?? pj

