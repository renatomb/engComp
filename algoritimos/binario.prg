declare d[20]
input "Entre com a quantidade de digitos " to n
for i=1 to n step 1
   input "Entre com o digito "+alltrim(str(i)) to d[i]
next
exp=0
num=0
count=n-1
soma=0
? "O numero binario digitado foi: "
for i=1 to n step 1
   ?? alltrim(str(d[i]))
   exp=2**count
   num=d[i]*exp
   soma=soma+num
   count=count-1
next
? "O numero decimal correspondente ‚: "
?? soma

