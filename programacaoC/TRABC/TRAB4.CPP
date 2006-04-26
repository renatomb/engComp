#include <iostream.h>

void main() {
	int num=10, sdp=0, sds=0;
	int matriz[8][8];
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			matriz[j][i]=num;
			num=num+5;
		}
	}
	for (i=0; i<8; i++) {
		cout << '\n';
		for (j=0; j<8; j++) {
			cout << matriz[i][j] << ' ';
			if (i=j) sdp=sdp+matriz[i][j];
			if (i+j=9) sds=sds+matriz[i][j];
		}
	}
	cout << "\nSoma da diagonal principal: " << sdp;
	cout << "\nSoma da diagonal secundaria: " << sds;
}
