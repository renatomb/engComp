x_plot=0:0.1:100;
cont=1;
for x=x_plot
   if x<=30
      y_plot(cont)=x_plot(cont)/10;
   elseif (x > 30 & x<=80)
      y_plot(cont)=3;
   elseif (x > 80 & x<=100)
      y_plot(cont)=2;
   end
   cont=cont+1;
end
plot(x_plot,y_plot)
axis([0 100 0 10])