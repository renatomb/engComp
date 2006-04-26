#include <iostream.h>
#include <conio.h>
#include <stdio.h>

char cod[3]={'A','B','C'};
int n;

void move(int n, int ori, int meio, int des){
	if (n==1)
		cout << "\nMover Disco 1 da Torre " << cod[ori]
		<< " para torre " << cod[des];
	else{
		move(n-1, ori, des, meio); // 0,2,1
		cout << "\nMover Disco " << n << " da torre "
		<< cod[ori] << " para torre " << cod[des];
		move(n-1,meio,ori,des); // 1,0,2
	}
}

void main(){
	char ch;
	while(1){
		clrscr();
		cout<<"No de Discos=";
		cin>>n;
		move(n,0,1,2);
		cout<<"\n\n\n<ESC> para terminar";
		ch = getch();
		if (ch == 27)
			break;
	}
}


