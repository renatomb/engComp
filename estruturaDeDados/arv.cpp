#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#define TRUE 1
// excluir metodo 2, menor elemento(esq) a direita
// do no a ser romovido
struct arv
{  char info;
	struct arv *esq;
	struct arv *dir;
};

struct arv *raiz;
int dele;

struct arv *preorder(struct arv *no)
{ if (no!=NULL)
	 {  cout<<no->info;
		 preorder(no->esq);
		 preorder(no->dir);
	 }
}

struct arv *posorder(struct arv *no)
{ if (no!=NULL)
	 {  posorder(no->esq);
		 posorder(no->dir);
		 cout<<no->info;
	 }
}

struct arv *inorder(struct arv *no)
{ if (no!=NULL)
	 {  inorder(no->esq);
		 cout<<no->info;
		 inorder(no->dir);
	 }
}

struct arv *incluir(struct arv *raiz,
						  struct arv *no,
						  char vr)

{
  struct arv *novo;
  if (no==NULL)
	{ novo=new(arv);
	  novo->esq=NULL;
	  novo->dir=NULL;
	  novo->info=vr;
	  no=novo;
	  if ( raiz!=NULL)
		 { if ( vr<raiz->info)
			  raiz->esq=no;
			else
			  raiz->dir=no;
		  }
	  return no;
	 }
  else
	  { if (vr > no->info )
			 incluir(no,no->dir,vr);
		 else
			 incluir(no,no->esq,vr);
		}
  }

void desenha(struct arv *no,int n)
{
 int i;
 if (no!=NULL)
	{  desenha(no->dir,n+1);
		cout<<"\n";
		for(i=1;i<=n;i++)
			cout<<"    ";
		cout<<no->info;
		desenha(no->esq,n+1);
	 }
 }

void menu()
{
  clrscr();
  gotoxy(20,4);
  cout <<" Incluir";
  gotoxy(20,6);
  cout<<" Desenhar";
  gotoxy(20,8);
  cout<<" Pre/in/pos/order";
  gotoxy(20,10);
  cout<<" Consultar";
  gotoxy(20,12);
  cout<<" Remover";
  gotoxy(20,14);
  cout<<" Terminar";
}

void entrada()
{ char ch;
  clrscr();
  while(TRUE)
	{ cout<<"\n\nDigite o no=";
	  ch=getche();
	  if (ch>91)
		 ch=ch-32;
	  cout<<"\n";
	  if ( ch>64 && ch<91)
		 { if (raiz!=NULL )
			  incluir(raiz,raiz,ch);
			else
			  raiz=incluir(raiz,raiz,ch);
			}
		else
		  { if ( ch==27)
				break;
				clrscr();
			}
	 }
 }

void main()
{
 char ch;
 raiz=NULL;
 while(TRUE)
 {
  menu();
  while(TRUE)
	{ch=getch();
	 if (ch=='I' || ch=='i' || ch=='D' || ch=='d'
		  || ch=='P' || ch=='p' || ch=='c' || ch=='C'
		  || ch=='r' || ch=='R' || ch=='T' || ch=='t')
		 break;
	}
	switch(ch)
	 { case 'i':
		case 'I': entrada();
					 break;
		case 'd':
		case 'D': clrscr();
					 if (raiz==NULL)
						{ cout <<"\n\nArvore vazia...";
						  getch();
						}
					 else
						{ desenha(raiz,0);
						  getch();
						}
					 break;
		case 'c':
		case 'C': consultar();
					 break;
		case 'r':
		case 'R': remover();
					 break;
		case 'p':
		case 'P': clrscr();
					 desenha(raiz,0);
					 cout<<"\n\nInorder=";
					 inorder(raiz);
					 cout<<"\n\nPreorder=";
					 preorder(raiz);
					 cout<<"\n\nPosorder=";
					 posorder(raiz);
					 getch();
					 break;
		case 't':
		case 'T': exit(1);
	  }
  }
}

