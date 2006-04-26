declare a[30],b[30],c[60]
for i=1 to 30 step 1
   input "Entre com o elemento "+alltrim(str(i))+" do vetor A" to a[i]
next
for i=1 to 30 step 1
   input "Entre com o elemento "+alltrim(str(i))+" do vetor B" to b[i]
next
for i=1 to 60 step 1
   if mod(i,2) == 1
      ele = (i+1)/2
      c[i]=a[ele]
   else
      ele = i/2
      c[i]=b[ele]
   endif
   ? "C["+alltrim(str(i))+"]="+alltrim(str(c[i]))
next
