/*
Passabdi estruturas para funcoes por valor e por referencia

Exemplo:
*/

#include <iostream.h>
struct venda
{
	int pecas;
	float preco;
};

void listavenda(venda& C, venda& D);

void main() {
	venda A,B;
	cout << "\nVenda A\n====================\n";
	cout << "Digite o nº de pecas: ";
	cin >> A.pecas;
	cout << "\nDigite o preco: ";
	cin >> A.preco;
	cout << "\n\nVenda B\n===========\n";
	cout << "Digite o nº de pecas: ";
	cin >> B.pecas;
	cout << "\nDigite o preco: ";
	cin >> B.preco;
	listavenda(A,B);
}

void listavenda(venda& C, venda& D) {
	cout << "\n\nVenda total \n========================\n";
	cout << "\nTotal de pecas: " << (C.pecas+D.pecas);
	cout << "\nPreco total: " << (C.preco+D.preco);
}
