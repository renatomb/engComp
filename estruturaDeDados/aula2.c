#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>

void main ()
{
 int n, k, i, troca, aux, a[100];
 char ch;
 randomize ();
 while(1)
 {
  clrscr();
  cout<<"N=";
  cin>>n;
  for(i=0;i<n;i++)
		a[i]=random(1000);
		k=n;
		troca=0;
		while(1)
		{
		 k=max(int(k/1.3), 1);
		 if(k<1)
		  k=1;
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



