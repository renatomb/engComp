#include <iostream.h>
#include <conio.h>

void main() {
	int primo, total=0;
	double i, j, num=2;
	cout << "Entre com o numero inicial:";
	cin >> i;
	if ((i%num) == 0) {
		i++;
	}
	cout << "Pressione qualquer tecla para iniciar!";
	getch();
	for (i;total<20000;i=i+2) {
		primo=0;
		for (j=3;j<=i;j++) {
			if ((i%j)==0) {
				if (j == i) {
					primo=1;
				}
				else {
					break;
				}
			}
		}
		if (primo) {
//			cout << '\n' << i;
			total++;
			cout << i;
		}
	}
	cout << "Total: " << total;
}


// 2262
