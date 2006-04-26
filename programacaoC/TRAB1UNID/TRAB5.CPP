/*---------------------------------
UNP - Universidade Potiguar
Curso de Engenharia de Computacao - 1º Ano
Disciplina Programacao Cientifica - 1ª Unidade
Professor: Marcelo Mariano
Aluno: RENATO MONTEIRO BATISTA
Trabalho de C++ - Questão 05
---------------------------------*/
#include <iostream.h>

void main() {
	float banco[30][5];
	for (int i=0; i<30; i++) {
		cout << "Informe o numero da conta: ";
		cin >> banco[i][0];
		cout << "Informe o saldo anterior: ";
		cin >> banco[i][1];
		{
		char oper;
		cout << "Informe a operacao D = Debito, C = Credito: ";
		cin >> oper;
		cout << "Informe o valor da operacao: ";
		cin >> banco[i][2];
		if (oper == 'C' || oper == 'c') banco[i][3]=banco[i][1]+banco[i][2];
		else {
			if (oper == 'D' || oper == 'd') banco[i][3]=banco[i][1]-banco[i][2];
		}
		}
		if (banco[i][3] <0) banco[i][4]=-1;
		else banco[i][4]=0;
	}
	cout << "\nCorrentistas com saldo positivo:\n";
	int count=0;
	for (i=0; i<30; i++) {
		if (banco[i][4] == 0) {
			cout << "\n* " << banco[i][0];
			if (banco[i][3] >= 1000 && banco[i][3] <= 10000) count++;
		}
	}
	cout << "\nTotal de correntistas com saldo entre R$ 1.000,00 e R$ 10.000,00: " << count;
}