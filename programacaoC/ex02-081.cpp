#include <iostream.h>

union num {
	char ch;
	int i;
	float f;
};

void main(){
	num x;
	cout << "\nEndereco de ch = " << &x.ch;
	cout << "\nEndereco de i = " << &x.i;
	cout << "\nEndereco de f = " << &x.f;
	cout << "\nEndereco de x = " << &x;
}