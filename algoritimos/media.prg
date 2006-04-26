input "entre com a primeira nota " to n1
input "entre com a segunda nota " to n2
mf = (n1+n2)/2
if mf < 4
   ? "Aluno reprovado por m‚dia, m‚dia final= "+alltrim(str(mf))
else
   if mf >= 7
      ? "Aluno aprovado por m‚dia, m‚dia final= "+alltrim(str(mf))
   else
      input "Entre com a nota da recupera‡Æo " to rec
      mf = (rec+mf)/2
      if (mf >=6)
         ? "Aluno aprovado na recupera‡Æo, m‚dia final= "+alltrim(str(mf))
      else
         ? "Aluno reprovado na recupera‡Æo, m‚dia final= "+alltrim(str(mf))
      endif
   endif
endif
