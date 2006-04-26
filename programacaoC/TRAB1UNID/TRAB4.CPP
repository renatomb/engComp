/*---------------------------------
UNP - Universidade Potiguar
Curso de Engenharia de Computacao - 1º Ano
Disciplina Programacao Cientifica - 1ª Unidade
Professor: Marcelo Mariano
Aluno: RENATO MONTEIRO BATISTA
Trabalho de C++ - Questão 04
---------------------------------*/
#include <iostream.h>
#include <iomanip.h>

void main() {
	int num=10, sdp=0, sds=0;
	int matriz[8][8];
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			matriz[j][i]=num;
			num=num+5;
		}
	}
	cout << "A matriz:";
	for (i=0; i<8; i++) {
		cout << '\n';
		for (int j=0; j<8; j++) {
			cout << setw(4) << matriz[i][j] << ' ';
			if (i==j) sdp=sdp+matriz[i][j];
			if ((i+j)==7) sds=sds+matriz[i][j];
		}
	}
	cout << "\n\nSoma da diagonal principal: " << sdp;
	cout << "\nSoma da diagonal secundaria: " << sds;
	cout << "\n\nA matriz, apos a multiplicacao dos elementos acima da diag. principal por zero:";
	for (i=0; i<8; i++) {
		cout << '\n';
		for (int j=0; j<8; j++) {
			if (i<j) matriz[i][j]=matriz[i][j]*0;
			cout << setw(4) << matriz[i][j] << ' ';
		}
	}

}
