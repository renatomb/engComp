// LENDO OBJETOS

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
		void print();
};

void livro::print() {
	cout << "\nTitulo: " << titulo;
	cout << "\nAutor: " << autor;
	cout << "\nNo Reg: " << numreg;
	cout << "\nPreco: " << preco;
}

void main() {
	ifstream fin("c:\lista.dat");
	livro li;
	while (fin.read((char*)&li,sizeof(livro)))
		li.print();
}
