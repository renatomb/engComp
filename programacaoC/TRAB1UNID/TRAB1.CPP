/*---------------------------------
UNP - Universidade Potiguar
Curso de Engenharia de Computacao - 1� Ano
Disciplina Programacao Cientifica - 1� Unidade
Professor: Marcelo Mariano
Aluno: RENATO MONTEIRO BATISTA
Trabalho de C++ - Quest�o 01
---------------------------------*/

#include <iostream.h>
#include <math.h>

void main() {
	double s=0, x, nume, count=0;
	cout << "Entre com o valor de x: ";
	cin >> x;
	for (int i=50; i>0; i=i-1) {
		count=(count*2)+1;
		nume=exp(i*log(x));
		if (i%2 == 0) {
			s=s+(nume/count);
		}
		else {
			s=s-(nume/count);
		}
	}
	cout << "O valor da serie eh: " << s;
}
