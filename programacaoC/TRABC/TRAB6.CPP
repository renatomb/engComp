#include <iostream.h>

void main {
	float n, dolar, franco, valor;
	char opcao;
	cout << "Entre com o valor do dolar: ";
	cin >> dolar;
	cout << "Entre com o valor do franco: ";
	cin >> franco;
	do {
		cout << "Entre com o valor a ser convertido: "
		cin >> n;
		if (n == -1) break;
		cout << "Entre com a opcao (D ou F): ";
		cin >> opcao;
		if (opcao == 'F' || opcao == 'f') {
			valor=n*franco;
			cout << "O valor de " << n << "Francos " << valor;
		}
		else {
			if (opcao == 'D' || opcao == 'd') {
				valor=n*dolar;
				cout << "O valor de " << n << "Dolares " << valor;
			}
			else cout << "Voce pressionou a tecla errada!";
		}
	} while (n <> -1)
}