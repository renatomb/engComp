#include <iostream.h>

void main() {
	float gordao, magrao, peso;
	int gordid, magrid;
//	for (int i=0; i<=89; i++) {
	for (int i=0; i<=4; i++) {
		cout << "Entre com o peso do boi " << (i+1) << ": ";
		cin >> peso;
		if (i==0) {
			magrao=peso;
			magrid=i+1;
			gordao=peso;
			gordid=i+1;
		}
		else {
			if (peso < magrao) {
				magrao=peso;
				magrid=i+1;
			}
			if (peso > gordao) {
				gordao=peso;
				gordid=i+1;
			}
		}
	}
	cout << "O boi mais gordo (" << gordid << ") pesa: " << gordao << '\n';
	cout << "O boi mais magro (" << magrid << ") pesa: " << magrao << "\n\n\n";
	cout << "(C) 2001 - Renato Monteiro Batista (Pré-engenheiro 1º Ano UnP)\n";
	cout << "    CCCC   +     +          eee  h           DDDD    +  \n";
	cout << "   C       +     +         e   e h           D   D   +  \n";
	cout << "   C     +++++ +++++       eeee  hhhh        D   D +++++\n";
	cout << "   C       +     +         e     h   h       D   D   +  \n";
	cout << "    CCCC   +     +          eeee h   h       DDDD    +  \n";
}