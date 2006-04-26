#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

struct data {
	int dia;
	char mes[10];
	int ano;
};

struct venda {
	data diavenda;
	int pecas;
	float preco;
};

void novavenda(void);
void listavenda(void);

venda vendas[50];
venda total={{0," ",0},0,0.0};
int n=0;

void main() {
	const VERDADE=1;
	const char ESC=27;
	char ch;
	while (VERDADE) {
		cout << "\n(I)nserir nova venda";
		cout << "\n(L)istar venda";
		cout << "\nESC para finalizar";
		ch=getch();
		switch(ch)
		{
			case 'I':novavenda();break;
			case 'L':listavenda();break;
			case ESC:break;
			default: cout << "\nOpcao invalida";
		}
	}
}

void novavenda() {
	char temp[80];
	cout << "\nDia: "; gets(temp);
	vendas[n].diavenda.dia=atoi(temp);
	cout << "\nMes: "; gets(vendas[n].diavenda.mes);
	cout << "\nAno: "; gets(temp);
	vendas[n].diavenda.ano=atoi(temp);
	cout << "\nPecas: "; gets(temp);
	vendas[n].pecas=atoi(temp);
	cout << "\nPreco: "; gets(temp);
	vendas[n].preco=atof(temp);
	total.pecas+=vendas[n].pecas;
	total.preco+=vendas[n].preco;
   n++;
}

void listavenda() {
	if (!n) {
		cout << "\nLista vazia";
		return;
	}
	cout << setprecision(2);
	for (int i=0; i<n; i++) {
		cout << '\n' << setw(2) << vendas[i].diavenda.dia;
		cout << "de" << setw(2) << vendas[i].diavenda.mes;
		cout << "de" << setw(2) << vendas[i].diavenda.ano;
		cout << setw(10) << vendas[i].pecas;
		cout << setw(20) << vendas[i].preco;
	}
	cout << "\n\n" << setw(34) << total.pecas;
	cout << '\n' << setw(20) << total.preco;
}

