function hd = ideal_lp(wc,N);
a = (N-1)/2;
n = [0:1:N-1];
m = n - a + eps;
hd = sin(wc*m)./(pi*m);