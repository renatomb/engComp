/*---------------------------------
UNP - Universidade Potiguar
Curso de Engenharia de Computacao - 1º Ano
Disciplina Programacao Cientifica - 2ª Unidade
Professor: Marcelo Mariano
Aluno: RENATO MONTEIRO BATISTA
Trabalho de C++ - Questão 02
---------------------------------*/

#include <iostream.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define f 2 // => Altere esse valor para o numero de registros desejado. 

class ccheque {
	private:
		char fulano[40];
		int inscricao;
		float salhn, salhe, deducao, liquido;
	public:
		void init();
		void imprime();
		int valida(int tc,int li,int ls);
};

float sref;
void main() {
	cout << "Entre com o valor do salario de referencia: ";
	cin >> sref;
	ccheque vetor[f];
	for (int i=0;i<f;i++){
		cout << "\nEntre com os dados do funcionario " << (i+1) << ": ";
		vetor[i].init();
	}
	clrscr();
	for (i=0;i<f;i++){
		vetor[i].imprime();
	}
}

void ccheque::init() {
	int cla, hno, hex;
	float base, bruto;
	cout << "\nInscricao: ";
	cin >> inscricao;
	cout << "Nome: ";
	gets(fulano);
	do {
	cout << "Classe (1 ou 2): ";
	cin >> cla;
	} while(!valida(cla,1,2));
	cout << "Horas normais: ";
	cin >> hno;
	cout << "Horas extras: ";
	cin >> hex;
	switch (cla) {
		case 1:
			base=1.3*sref;
			break;
		case 2:
			base=1.9*sref;
			break;
	}
	salhn=hno*base;
	salhe=hex*1.3*base;
	bruto=salhn+salhe;
	deducao=bruto*(0.08);
	liquido=bruto-deducao;
}

void ccheque::imprime() {
	cout << "\n************************************************************************";
	cout << "\n* N. Insc.: " << inscricao << " Nome: " << fulano;
	cout << "\n* Salario horas normais: " << salhn;
	cout << "\n* Salario horas extras: " << salhe;
	cout << "\n* Deducao INSS: " << deducao;
	cout << "\n* Salario liquido: " << liquido;
	cout << "\n************************************************************************";
}

int ccheque::valida(int tc,int li,int ls){
	if (tc >= li && tc <= ls) { return 1; }
	else { return 0; }
}

