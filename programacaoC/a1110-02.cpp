/*
AULA 11/10/2001 - Exemplo 2

2 - Fazer um programa em c++ que leia uma matrix A(3x5) e uma matriz B(5x3)
e calcule e imprima o produto destas duas matrizes.
*/

#include <iostream.h>
void main() {
	int a[3][5],b[5][3],c[3][3];
	int i,j,k;
	for (i=0; i<3; i++)
		for (j=0; i<5; j++)
			cin >> a[i][j];
	for (j=0; j<5; j++)
		for (i=0; i<3; i++)
			cin >> b[j][i];
	for (i=0; i<3; i++)
		for (k=0; k<3; k++) {
			c[i][k]=0;
			for (j=0; j<5; j++)
				c[i][k]=c[i][k]+a[i][j]*b[i][k];
		}
	for (i=0; i<3; i++)
		for (k=0; k<3; k++)
			cout << c[i][k];
}
