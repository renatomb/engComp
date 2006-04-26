n=0
do while !((n>0) .and. (n<10))
   input "Entre com o valor para o qual vocˆ quer a tabuada " to n
enddo
cont=1
do while (cont<=10)
   ? alltrim(str(cont))+" x "+alltrim(str(n))+" = "+alltrim(str(cont*n))
   cont = cont+1
enddo
