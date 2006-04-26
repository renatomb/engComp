%Programa para aplicacao do teste de jury
%e verificar a estabilidade de uma planta.
%
%Modo de utilizacao: jury([a0 a1 ... an])
%
%Onde a0, a1, e an sao os coeficientes da
%equacao.

function resp=jury(a)

if (a(1) < 0)
   a=a*(-1);
end   
resp=[];
fcorrecao=0;
syms eps;
for n=size(a,2):-1:1
   resp=[resp a(1)];
   if (a(1) < 0)
      disp('Sistema INSTAVEL.');
      break;
   else
      if (a(1) == 0)
         fcorrecao=1;
%         disp('Ativado fator de correcao');
         a(1)=eps;
      end
   end
   for k=1:(n-1)
      b(k)=a(k)-(a(n)/a(1))*a(n-(k-1));
      if ((k == 1) & (fcorrecao == 1))
         b(1)=b(1)-eps;
      end
   end
   clear a;
   a=b;
end
if (sum(resp >= 0) == size(resp,2))
   if (fcorrecao == 0)
      disp('Sistema Estavel');
   else
      disp('Sistema CRITICAMENTE estavel');
   end
end

        