function r=trig(s,a,b,c,x)
r=0; %%Linha acrescentada para as situacoes nao previstas nos ifs.
if s==0
   if x>=a & x<=b
      r=(x-a)/(b-a);
   else
      if x>b
         r=1;
      end
   end
end
if s==1
   if x>=a & x<=b
      r=(b-x)/(b-a);
   else
      if x<a
         r=1;
      end
   end
end
if s==2
   if x>=a & x<=c
      r=(x-a)/(c-a);
   else
      if x>c & x<=b
         r=(b-x)/(b-c);
      end
   end
end
