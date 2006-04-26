#include <iostream.h>

int quadrado(int num);

void main() {
	int num1=0,num2=0;
	cout << "\nEntre com o primeiro e o segundo numeros: ";
	cin >> num1 >> num2;
	cout << "\nA soma do quadrado desses numeros eh: " << (quadrado(num1)+quadrado(num2));
}

int quadrado(int num){
	return num*num;
}
