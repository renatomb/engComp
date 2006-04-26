declare v[200]
input "Entre com o numero de elementos " to n
for i=1 to n step 1
    input "Entre com o elemento dao posi‡Æo "+alltrim(str(i)) to v[i]
next
? "Numeros pares das posicoes pares:"
for i=2 to n step 2
   if mod(v[i],2) == 0
      ? v[i]
   endif
next
