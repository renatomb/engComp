//Programa para ELEICOES
//Aula 13/09/2001
//(c) 2001 - Renato Monteiro

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>

void computa(int voto);
int n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0;
void resultado();
void final();
int vitorioso();

void main() {
	 int voto;
	 for (;;) {
		  cout << "\nEntre com o seu voto: ";
		  cin >> voto;
		  if (voto == -1) { break; }
		  else { computa(voto); }
	 }
	 final();
}

void computa(int voto) {
	switch(voto){
		case 0:
			n0=n0++;
			break;
		case 1:
			n1=n1++;
			break;
		case 2:
			n2=n2++;
			break;
		case 3:
			n3=n3++;
			break;
		case 4:
			n4=n4++;
			break;
		case 5:
			n5=n5++;
			break;
		case 6:
			n6=n6++;
			break;
		case 7:
			n7=n7++;
			break;
	}
}

void final() {
	clrscr();
	cout << "\n*******************************";
	cout << "\n*   Resultado das eleicoes:   *";
	cout << "\n*-----------------------------*";
	cout << setfill('0');
	cout << "\n* a) Votos em branco...: " << setw(4) << n0 << " *";
	cout << "\n* b) Votos nulos.......: " << setw(4) << n7 << " *";
	cout << "\n* c) Votos computados..: " << setw(4) << (n0+n1+n2+n3+n4+n5+n6+n7) << " *";
	cout << "\n* d) Candidato campeao.: " << setw(4) << vitorioso() << " *";
	cout << "\n*******************************";
}

int vitorioso() {
	int maior=0,eleito=0;
	if (n1 > maior) {
		maior=n1;
		eleito=1;
	}
	if (n2 > maior) {
		maior=n2;
		eleito=2;
	}
	if (n3 > maior) {
		maior=n3;
		eleito=3;
	}
	if (n4 > maior) {
		maior=n4;
		eleito=4;
	}
	if (n5 > maior) {
		maior=n5;
		eleito=5;
	}
	if (n6 > maior) {
		maior=n6;
		eleito=6;
	}
	return eleito;
}
