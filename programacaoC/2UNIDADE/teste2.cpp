#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <fstream.h>
#define x 5

struct dados {
	int codigo;
	int ano;
//	char autor[20];
	char titulo[20];
//	char editora[15];
};


void main() {
	ofstream fout("lista.dat");
	dados vetor[x];
	for (int i=0;i<x;i++) {
		cout << "\nCodigo: "; cin >> vetor[i].codigo;
//		cout << "Autor: "; gets(vetor[i].autor);
		cout << "Titulo: "; gets(vetor[i].titulo);
		cout << "Ano: "; cin >> vetor[i].ano;
//      cout << "Editora: "; gets(vetor[i].editora);
		fout.write((char*)&vetor[i],sizeof(dados));
	}
}
