/* Aula de Programa��o cient�fica - 21/09/2001.

UNP - UNIVERSIDADE POTIGUAR
CURSO DE ENGENHARIA DE COMPUTA��O
ALUNO: RENATO MONTEIRO BATISTA

TRABALHO EM SALA DE AULA:
-------------------------

	Escrever um programa em C++ que calcule e imprima os dados estat�sticos a respeito
da turma do 1� ano do curso de engenharia de computa��o. O programa deve:
a) Ler a freq��ncia m�nima exigida como requisito parcial para a aprova��o do aluno em
algebra linear, programacao cientifica e calculo integral e series, nesta ordem. *
b) Ler o n�mero de matr�cula de cada aluno e suas duas notas em cada disciplina, al�m
de sua freq��ncia por disciplina. *
c) Calcular a m�dia para cada disciplina. *
d) Verificar se o aluno ter� direito de fazer a prova final de c�lculo (isto �, se ele �
frequente e obteve m�dia acima de 5.0 e menor que 7.0), imprimindo sua matricula e a
mensagem "RECUPERA��O EM C�LCULO"; *
e) Calcular a percentagem de alunos que foram aprovados em �lgebra. Sem a necessidade da
prova de recupera��o; *
f) N�mero de alunos reprovados em Programa��o.
*/

#include <iostream.h>

void main() {
	int fmc, fma, fmp, mat, fa, fp, fc, apa=0, rpp=0, count=0;
	float n1a, n2a, n1c, n2c, n1p, n2p, mediaa, mediac, mediap;
	cout << "\nEntre com a frequencia m�nima necess�ria p/aprova��o em algebra: ";
	cin >> fma;
	cout << "\nEntre com a frequencia m�nima necess�ria p/aprova��o em programa��o: ";
	cin >> fmp;
	cout << "\nEntre com a frequencia m�nima necess�ria p/aprova��o em c�lculo: ";
	cin >> fmc;
	do {
		cout << "\nEntre com a matr�cula do aluno (ou tecle 0 para sair): ";
		cin >> mat;
		if (mat == 0) break;
		count++;
		cout << "\nEntre com a frequencia e suas duas notas na disciplina de Algebra linear: ";
		cin >> fa >> n1a >> n2a;
		cout << "\nEntre com a frequencia e suas duas notas na disciplina de Programacao cientifica: ";
		cin >> fp >> n1p >> n2p;
		cout << "\nEntre com a frequencia e suas duas notas na disciplina de Calculo integral e series: ";
		cin >> fc >> n1c >> n2c;
		mediaa=(n1a+n2a)/2;
		mediac=(n1c+n2c)/2;
		mediap=(n1p+n2p)/2;
		if (mediac >= 5 && mediac < 7 && fc >= fmc) cout << '\n' << mat << " - RECUPERA��O EM C�LCULO";
		if (mediaa >=7 && fa >= fma) apa++;
		if (mediap < 5 || fp < fmp) rpp++;
	} while(mat != 0);
	cout << "\nPercentagem dos alunos aprovados em algebra: " << (float(apa)/float(count))*100 << '%';
	cout << "\nN�mero de alunos reprovados em programa��o: " << rpp;
}
