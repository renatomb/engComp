//-----------------------------------------------------------------
//UnP - Universidade Potiguar
//Departamento de Engenharia e Ciencia Exatas
//Disciplina: Estrutura de Dados
//Professor.: Alax
//Aluno.....: Rogerio Glaidson M. Gama
//-----------------------------------------------------------------
//Trabalho: Implementacao do Algoritmo MergeSort
//-----------------------------------------------------------------

#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
  int n,i,j,v1,v2,ini_mei,mei_fim,aux,a[500],a_ord[500];

  randomize();
  while(1)
  {
	 clrscr();
	 cout<<"N=";
	 cin>>n;
	 for(i=0;i<n;i++)
		/*cin>>a[i]*/a[i]=random(250);

	 ini_mei=int(n/2);
	 if(n%2==0)
		mei_fim=(n-ini_mei);
	 else
		mei_fim=(n-ini_mei)-1;

	 for(i=0;i<ini_mei-1;i++)
		for(j=i+1;j<ini_mei;j++)
		  if(a[i]>a[j])
		  {
			 aux=a[i];
			 a[i]=a[j];
			 a[j]=aux;
		  }

	 for(i=mei_fim;i<n-1;i++)
		for(j=i+1;j<n;j++)
		  if(a[i]>a[j])
		  {
			 aux=a[i];
			 a[i]=a[j];
			 a[j]=aux;
		  }

	 v1=0;
	 v2=mei_fim;

	 for(i=0;i<n;i++)
	 {
		if ((v1 >= mei_fim) || (v2 >= n))
		{
			if ((v1 >= mei_fim) && (v2 >= n))
			{
			  break;
			}
			if (v1 >= mei_fim)
			{
			  a_ord[i]=a[v2];
			  v2++;
			}
			else
			{
			  a_ord[i]=a[v1];
			  v1++;
			}
		}
		else
		{
		  if(a[v1]<a[v2])
		  {
			 a_ord[i]=a[v1];
			 v1++;
		  }
		  else
		  {
			 a_ord[i]=a[v2];
			 v2++;
		  }
		}
	 }
	 for(i=0;i<n;i++)
		cout<<setw(5)<<a_ord[i];

	 getch();
  }
}
