declare m[13,3]
for i=1 to 13 step 1
   for j=1 to 3 step 1
      accept "Marque X para jogar na coluna "+alltrim(str(j))+" do palpite "+alltrim(str(i)) to m[i,j]
   next
next
duplos=0
triplos=0
for i=1 to 13 step 1
   jogo=0
   for j=1 to 3 step 1
      if m[i,j] == "X"
         jogo=jogo+1
      endif
   next
   if jogo == 2
      duplos=duplos+1
   else
      if jogo == 3
         triplos=triplos+1
      endif
   endif
next
? "Duplos: "
?? duplos
? "Triplos: "
?? triplos
