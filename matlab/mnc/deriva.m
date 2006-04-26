function [assime,simet]=deriva(x,delta_x)

assime=(f(x+delta_x)-f(x))/delta_x;
simet=(f(x+delta_x)-f(x-delta_x))/(2*delta_x);