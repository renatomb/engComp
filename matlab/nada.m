figure
x=0:0.01:14;
for i=1:size(x,2)
   if x(i)<=7
      y(i)=(x(i).*(20/7))+10;
   elseif x(i)<=9
      y(i)=0;
   elseif x(i)<=11
      y(i)=35;
   elseif x(i)<=12
      y(i)=20;
   elseif x(i)<14
      y(i)=10;
   else
      y(i)=0;
   end
end
plot(x,y);
axis([0 25 0 50])
