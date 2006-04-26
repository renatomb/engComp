#include <iostream.h>
#include <stdio.h>
#include <string.h>

void main() {
	int n=0, i=0, k=0;
	do {
	cout << "Entre com o total de socios: ";
	cin >> n;
	} while(n>100);
	float b=0;
	float altura[100];
	char nomes[100][40];
	char nome[40];
	for (k=1; k<=n; k++) {
		cout << "Entre com o nome do socio " << k << ": ";
		gets(nomes[k]);
		cout << "Entre com a altura do socio " << k << ": ";
		cin >> altura[k];
	}
	i=1;
	while (i < n) {
		for (k=1; k<=(n-i); k++) {
			if (altura[k+1] > altura[k]) {
				b=altura[k];
				strcpy(nome,nomes[k]);
			}
			altura[k]=altura[k+1];
			strcpy(nomes[k],nomes[k+1]);
			altura[k+1]=b;
			strcpy(nomes[k+1],nome);
		}
		i++;
	}
	for (k=1; k<=n; k++) {
		cout << nomes[k] << " = " << altura[k] << "cm.";
		cout << '\n';
	}
	cout << "\nA pessoa mais alta eh: " << nomes[1] << " e tem " << altura[1] << "cm.";
	cout << "\nA pessoa mais baixa eh: " << nomes[n] << " e tem " << altura[n] << "cm.";
}