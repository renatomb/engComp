/*---------------------------------
UNP - Universidade Potiguar
Curso de Engenharia de Computacao - 1º Ano
Disciplina Programacao Cientifica - 1ª Unidade
Professor: Marcelo Mariano
Aluno: RENATO MONTEIRO BATISTA
Trabalho de C++ - Questão 02
---------------------------------*/

#include <iostream.h>

int renatus(char tipo);
int renatow(char soun);

void main() {
	int girls=0, boys=0, iboys=0, nboys=0, homens=0, mulheres=0, inscr, idade;
	char sexo, expe;
	do {
		cout << "Entre com o numero de inscricao do candidato: ";
		cin >> inscr;
		if (inscr == 0) break;
		cout << "Qual a idade desse candidato? ";
		cin >> idade;
		cout << "Qual o sexo desse candidato? (M/F) ";
		cin >> sexo;
		cout << "Esse candidato ja possui experiencia no servico? (S/N) ";
		cin >> expe;
		if (renatus(sexo)) {
			boys++;
			if (renatow(expe)) {
				iboys=iboys+idade;
				nboys++;
			}
			if (idade > 30) {
				homens++;
			}
		}
		else {
			girls++;
			if (renatow(expe) && idade < 35) mulheres++;
		}
	} while (inscr != 0);
	cout << "Dados estatisticos:\n";
	cout << "\na) Total de candidatas do sexo feminino: " << girls;
	cout << "\nb) Total de candidatos do sexo masculino: " << boys;
	cout << "\nc) Idade media dos homens experientes: " << iboys/float(nboys) << "anos";
	cout << "\nd) Percentagem de homens com mais de 30 anos: " << (homens/float(boys))*100 << '%';
	cout << "\ne) Numero de mulheres c/menos de 35 anos e experientes: " << mulheres;
}

int renatus(char tipo) {
	if (tipo == 'M' || tipo == 'm') return 1;
	else {
		if (tipo == 'F' || tipo == 'f') return 0;
	}
}

int renatow(char soun) {
	if (soun == 'S' || soun == 's') return 1;
	else {
		if (soun == 'N' || soun == 'n') return 0;
	}
}