input "entre com o sal rio em R$ " to salario
if salario > 20000
   desc = salario * 0.20
else
   if salario > 10000
      desc = salario * 0.10
   else
      if salario > 2000
         desc = salario * 0.05
      else
         desc = salario * 0.02
      endif
   endif
endif
? "O desconto ‚ de R$ "+alltrim(str(desc))
? "O novo salario ‚ de R$ "+alltrim(str(salario-desc))
