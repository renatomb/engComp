/*---------------------------------
UNP - Universidade Potiguar
Curso de Engenharia de Computacao - 1º Ano
Disciplina Programacao Cientifica - 2ª Unidade
Professor: Marcelo Mariano
Aluno: RENATO MONTEIRO BATISTA
Trabalho de C++ - Questão 01
---------------------------------*/

#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define x 15  // => Altere esse valor para o numero de registros desejado.


struct book {
	int codigo;
	char autor[40];
	char titulo[50];
	int data;
	char editora[30];
};
book vetor[x];
void inclui(int i);
void atualiza(int i);
void imprime(int i);
void movedados(int p, int s);
void idx_titulo(int pos);
void idx_autor(int pos);
void idx_codigo(int pos);
int valida(int tc,int li,int ls);

void main() {
	int pos=0,idx=0, i;
	char tecla;
	int menu();
	int menu_i();
	do {
		tecla=menu();
		switch(tecla) {
			case '1':
				if (pos > x) { cout << "\nBanco de dados ja esta cheio, por favor escolha outra opcao!"; getch(); }
				else {
					char sn='S';
					do {
						inclui(pos);
						pos++;
						if (pos < x) { cout << "\nPressione qualquer tecla para incluir um novo registro ou ESC para sair"; sn=getch(); }
						else { sn=27; }
					} while(sn != 27);
				}
				if (idx > 0) {
					cout << "\nAguarde... REOrganizando registros...";
					switch(idx) {
						case 1:idx_titulo(pos);break;
						case 2:idx_autor(pos);break;
						case 3:idx_codigo(pos);break;
					}
				}
				break;
			case '2':
				if (pos == 0) { cout << "\nNao ha registros a alterar - Banco de dados vazio!"; getch(); break; }
				clrscr();
				for(i=0;i<pos;i++) {
					cout << "\n*********************************************************************";
					cout << "\nRegistro numero:" << i;
					imprime(i);
				}
				cout << "\n*********************************************************************";
				int regi;
				do {
					cout << "\nEscolha o registro que deseja alterar (-1 = Nao alterar nada): ";
					cin >> regi;
					if (!valida(regi,-1,pos-1)) { cout << "Voce selecionou um registro invalido, escolha outro ou -1!"; }
				} while(!valida(regi,-1,pos-1));
				if (regi >= 0) { atualiza(regi); }
				break;
			case '3':
				if (pos == 0) { cout << "\nNao ha registros a organizar - Banco de dados vazio!"; getch(); break; }
				idx=menu_i();
				cout << "\nAguarde... Organizando registros...";
				switch(idx) {
					case 1:idx_titulo(pos);break;
					case 2:idx_autor(pos);break;
					case 3:idx_codigo(pos);break;
				}
				break;
			case '4':
				if (pos == 0) { cout << "\nNao ha registros a listar - Banco de dados vazio!"; getch(); break; }
				clrscr();
				cout << "\nCatalogo de referencias: (";
				switch(idx) {
					case 0:cout << "Nao organizado)";break;
					case 1:cout << "Organizado por titulo)";break;
					case 2:cout << "Organizado por autores)";break;
					case 3:cout << "Organizado por codigo)";break;
				}
				for(i=0;i<pos;i++) imprime(i);
				cout << "\n*********************************************************************";
				cout << "\nPressione qualquer tecla para voltar ao menu principal";
				getch();
				break;
			case '5':
				break;
		}
	} while(tecla!='5');
}

void inclui(int i) {
	clrscr();
	cout << "\n* * * * * MODULO DE INCLUSAO:\n\n";
	cout << "Codigo de referencia: "; cin >> vetor[i].codigo;
	cout << "Autores: "; gets(vetor[i].autor);
	cout << "Titulo: "; gets(vetor[i].titulo);
	cout << "Data da publicacao: "; cin >> vetor[i].data;
	cout << "Editora: "; gets(vetor[i].editora);
	cout << "\nREGISTRO INCLUIDO COM SUCESSO!";
	getch();
}

void atualiza(int i) {
	clrscr();
	cout << "\n* * * * * MODULO DE ALTERACAO:";
	imprime(i);
	char tecla;
	cout << "\n\nVoce pode alterar:";
	cout << "\n1 - Codigo     2 - Autores";
	cout << "\n3 - Titulo     4 - Data";
	cout << "\n5 - Editora    0 - Nao alterar nada";
	do {
		cout << "\nSelecione o campo que deseja alterar: ";
		cin >> tecla;
	} while(!valida(tecla,'0','4'));
	switch(tecla){
		case '0':
			return;
		case '1':
			cout << "Digite o novo codigo: "; cin >> vetor[i].codigo;
			cout << "\nAlteracao de codigo efetuada com sucesso!!!";
			break;
		case '2':
			cout << "Digite os novos autores: "; gets(vetor[i].autor);
			cout << "\nAlteracao de autores efetuada com sucesso!!!";
			break;
		case '3':
			cout << "Digite o novo titulo: "; gets(vetor[i].titulo);
			cout << "\nAlteracao de titulo efetuada com sucesso!!!";
			break;
		case '4':
			cout << "Digite a nova data: "; cin >> vetor[i].data;
			cout << "\nAlteracao de data efetuada com sucesso!!!";
			break;
		case '5':
			cout << "Digite a nova editora: "; gets(vetor[i].editora);
			cout << "\nAlteracao de editora efetuada com sucesso!!!";
			break;
		default:
			cout << "Opcao invalida!!!";
			break;
	}
}

