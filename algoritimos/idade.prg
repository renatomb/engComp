set decimals to 0
input "Entre com o dia do nascimento " to dn
input "Entre com o mes de nascimento " to mn
input "Entre com o ano de nascimento " to an
input "Entre com o dia do atual " to da
input "Entre com o mes de atual " to ma
input "Entre com o ano de atual " to aa
is=0
if (aa>an)
   if (ma == mn)
      if (da >= dn)
         ia=aa-an
         aux=(da-dn)/7
         is=(ia*52)+aux
      else
         ia=aa-an-1
         aux=(365-(dn-da))/7
         is=(ia*52)+aux
      endif
   else
      if (ma > mn)
         ia=aa-an
         if (da == dn)
           aux=(ma-mn)*4
         else
           if (da > dn)
              aux=((ma-mn-1)*4)+((da-dn)/7)
           else
              aux=((ma-mn-1)*4)+(((da-dn)+30)/7)
           endif
         endif
         is=(ia*52)+aux
      else
         ia=aa-an-1
         if (da == dn)
           aux=((ma-mn)+12)*4
         else
           if (da > dn)
              aux=(((ma-mn)+12)*4)+((da-dn)/7)
           else
              aux=(((ma-mn)+12)*4)+(((da-dn)+30)/7)
           endif
         endif
         is=(ia*52)+aux
      endif
   endif
   ? "A pessoa tem "+alltrim(str(ia))+" anos de vida."
   ? "A pessoa tem "+alltrim(str(is))+" semanas de vida."
else
   if (aa < an)
      ? "A data atual nÆo pode ser menor que a data de nascimento"
   else
      if (ma == mn)
         if (da < dn)
            ? "A data atual nÆo pode ser menor que a data de nascimento"
         else
            if (da == dn)
               ? "A pessoa nasceu hoje."
            else
               aux=(da-dn)/7
               if (aux < 1)
                  aux=da-dn
                  ? "A pessoa tem apenas "+alltrim(str(aux))+" dias de vida."
               else
                  ? "A pessoa tem apenas "+alltrim(str(aux))+" semanas de vida."
               endif
            endif
         endif
      else
         if (ma < mn)
            ? "A data atual nÆo pode ser menor que a data de nascimento"
         else
            if (da == dn)
              aux=(ma-mn)*4
            else
              if (da > dn)
                 aux=((ma-mn)*4)+((da-dn)/7)
              else
                 aux=((ma-mn)*4)+(((da-dn)+30)/7)
              endif
            endif
            ? "A pessoa tem apenas "+alltrim(str(aux))+" semanas de vida."
         endif
      endif
   endif
endif
