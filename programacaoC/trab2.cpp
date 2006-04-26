#include <iostream.h>
#include <stdio.h>
#include <string.h>
#define f 1

class ccheque {
	private:
		char fulano[40];
		int inscricao;
		float salhn, salhe, deducao, liquido;
	public:
		void init(int ins,int cla,int hno,int hex,char nome[]);
		void imprime();
};

float sref;
void main() {
	char nome[40];
	int ins, cla, hno, hex;
	cout << "Entre com o valor do salario de referencia: ";
	cin >> sref;
	ccheque vetor[f];
	for (int i=0;i<f;i++){
		cout << "\nEntre com os dados do funcionario " << (i+1) << ": ";
		cout << "\nInscricao: ";
		cin >> ins;
		cout << "Nome: ";
		gets(nome);
		cout << "Classe: ";
		cin >> cla;
		cout << "Horas normais: ";
		cin >> hno;
		cout << "Horas extras: ";
		cin >> hex;
		vetor[i].init(ins,cla,hno,hex,nome);
	}
	for (i=0;i<f;i++){
		vetor[i].imprime();
	}
}

void ccheque::init(int ins,int cla,int hno,int hex,char nome[]) {
	float base, bruto;
	inscricao=ins;
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
	strcpy(fulano,nome);
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

