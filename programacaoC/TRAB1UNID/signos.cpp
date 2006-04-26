#include <iostream.h>

void main() {
	char signos[12][12]={"Capricornio","Aquario","Peixes","Aries","Touro","Gemeos","Cancer","Leao","Virgem","Libra","Escorpiao","Sargitario"};
	int dias[12]={22,21,20,21,21,21,21,22,23,23,23,22};
	int dn, mn;
	cout << "Entre com o dia do seu nascimento: ";
	cin >> dn;
   cout << "Entre com o mes do seu nascimento: ";
	cin >> mn;
	if (mn == 12) mn=0;
	if (dn >= dias[mn]) {
		cout << "Seu signo eh: " << signos[mn];
	}
	else {
		if (mn > 0) {
			cout << "Seu signo eh: " << signos[mn-1];
		}
		else cout << "Seu signo eh: " << signos[0];
	}
}
