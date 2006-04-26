/*
AULA 11/10/2001 - EXEMPLO 3

3 - Fazer um programa em c++ que leia uma matrix 50x4 onde na primeira
coluna colocaremos as matriculas dos alunos do 1º ano, na segunda coluna
as notas na 1ª unidade de programação, e na terceira coluna as notas da 2ª
unidade. Calcule as médias dos alunos colocando-as na quarta coluna.
*/

#include <iostream.h>
void main() {
	float turma[50][4];
	int i;
	cout << "\nDigite a matrícula e as duas notas dos alunos:";
	for (i=0; i<50; i++)
		cin >> turma[i][0] >> turma [i][1] >> turma[i][2];
	for (i=0; i<50; i++)
		turma[i][3]=(turma[i][1]+turma[i][2])/2;
	for (i=0; i<50; i++)
		cout << "\nAluno " << (i+1) << " media=" << turma[i][3];
}