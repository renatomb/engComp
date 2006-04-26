input "entre com x " to x
input "entre com y " to y
if ((x=0) .and. (y=0))
   ? "O ponto est  na origem"
else
   if ((x=0) .or. (y=0))
      if (x=0)
         ? "O ponto est  no eixo y"
      else
         ? "O ponto est  no eixo x"
      endif
   else
      if (x>0)
         if (y>0)
            ? "O ponto est  no 1§ quadrante"
         else
            ? "O ponto est  no 4§ quadrante"
         endif
      else
         if (y>0)
            ? "O ponto est  no 2§ quadrante"
         else
            ? "O ponto est  no 3§ quadrante"
         endif
      endif
   endif
endif
