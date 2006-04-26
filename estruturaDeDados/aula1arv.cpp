#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#define TRUE 1

struct arv
{  char info;
	struct arv *esq;
	struct arv *dir;
};

struct arv *raiz;
struct arv *incluir(struct arv *raiz,
						  struct arv *no,
						  char vr, char l)

{ char lado;
  struct arv *novo;
  if (no==NULL)
	{ novo=new(arv);
	  novo->esq=NULL;
	  novo->dir=NULL;
	  novo->info=vr;
	  no=novo;
	  if ( raiz!=NULL)
		 { if ( l=='E')
			  raiz->esq=no;
			else
			  raiz->dir=no;
		  }
	  return no;
	 }
  else
	  { cout<<"E/D ? = ";
		 do{
			 lado=getch();
			 if (lado>97)
				 lado=lado-32;
			 }while(lado!='E' && lado!='D');
		 cout <<lado<<"\n";
		 if (lado=='D')
			 incluir(no,no->dir,vr,lado);
		 else
			 incluir(no,no->esq,vr,lado);
		}
  }

void desenha(struct arv *no,int n)
{
 int i;
 if (no!=NULL)
	{  desenha(no->dir,n+1);
		cout<<"\n\n";
		for(i=1;i<=n;i++)
			cout<<"    ";
		cout<<no->info;
		desenha(no->esq,n+1);
	 }
 }


void main()
{
 char ch;
 while(TRUE)
 {
  raiz=NULL;
  clrscr();
  while(TRUE)
	{ cout<<"\n\nDigite o no=";
	  ch=getche();
	  if (ch>91)
		 ch=ch-32;
	  cout<<"\n"; // Z->90   a->97   A->65
	  if ( ch>64 && ch<91)
		 { if (raiz!=NULL )
			  incluir(raiz,raiz,ch,' ');
			else
			  raiz=incluir(raiz,raiz,ch,' ');
			desenha(raiz,0);
		  }
		else
		  { if ( ch==27)
				break;
				clrscr();
			}
	 }
	cout<<"\n\n<ESC> para terminar";
	ch=getch();
	if (ch==27)
	  break;
	else
	  clrscr();

	}
}


