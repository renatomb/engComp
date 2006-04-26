#include <stdio.h>
#include <iostream.h>

int tamanho(char s[]);
void main(){
	char s[]="Universidade Potiguar";
	char *ps=&s[21];
	while (--ps>=s) putchar(*ps);
	putchar('\n');
	cout << "O tamanho da string e = " << tamanho(s);
}

int tamanho(char s[]){
	int n;
	for (n=0; *s; s++) n++;
	return n;
}