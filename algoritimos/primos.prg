declare primo[304]
input "Entre com um n£mero entre 4 e 2000" to n
primo[1]=1
pv=1
for i=2 to n step 1
   cont=0
   for j=1 to i step 1
      r = mod(i,j)
      if r = 0
         cont=cont+1
      endif
   next
   if cont == 2
      pv=pv+1
      primo[pv]=i
   endif
next
for i=4 to n step 2
   p1=0
   p2=0
   for j=1 to pv step 1
      for k=1 to j step 1
         if (primo[j]+primo[k] == i)
            p1=primo[j]
            p2=primo[k]
         endif
      next
      if p2>0
         ? alltrim(str(i))+"="+alltrim(str(p1))+"+"+alltrim(str(p2))
         j=pv
      endif
   next
next
