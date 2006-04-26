quantidade=1:16;
po_a=0;
po_s=0;
deltas=0.01:0.01:9;
%quantidade=1:size(deltas,2);
for i=quantidade
   deltinha=10^(-i);
%   deltinha=deltas(i);
   [as,si]=deriva(0.5,deltinha);
   assim(i)=as;
   simet(i)=si;
   analitico(i)=9.9461638;
   if (i>1) 
	   erro_a(i-1)=abs(assim(i)-assim(i-1));
      erro_s(i-1)=abs(simet(i)-simet(i-1));
   end
end
for i=2:(size(quantidade,2)-1)
   if (erro_a(i) > erro_a(i-1)) & (po_a == 0)
      disp(['Ponto otimo do metodo assimetrico encontrado na iteracao ' num2str(i)]);
      po_a=i;
   end
   if (erro_s(i) > erro_s(i-1)) & (po_s == 0)
      disp(['Ponto otimo do metodo simetrico encontrado na iteracao ' num2str(i)]);
      po_s=i;
   end
end  
plot(quantidade,assim,'k-');
hold on
xlabel('Iteracao');
ylabel('Valor da derivada');
plot(quantidade,simet,'r-');
plot(po_a,assim(po_a),'kd');
plot(po_s,simet(po_s),'rd');
plot(quantidade,analitico,'b:');
axis([1 16 8.5 10.5])
legend('Assimetrico','Simetrico','Ponto otimo assimetrico','Ponto otimo simetrico','Solucao Analitica');
