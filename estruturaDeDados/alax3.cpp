#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
  int n,i,k,troca,aux,a[100];
  char ch;
  randomize();
  while(1)
  {
	 clrscr();
	 cout<<"N= ";
	 cin>>n;
	 for(i=0;i<n;i++)
		a[i]=random(1000);
	 k=n;

	 while(1)
	 {
		troca=0;
		k=max(int(k/1.3),1);
		for(i=0;i<n-k;i++)
		  if(a[i]>a[i+k])
		  {
			 aux=a[i];
			 a[i]=a[i+k];
			 a[i+k]=aux;
			 troca=1;
		  }
		if(troca==0 && k==1)
		  break;
	 }
	 clrscr();
	 for(i=0;i<n;i++)
		cout<<setw(5)<<a[i];
	 cout<<"\n\n\<ESC> para sair";
	 ch=getch();
  }
}

