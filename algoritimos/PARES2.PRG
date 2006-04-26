input "Entre com n= " to n
input "Entre com m= " to m
if (mod(n,2) = 0)
   cont=n
else
   if (n>m)
      cont=n-1
   else
      cont=n+1
   endif
endif
if (n>m)
   aux=-2
else
   aux=2
endif
do while (((cont >= m) .and. (aux < 0)) .or. ((cont <= m) .and. (aux > 0)))
   ? cont
   cont = cont + aux
enddo
