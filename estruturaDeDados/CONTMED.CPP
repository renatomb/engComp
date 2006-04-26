
#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#define num 1500

long I,F,T[5];
int n,i,troca,aux,a[num],b[num];
void salva();
void metodo1();
void metodo2();
void metodo3();
void metodo4();
void metodo5();

long tempo()
	{
	 long h,m,s,hs,t1;
	 struct time t;
	 gettime(&t);
	 h=t.ti_hour;
	 m=t.ti_min;
	 s=t.ti_sec;
	 hs=t.ti_hund;
	 t1=(h*360+m*60+s)*100+hs;
	 return t1;}

void salva()
 {
 for(i=0;i<n;i++)
	b[i]=a[i];
 }


void metodo1()
  {
	I=tempo();
	troca=1;
	while(troca==1)
	{
	 troca=0;
	 for(i=0;i<n-1;i++)
	 {
	  if(b[i]>b[i+1])
	  {
		troca=1;
		aux=b[i];
		b[i]=b[i+1];
		b[i+1]=aux;
		}
	  }
	 }
 //  for(i=0;i<n;i++)
 //		cout<<"\n"<<b[i];
	F=tempo();
	T[0]=F-I;
 //	cout<<"\nTEMPO DO METODO 1 "<<T[0];
  }

void metodo2()
{
I=tempo();
for(int i=0;i<n-1;i++)
  {
	for(int j=i+1;j<n;j++)
	{
	 if(b[i]>b[j])
	  {
		aux=b[i];
		b[i]=b[j];
		b[j]=aux;
		}
	 }
	}
//for(i=0;i<n;i++)
//  cout<<"\n"<<b[i];
F=tempo();
T[1]=F-I;
//cout<<"\nTEMPO DO METODO 2 "<<T[1];
}

void metodo3()
{
I=tempo();
 int menor,k;
 for(int i=0;i<n-1;i++)
  {
	menor=b[i];
	k=i;
	for(int j=i+1;j<n;j++)
	{
	 if(menor>b[j])
	 {
	  menor=b[j];
	  k=j;
	  }
	 }
	 aux=b[i];
	 b[i]=b[k];
	 b[k]=aux;
	}
//for(i=0;i<n;i++)
//  cout<<"\n"<<b[i];
F=tempo();
T[2]=F-I;
//cout<<"\nTEMPO DO METODO 3 "<<T[2];
}


void metodo4()
{
I=tempo();
int c[num],j;
	for(i=0;i<(n-1);i++)
		for(j=(i+1);j<n;j++)
			if(b[i]>b[j])
				c[i]++;
			else
				c[j]++;
//	for(i=0;i<n;i++)
//		for(j=0;j<n;j++)
//			if(c[j]==i)
//				cout<<"\n"<<b[j];
F=tempo();
T[3]=F-I;
//cout<<"\nTEMPO DO METODO 4 "<<T[3];
}

void metodo5()
{
I=tempo();
int k;
k=n;
	while(1)
	  {k=int(k/1.3);
		if(k<1)
			{k=1;
			troca=0;
			}
		for(i=0;i<(n-k);i++)
			if(b[i]>b[i+k])
				{aux=b[i];
				b[i]=b[i+k];
				b[i+k]=aux;
				troca=1;
				}
			if(troca==0&&k==1)
				break;
		 }
//for (i=0;i<n;i++)
//	cout<<"\n"<<b[i];
//break;
F=tempo();
T[4]=F-I;
//cout<<"\nTEMPO DO METODO 5 "<<T[4];

}



void main()
{
 char ch;
 while(1)
 {
  clrscr();
  printf("\nEntre como a quantidade de numeros p/ ordenar : ");
  cin>>n;
  randomize();
  for(i=0;i<n;i++)
  {
	a[i]=random(10000);
	//printf("\na[%d]= %d", i+1,a[i]);
	}
  //getch();
  salva();
  metodo1();
  salva();
  metodo2();
  salva();
  metodo3();
  salva();
  metodo4();
  salva();
  metodo5();
  clrscr();
  cout<<"\n                   TEMPO DE EXECUCAO";
  cout<<"\n\n         METODO 1 = "<<T[0];
  cout<<"\n         METODO 2 = "<<T[1];
  cout<<"\n         METODO 3 = "<<T[2];
  cout<<"\n         METODO 4 = "<<T[3];
  cout<<"\n         METODO 5 = "<<T[4];
  cout<<"\n\n DIGITE ENTRE PARA SABER O METODO MAIS RAPIDO :";
  getch();
  n=5;
  for(i=0;i<n;i++)
	{b[i]=T[i];
	 a[i]=T[i];}
  metodo1();
  clrscr();
  if(b[0]==a[0])
		cout<<"\nMETODO 1 E MAIS RAPIDO COM O TEMPO DE "<<a[0];
  if(b[0]==a[1])
		cout<<"\nMETODO 2 E MAIS RAPIDO COM O TEMPO DE "<<a[1];
  if(b[0]==a[2])
		cout<<"\nMETODO 3 E MAIS RAPIDO COM O TEMPO DE "<<a[2];
  if(b[0]==a[3])
		cout<<"\nMETODO 4 E MAIS RAPIDO COM O TEMPO DE "<<a[3];
  if(b[0]==a[4])
		cout<<"\nMETODO 5 E MAIS RAPIDO COM O TEMPO DE "<<a[4];
  printf("\n\n<ESC> para terminar: ");
  ch=getch();
  if(ch==27)
	  break;
  }
}


