#include <iostream.h>

int fatorial(int n);

void main(){
	float s=0;
	for (int j=1; j<=5; j++) s=s+(j/float(fatorial(j)));
	cout << "\nO valor de S eh: " << s;
}

int fatorial(int n){
	int fat=1;
	for (int i=1; i<=n; i++) fat=fat*i;
	return fat;
}
