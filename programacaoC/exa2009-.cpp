#include <iostream.h>

void reajusta (float& p, float& r);
void main() {
	float preco, valor;
	do {
		cout << "\nPreco atual: ";
		cin >> preco;
		reajusta(preco,valor);
		cout << "\nPreco novo: " << preco;
		cout << "\nAumento: " << valor;
	} while (preco != 0.0);
}

void reajusta(float& p, float& r){
	r=p*0.2;
	p=p*1.2;
}
