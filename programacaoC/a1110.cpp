/* Aula 11/10/2001.
# Matrizes de mais de uma dimensão

-> Declaração

tipo nome_matriz[linhas][colunas]
exemplo:
int soma[5][5];
float mult[3][5];


Exemplo:

1 - Fazer um programa em c++ que leia duas matrizes A e B de dimensões 3x5
e calcule e imprima a matriz soma.

*/

#include <iostream.h>
void main() {
	int a[3][5],b[3][5],c[3][5];
	int i, j;
	cout << "\nDigite a matriz A";
	for (i=0; i<3; i++)
		for (j=0; j<5; j++)
			cin >> a[i][j];
	for (i=0; i<3; i++)
		for (j=0; j<5; j++) {
			cout << "b[" << i << "][" << j << "]=";
			cin >> b[i][j];
		}
	for (i=0; i<3; i++)
		for (j=0; j<5; j++)
			c[i][j]=a[i][j]+b[i][j];
	for (i=0; i<3; i++)
		for (j=0; j<5; j++)
			cout << c[i][j];
}