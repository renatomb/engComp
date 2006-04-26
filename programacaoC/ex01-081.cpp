#include <iostream.h>
#include <string.h>
#include <iomanip.h>

void printfunc(void);

union num {
	char str[20];
	int i;
	float f;
}x;

enum datatipo{strtipo, inttipo, floattipo}tipo;

void intnum (char n[]) {
	tipo = strtipo;
	strcpy(x.str,n);
}

void intnum (float n) {
	tipo=floattipo;
	x.f=n;
}

void intnum (int n) {
	tipo=inttipo;
	x.i=n;
}

void main() {
	float y=3.14159;
	int z=123;
	intnum("ENGENHARIA");
	printfunc();
	intnum(z);
	printfunc();
	intnum(y);
	printfunc();
	cout << sizeof(num) << '\n';
	cout << sizeof(x);
}

void printfunc() {
	switch (tipo) {
		case strtipo:cout << "\nStr= " << x.str;
		break;
		case inttipo:cout << "\nInt= " << x.i;
		break;
		case floattipo:cout << setprecision(2);
		cout << "\nFloat= " << x.f;
		break;
	}
}