void imprime(int i) {
	cout << "\n*********************************************************************";
	cout << "\nCodigo: " << vetor[i].codigo << " - Titulo: " << vetor[i].titulo;
	cout << "\nAutores: " << vetor[i].autor;
	cout << "\nPublicado em: " << vetor[i].data << " - Editora: " << vetor[i].editora;
}

void idx_titulo(int pos) {
	int troca=0;
	do {
		troca=0;
		for (int i=0;i<(pos-1);i++) {
			if (strcmp(vetor[i].titulo,vetor[i+1].titulo) > 0) {
				troca=1;
				movedados(i,i+1);
			}
		}
	} while (troca > 0);
}

void idx_autor(int pos) {
	int troca=0;
	do {
		troca=0;
		for (int i=0;i<(pos-1);i++) {
			if (strcmp(vetor[i].autor,vetor[i+1].autor) > 0) {
				troca=1;
				movedados(i,i+1);
			}
		}
	} while (troca > 0);
}

void idx_codigo(int pos) {
	int troca=0;
	do {
		troca=0;
		for (int i=0;i<(pos-1);i++) {
			if (vetor[i].codigo > vetor[i+1].codigo) {
				troca=1;
				movedados(i,i+1);
			}
		}
	} while (troca > 0);
}


void movedados(int p, int s) {
	book aux;
	// Movendo dados para o auxiliar
	aux.codigo=vetor[p].codigo;
	aux.data=vetor[p].data;
	strcpy(aux.autor,vetor[p].autor);
	strcpy(aux.titulo,vetor[p].titulo);
	strcpy(aux.editora,vetor[p].editora);
	// Movendo dados do segundo para o primeiro
	vetor[p].codigo=vetor[s].codigo;
	vetor[p].data=vetor[s].data;
	strcpy(vetor[p].autor,vetor[s].autor);
	strcpy(vetor[p].titulo,vetor[s].titulo);
	strcpy(vetor[p].editora,vetor[s].editora);
	// Movendo dados do auxiliar para o segundo
	vetor[s].codigo=aux.codigo;
	vetor[s].data=aux.data;
	strcpy(vetor[s].autor,aux.autor);
	strcpy(vetor[s].titulo,aux.titulo);
	strcpy(vetor[s].editora,aux.editora);
}

int menu() {
	int tecla;
	do {
	clrscr();
	cout << "\n***********************************************************";
	cout << "\nUnP - Universidade Potiguar / Engenharia de Computacao";
	cout << "\nSistema de Artigos Cientificos";
	cout << "\n***********************************************************";
	cout << "\nMenu principal:";
	cout << "\n1 - Incluir uma referencia";
	cout << "\n2 - Atualizar dados de uma referencia";
	cout << "\n3 - Definir indice";
	cout << "\n4 - Listar todas as referencias";
	cout << "\n5 - Sair do sistema";
	cout << "\n***********************************************************";
	cout << "\nInforme o numero da opcao desejada:";
	tecla=getche();
	if (!valida(tecla,'1','5')) { cout << "\nVoce informou uma opcao invalida, por favor tente novamente!"; getch(); }
	} while(!valida(tecla,'1','5'));
	return tecla;
}

int valida(int tc,int li,int ls){
	if (tc >= li && tc <= ls) { return 1; }
	else { return 0; }
}

int menu_i() {
	int tecla;
	do {
	clrscr();
	cout << "\n***********************************************************";
	cout << "\nUnP - Universidade Potiguar / Engenharia de Computacao";
	cout << "\nSistema de Artigos Cientificos";
	cout << "\n***********************************************************";
	cout << "\nMenu de indexacao:";
	cout << "\n1 - Organizar por titulo";
	cout << "\n2 - Orgenizar por autores";
	cout << "\n3 - Organizar por codigo";
	cout << "\n***********************************************************";
	cout << "\nInforme o numero da opcao desejada:";
	cin >> tecla;
	if (!valida(tecla,1,3)) { cout << "\nVoce informou uma opcao invalida, por favor tente novamente!"; getch(); }
	} while(!valida(tecla,1,3));
	return tecla;
}

