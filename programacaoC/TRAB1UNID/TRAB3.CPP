/*---------------------------------
UNP - Universidade Potiguar
Curso de Engenharia de Computacao - 1� Ano
Disciplina Programacao Cientifica - 1� Unidade
Professor: Marcelo Mariano
Aluno: RENATO MONTEIRO BATISTA
Trabalho de C++ - Quest�o 03
---------------------------------*/
#include <iostream.h>

void main() {
	int n;
	char sexo;
	int melhor=-1, pior=11, nmelhor=0, npior=0, count=0;
	float media=0;
	do {
		cout << "Entre com o numero de alunos da Universidade Potiguar: ";
		cin >> n;
	} while (n > 10000);
	float cursos[100][4]; // OBS.: A matriz com 10000 linhas nao eh suportada pelo C!
	for (int i=0; i<n; i++) {
		cout << "Entre com a matricula do aluno: ";
		cin >> cursos[i][0];
		cout << "Entre com o sexo do aluno (M/F): ";
		cin >> sexo;
		if (sexo == 'M' || sexo == 'm') cursos[i][1]=1;
		else {
			if (sexo == 'F' || sexo == 'f') cursos[i][1]=0;
		}
		cout << "Entre com o numero do curso: ";
		cin >> cursos[i][2];
		cout << "Entre com a media geral no curso: ";
		cin >> cursos[i][3];
	}
	for (i=0; i<n; i++) {
		if (cursos[i][2] == 15) {
			if (cursos[i][3] > melhor) {
				melhor=cursos[i][3];
				nmelhor=cursos[i][0];
			}
			if (cursos[i][3] < pior) {
				pior=cursos[i][3];
				npior=cursos[i][0];
			}
			count++;
			media=media+cursos[i][3];
		}
	}
	cout << "\nAluno com melhor media no curso 15: " << nmelhor;
	cout << "\nAluno com pior media no curso 15: " << npior;
	cout << "\nMedia geral do curso 15: " << (media/count);
}