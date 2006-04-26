#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <process.h>
#define TRUE 1

void incluir();
void listar();

struct ficha
{  int cod;
	char nome[10];
	struct ficha *fprox;
};

struct ficha *fprim,*fatual,*fnovo;

main()
{char ch;
 fprim=NULL;
 while(TRUE)
 {
  clrscr();
  gotoxy(30,10);
  cout <<" Incluir\n";
  gotoxy(30,12);
  cout<<" Listar\n";
  gotoxy(30,14);
  cout<<" Terminar";
  while(TRUE)
	{ch=getch();
	 if (ch=='I' || ch=='i' || ch=='L' || ch=='l'
		  || ch=='T' || ch=='t')
		 break;
	}
	switch(ch)
	 { case 'i':
		case 'I': incluir();
					 break;
		case 'l':
		case 'L': listar();
					 break;
		case 't':
		case 'T': exit(1);
	  }
  }
}

void incluir()
{ fnovo=new(ficha);
  if ( fprim==NULL)
	 fprim=fatual=fnovo;
  else
	 { fatual=fprim;
		while( fatual ->fprox !=NULL)
		  fatual=fatual->fprox;
		fatual->fprox=fnovo;
		fatual=fnovo;
	  }
  clrscr();
  cout<<"Codigo: ";
  cin>> fatual->cod;
  cout<<"\nNome: ";
  cin>> fatual->nome;
  fatual->fprox=NULL;

}

void listar()
{
  clrscr();
  if (fprim==NULL )
	{ cout <<"Lista vazia...";
	  getch();
	}
  else
	{ fatual=fprim;
	  while (fatual !=NULL)
		 {cout <<"Codigo: "<<fatual->cod;
		  cout <<"\nNome: "<<fatual->nome;
		  cout<<"\n\n";
		  getch();
		  fatual=fatual->fprox;		  }
	 }

}
