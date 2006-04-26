/*---------------------------------
UNP - Universidade Potiguar
Curso de Engenharia de Computacao - 1º Ano
Disciplina de Fisica II
Professor: Fabio Augusto
Alunos:
- DANIELA NONATO DE PAIVA
- RENATO MONTEIRO BATISTA
---------------------------------*/
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#define s setw(10)

float f2c(float tf);
float c2f(float tc);
float c2k(float tc);
float k2c(float tk);
float k2r(float tk);
float r2k(float tk);
void escala();
int tabela();
int teste(int tipo);

char ch;
int c=0;
float inf, sup, passo, tc, tk, tf, tr, aux;
void main() {
	for(;;) {
	if (c == 1) { break; }
	clrscr();
	cout << "\n********************************************************";
	cout << "\n* Escolha a escala:                                    *";
	cout << "\n* 0 - Sair                                             *";
	cout << "\n* 1 - Celsius                 2 - Farenheit            *";
	cout << "\n* 3 - Kelvin                  4 - Rankine              *";
	cout << "\n********************************************************";
	escala();
	if (ch == '0') { break; }
	cout << "\nInforme o limite inferior..........: "; cin >> inf;
	cout << "Informe o limite superior..........: "; cin >> sup;
	cout << "Informe o passo....................: "; cin >> passo;
	c=teste(2);
	c=tabela();
	}
	cout << "\nPrograma encerrado!!";
}

float f2c(float tf){ return ((9/float(5))*(tf-32)); }
float c2f(float tc){ return ((5/float(9))*tc)+32; }
float c2k(float tc){ return (tc+273.15); }
float k2c(float tk){ return (tk-273.15); }
float k2r(float tk){ return (9/float(5))*tk; }
float r2k(float tr){ return (5/float(9))*tr; }

int teste(int tipo) {
	switch (tipo) {
		case 1:
			if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4') { return 0; }
			else { cout << "\nVoce escolheu uma opcao invalida, tente novamente!"; getch(); return 1; }
		case 2:
			switch (ch) {
				case '1':
					if ((inf < -273.15) || (sup < -273.15)) { cout << "\nO intervalo informado possui temperaturas abaixo do zero absoluto!"; getch(); return 0; }
					else { return 1; }
				case '2':
					if ((inf < -119.15) || (sup < -119.15)) { cout << "\nO intervalo informado possui temperaturas abaixo do zero absoluto!"; getch(); return 0; }
					else { return 1; }
				case '3':
					if ((inf < 0) || (sup < 0)) { cout << "\nO intervalo informado possui temperaturas abaixo do zero absoluto!"; getch(); return 0; }
					else { return 1; }
				case '4':
					if ((inf < 0) || (sup < 0)) { cout << "\nO intervalo informado possui temperaturas abaixo do zero absoluto!"; getch(); return 0; }
					else { return 1; }
			}
	}
}

void escala() {
	do {
		cout << "\nInforme o numero da escala desejada: "; ch=getche();
	} while(teste(1));
}

int tabela() {
	char tecla;
	if (inf > sup) { aux=inf; inf=sup; sup=aux; }
	switch (ch) {
		case '1':cout << s << "ºC" << s << "ºF" << s << " K" << s << "ºR";break;
		case '2':cout << s << "ºF" << s << "ºC" << s << " K" << s << "ºR";break;
		case '3':cout << s << " K" << s << "ºC" << s << "ºF" << s << "ºR";break;
		case '4':cout << s << "ºR" << s << "ºC" << s << "ºF" << s << " K";break;
	}
	if (c){
	for (float i=inf;i<=sup;i=i+passo){
		switch (ch) {
			case '1':
				tc=i;tk=c2k(tc);
				tf=c2f(i);tr=k2r(tk);
				cout << '\n' << s << tc << s << tf << s << tk << s << tr;
				break;
			case '2':
				tc=f2c(i);tk=c2k(tc);
				tf=c2f(tc);tr=k2r(tk);
				cout << '\n' << s << tf << s << tc << s << tk << s << tr;
				break;
			case '3':
				tk=i;tc=k2c(tk);
				tf=c2f(tc);tr=k2r(tk);
				cout << '\n' << s << tk << s << tc << s << tf << s << tr;
				break;
			case '4':
				tk=r2k(i);tc=k2c(tk);
				tf=c2f(tc);tr=k2r(tk);
				cout << '\n'<< s << tr << s << tc << s << tf << s << tk;
				break;
		}
	}
	cout << "\nDeseja realizar nova consulta (S/N)? ";
	tecla=getche();
	if (tecla == 'N' || tecla == 'n') { return 1; }
	else { return 0; }
	}
}
