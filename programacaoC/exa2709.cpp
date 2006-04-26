/*
M A T R I Z E S

Sintaxe:
	tipo nome_matrix[tamanho]

Exemplo:
	int notas[5];

** Referenciando elementos da matriz
	notas[2]=9.0
	cin >> notas[i];

*/

#include <iostream.h>
void main()
{
	int dmes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int dia, mes, ano;
	cout << "\nDigite a data no formato DD/MM/AAAA: ";
	{
		char ch;
		cin >> dia >> ch >> mes >> ch >> ano;
	}
	if (ano%4==0 && ano%100 || ano%400 == 0)
		dmes[1]=29;
	int total=dia;
	for(int i=0;i < mes-1; i++)
		total=total+dmes[i];
	cout << "Total de dias transcorridos: " << total;
}
