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

void main() {
	int c=1;
	float inf, sup, passo, tc, tk, tf, tr;
	char ch;
	cout << "\n********************************************************";
	cout << "\n* Escolha a escala:                                    *";
	cout << "\n*                                                      *";
	cout << "\n* 1 - Celsius                 2 - Farenheit            *";
	cout << "\n* 3 - Kelvin                  4 - Rankine              *";
	cout << "\n********************************************************";
	cout << "\nInforme o numero da escala desejada: "; ch=getche();
	cout << "\nInforme o limite inferior..........: "; cin >> inf;
	cout << "Informe o limite superior..........: "; cin >> sup;
	cout << "Informe o passo....................: "; cin >> passo;
	clrscr();
	if ((inf > sup) && (passo>0)) { passo=passo*(-1); }
	switch (ch) {
		case '1':cout << s << "ºC" << s << "ºF" << s << " K" << s << "ºR";break;
		case '2':cout << s << "ºF" << s << "ºC" << s << " K" << s << "ºR";break;
		case '3':cout << s << " K" << s << "ºC" << s << "ºF" << s << "ºR";break;
		case '4':cout << s << "ºR" << s << "ºC" << s << "ºF" << s << " K";break;
		default:cout << "Voce nao escolheu uma escala valida. CHAU!!!";c=0;break;
	}
	if (c) {
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
	}
}

float f2c(float tf){ return ((9/float(5))*(tf-32)); }
float c2f(float tc){ return ((5/float(9))*tc)+32; }
float c2k(float tc){ return (tc+273.15); }
float k2c(float tk){ return (tk-273.15); }
float k2r(float tk){ return (9/float(5))*tk; }
float r2k(float tr){ return (5/float(9))*tr; }
