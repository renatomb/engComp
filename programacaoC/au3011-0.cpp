// GRAVANDO OBJETOS

#include <fstream.h>
#include <stdio.h>
#include <conio.h>

class livro {
	private:
		char titulo[50];
		char autor[50];
		int numreg;
		double preco;
	public:
		void novonome();
};

void livro::novonome() {
	cout << "\nDigite o titulo: ";
	gets(titulo);
	cout << "\nDigite o autor: ";
	gets(autor);
	cout << "\nDigite o numero do registro: ";
	cin >> numreg;
	cout << "\nDigite o preco: ";
	cin >> preco;
}

void main() {
	ofstream fout("c:\lista.dat");
	livro li;
	do {
		li.novonome();
		fout.write((char*)&li,sizeof(livro));
		cout << "\nMais um livro (s/n)?";
	} while (getche()!='n');
}

