/*
Aula 01/11/2001.

Exercicio:

Fazer um programa em c++ que leia os seguintes dados:
* Matricula - numerico;
* Nome - caractere (40);
* Curso - caractere (40);
* Sexo - caractere (10);
* Idade - numerico;

Armazene-os em uma matriz de estruturas alunos (50 elementos). Em seguida lista
todos os alunos do curso de Engenharia de Computacao, do sexo masculino com mais
de 21 anos.
*/

#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define n 5

struct aluno {
	int matricula;
	char nome[40];
	char curso[40];
	char sexo[10];
	int idade;
};
aluno alunos[n];
void maiusculo()

void main() {
	for(int i=0;i<n;i++) {
		clrscr();
		cout << "\nEntre com os dados do " << (i+1) << "º aluno (informe matricula 0 para sair): ";
		cout << "\n---------------------------------------------------";
		cout << "\nEntre com a matricula do aluno:";
		cin >> alunos[i].matricula;
		if (alunos[i].matricula == 0) break;
		cout << "Entre com o nome do aluno: ";
		gets(alunos[i].nome);
		cout << "Entre com o curso do aluno: ";
		gets(alunos[i].curso);
		cout << "Entre com o sexo desse aluno: ";
		gets(alunos[i].sexo);
		cout << "Entre com a idade desse aluno: ";
		cin >> alunos[i].idade;
	}
	clrscr();
	cout << "\nListagem dos alunos que atendem ao criterio:";
	cout << "\n---------------------------------------------------";
	for (i=0; i<n; i++) {
		char engcomp[]="ENGENHARIA DE COMPUTACAO";
		char boys[]="MASCULINO";
		if (strcmp(alunos[i].curso,engcomp) == 0 && strcmp(alunos[i].sexo,boys) == 0 && alunos[i].idade > 21) {
			cout << "\n********** Aluno de matricula: " << alunos[i].matricula << " **********";
			cout << "\n* Nome..: " << alunos[i].nome;
			cout << "\n* Curso.: " << alunos[i].curso;
			cout << "\n* Sexo..: " << alunos[i].sexo;
			cout << "\n* Idade.: " << alunos[i].idade;
		}
	}
}



toupper
