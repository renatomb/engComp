#include <iostream.h>
#include <stdlib.h>

void main() {
	int n, a[50], dup;
	cout << "Entre com o numero de elementos que deseja sortear: ";
	cin >> n;
	randomize();
	for (int i=0;i<n;i++){
		do {
			dup=0;
			a[i]=random(10000);
			for(int j=0;j<i;j++){
				if (a[i] == a[j]) {
					dup=1;
				}
			}
		} while(dup==1);
	}
	for (i=0;i<n;i++) {
		cout << a[i] << '\n';
	}
}
