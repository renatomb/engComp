#include <iostream.h>
#include <conio.h>

int renato(int m, int n);

void main() {
	for(;;){
		int n,m;
		char ch;
		cout << "\nM=";
		cin >> m;
		cout << "N=";
		cin >> n;
		cout << "A["<<m<<","<<n<<"]=" << renato(m,n);
		cout << "\nTecle S caso deseje reiniciar o programa";
		ch=getch();
		if ((ch != 'S') && (ch != 's')) {
			break;
		}
	}
}

int renato(int m, int n){
	if (m == 0) { return n+1; }
	else {
		if (n == 0) { return renato(m-1,1); }
      else { return renato(m-1,renato(m,n-1)); }
	}
}

