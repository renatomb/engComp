/* Aula de Programação científica - 21/09/2001.

UNP - UNIVERSIDADE POTIGUAR
CURSO DE ENGENHARIA DE COMPUTAÇÃO
ALUNO: RENATO MONTEIRO BATISTA

TRABALHO EM SALA DE AULA:
-------------------------

	Escrever um programa em C++ que calcule e imprima os dados estatísticos a respeito
da turma do 1º ano do curso de engenharia de computação. O programa deve:
a) Ler a freqüência mínima exigida como requisito parcial para a aprovação do aluno em
algebra linear, programacao cientifica e calculo integral e series, nesta ordem. *
b) Ler o número de matrícula de cada aluno e suas duas notas em cada disciplina, além
de sua freqüência por disciplina. *
c) Calcular a média para cada disciplina. *
d) Verificar se o aluno terá direito de fazer a prova final de cálculo (isto é, se ele é
frequente e obteve média acima de 5.0 e menor que 7.0), imprimindo sua matricula e a
mensagem "RECUPERAÇÃO EM CÁLCULO"; *
e) Calcular a percentagem de alunos que foram aprovados em álgebra. Sem a necessidade da
prova de recuperação; *
f) Número de alunos reprovados em Programação.
*/

#include <iostream.h>

void main() {
	int fmc, fma, fmp, mat, fa, fp, fc, apa=0, rpp=0, count=0;
	float n1a, n2a, n1c, n2c, n1p, n2p, mediaa, mediac, mediap;
	cout << "\nEntre com a frequencia mínima necessária p/aprovação em algebra: ";
	cin >> fma;
	cout << "\nEntre com a frequencia mínima necessária p/aprovação em programação: ";
	cin >> fmp;
	cout << "\nEntre com a frequencia mínima necessária p/aprovação em cálculo: ";
	cin >> fmc;
	do {
		cout << "\nEntre com a matrícula do aluno (ou tecle 0 para sair): ";
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
		if (mediac >= 5 && mediac < 7 && fc >= fmc) cout << '\n' << mat << " - RECUPERAÇÃO EM CÁLCULO";
		if (mediaa >=7 && fa >= fma) apa++;
		if (mediap < 5 || fp < fmp) rpp++;
	} while(mat != 0);
	cout << "\nPercentagem dos alunos aprovados em algebra: " << (float(apa)/float(count))*100 << '%';
	cout << "\nNúmero de alunos reprovados em programação: " << rpp;
}
