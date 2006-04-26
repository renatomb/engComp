/*---------------------------------
UNP - Universidade Potiguar
Curso de Engenharia de Computacao - 1º Ano
Disciplina Programacao Cientifica - 1ª Unidade
Professor: Marcelo Mariano
Aluno: RENATO MONTEIRO BATISTA
Trabalho de C++ - Questão 06
---------------------------------*/
#include <iostream.h>

void main() {
	float n, dolar, franco, valor;
	char opcao;
	cout << "Entre com o valor do dolar: ";
	cin >> dolar;
	cout << "Entre com o valor do franco: ";
	cin >> franco;
	do {
		cout << "Entre com o valor a ser convertido: ";
		cin >> n;
		if (n == -1) break;
		cout << "Entre com a opcao (D ou F): ";
		cin >> opcao;
		if (opcao == 'F' || opcao == 'f') {
			valor=n*franco;
			cout << "O valor de " << n << " Francos eh R$ " << valor << '\n';
		}
		else {
			if (opcao == 'D' || opcao == 'd') {
				valor=n*dolar;
				cout << "O valor de " << n << " Dolares eh R$ " << valor << '\n';
			}
			else cout << "Voce pressionou a tecla errada!";
		}
	} while (n != -1);
}