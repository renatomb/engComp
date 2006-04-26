#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calcdv(int num,int dv){
	do {
		dv+=10;
	}while(num>dv);
	return (dv-num);
}

void main() {
	int vetor[12];
	for (int i=0;i<=12;i++) { vetor[i]=-1; }
	int pos=0,soma_imp=0,soma_par=0,resultado=0;
	do {
		clrscr();
		cout << "Verificador de Codigo de Barras - Versao 1.0\n(C) 2002 - Renato Monteiro Batista (rmb@rmb.eng.br)\n\n";
		cout << "Informe o codigo de barras: ";
		for (int i=11; i>=0; i=i-1) {
			if (vetor[i] < 0) { break; }
			else { cout << vetor[i]; }
		}
		char tecla,valid[10];
		strcpy(valid,"0123456789");
		do {
			tecla=getch();
		} while (!strchr(valid,tecla) && (tecla != 8));
		if ((tecla == 8) && (pos >0)) {
			pos--;
			vetor[11-pos]=-1;
		}
		else {
			vetor[11-pos]=tecla-48;
         cout << tecla-48;
			pos++;
		}
	} while (pos <12);
	for (i=0; i<12; i++) {
		if (i%2 == 0) {
			soma_par=soma_par+vetor[i];
		}
		else {
			soma_imp=soma_imp+vetor[i];
		}
	}
//	cout << "\nPasso 1: " << soma_imp;
//	cout << "\nPasso 2: " << soma_par;
	soma_par*=3;
//	cout << "\nPasso 3: " << soma_par;
	resultado=soma_imp+soma_par;
//	cout << "\nResultado: " << resultado;
	cout << "\nDigito verificador: " << calcdv(resultado,10);
}


