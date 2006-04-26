#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

long hora();

void main() {
	int n,i,troca,aux,a[22200];
	long tempo1,tempo2;
//	char ch;
	randomize();
//	while(1){
	clrscr();
	printf("N=");
	scanf(&n);
	for(i=0;i<n;i++){
		a[i]=random(5000);
	}
	tempo1=hora();
	do{
		troca=0;
		for(i=0;i<n-1;i++){
			if(a[i]>a[i+1]){
				aux=a[i];
				a[i]=a[i+1];
				a[i+1]=aux;
				troca=1;
			}
		}
	}while(troca==1);
	tempo2=hora();
	for(i=0;i<n;i++){
		printf("%7d",a[i]);
	}
	printf("\nTempo gasto: %l",(tempo2-tempo1));
}


long hora(){
	long h,m,s,hs;
	struct time t;
	gettime(&t);
	h=t.ti_hour;
	m=t.ti_min;
	s=t.ti_sec;
	hs=t.ti_hund;
	return (h*3600+m*60+s)*100+hs;
}