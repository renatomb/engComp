declare s[12],di[12]
s[1]="Aquario"
s[2]="Peixes"
s[3]="�ries"
s[4]="Touro"
s[5]="G�meos"
s[6]="C�ncer"
s[7]="Le�o"
s[8]="Virgem"
s[9]="Libra"
s[10]="Escorpi�o"
s[11]="Sargit�rio"
s[12]="Capric�rnio"
di[1]=21
di[2]=20
di[3]=21
di[4]=21
di[5]=21
di[6]=21
di[7]=22
di[8]=23
di[9]=23
di[10]=23
di[11]=22
di[12]=22
input "Entre com o dia do seu nascimento " to dn
input "Entre com o m�s do seu nascimento " to mn
*for i=1 to 12 step 1
   if dn >= di[mn]
      ? "Seu signo � "+s[mn]
   else
      if mn > 1
         ? "Seu signo � "+s[mn-1]
      else
         ? "Seu signo � "+s[12]
      endif
   endif
*next
