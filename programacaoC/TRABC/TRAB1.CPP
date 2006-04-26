/* UNP - Universidade Potiguar
Trabalho de C++ - Questão 01
Aluno: RENATO MONTEIRO BATISTA
Engenharia de Computacao - 1º ANo
*/

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
