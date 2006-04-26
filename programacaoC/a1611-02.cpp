#include <stdio.h>
#include <iostream.h>

void main(){
	char *p1,*p2;
	p1=p2="Engenharia de Computação";
	while(*p2) putchar(*p2++);
	putchar('\n');
	while (--p2>=p1) putchar(*p2);
	putchar('\n');
}