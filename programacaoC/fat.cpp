#include <iostream.h>

void main() {
	int n, fat=1;
	cout << "Entre com um número: ";
	cin >> n;
	for (int i=1; i<=n; i++) fat=fat*i;
	cout << "O fatorial de " << n << " é: " << fat << "\n\n\n";
	cout << "(C) 2001 - Renato Monteiro Batista\n";
	cout << "    CCCC   +     +          eee  h           DDDD    +  \n";
	cout << "   C       +     +         e   e h           D   D   +  \n";
	cout << "   C     +++++ +++++       eeee  hhhh        D   D +++++\n";
	cout << "   C       +     +         e     h   h       D   D   +  \n";
	cout << "    CCCC   +     +          eeee h   h       DDDD    +  \n";
}
