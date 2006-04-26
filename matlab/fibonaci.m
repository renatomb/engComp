alfa=input('Entre com um numero ');
n=[0 1];
for i=2:alfa
   n(i+1)=n(i)+n(i-1);
end
disp(n);