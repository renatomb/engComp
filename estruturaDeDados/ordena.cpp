#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#define num 2500

long score[5];
int n,matrix[num],vetor[num];

long tempo(){
	 long h,m,s,hs,t1;
	 struct time t;
	 gettime(&t);
	 h=t.ti_hour;
	 m=t.ti_min;
	 s=t.ti_sec;
	 hs=t.ti_hund;
	 t1=(h*360+m*60+s)*100+hs;
	 return t1;
}

void dados(){
	for(int i=0;i<n;i++){
		vetor[i]=matrix[i];
	}
}

void metodo_1(){
	int aux,troca=1;
	while(troca==1){
		troca=0;
		for(int i=0;i<n-1;i++){
			if(vetor[i]>vetor[i+1]){
				troca=1;
				aux=vetor[i];
				vetor[i]=vetor[i+1];
				vetor[i+1]=aux;
			}
		}
	}
}

void metodo_2(){
	int aux;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(vetor[i]>vetor[j]){
				aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}
		}
	}
}

void metodo_3(){
	int menor,k,aux;
	for(int i=0;i<n-1;i++){
		menor=vetor[i];
		k=i;
		for(int j=i+1;j<n;j++){
			if(menor>vetor[j]){
				menor=vetor[j];
				k=j;
			}
		}
		aux=vetor[i];
		vetor[i]=vetor[k];
		vetor[k]=aux;
	}
}


void metodo_4(){
	int c[num];
	for(int i=0;i<(n-1);i++){
		for(int j=(i+1);j<n;j++){
			if(vetor[i]>vetor[j]){
				c[i]++;
			}
			else{
				c[j]++;
			}
		}
	}
}

void metodo_5(){
	int k,troca,aux;
	k=n;
	for(;;){
		k=int(k/1.3);
		if(k<1){
			k=1;
			troca=0;
		}
		for(int i=0;i<(n-k);i++){
			if(vetor[i]>vetor[i+k]){
				aux=vetor[i];
				vetor[i]=vetor[i+k];
				vetor[i+k]=aux;
				troca=1;
			}
		}
		if((troca==0) && (k==1)){
			break;
		}
	}
}

void metodo(int metodo){
	switch (metodo) {
		case 0:
			metodo_1();
			break;
		case 1:
			metodo_2();
			break;
		case 2:
			metodo_3();
			break;
		case 3:
			metodo_4();
			break;
		case 4:
			metodo_5();
			break;
	}
}



void main(){
	for(;;){
		clrscr();
		printf("\nEntre como a quantidade de numeros p/ordenar: ");
		scanf("%d",&n);
		randomize();
		for(int i=0;i<n;i++){
			int dup=0;
			do {
				dup=0;
				matrix[i]=random(10000);
				for(int j=0;j<i;j++){
					if (matrix[i] == matrix[j]) {
						dup=1;
					}
				}
			} while(dup==1);
		}
		clrscr();
		printf("\nT e m p o s     d e     O r d e n a c a o");
		for(i=0;i<5;i++){
			long inicio;
			inicio=tempo();
			dados();
			metodo(i);
			score[i]=tempo()-inicio;
			printf("\nMetodo %d = %d (centesimos de segundo)",i+1,score[i]);
		}
		long menor;
		menor=score[0];
		int men_id=0;
		for (i=0;i<5;i++){
			if (score[i] < menor) {
				menor=score[i];
				men_id=i;
			}
		}
		printf("\nO metodo mais rapido foi o Metodo %d, com %d centesimos de segundo.",men_id+1,menor);
		printf("\n\n[ESC] para sair.");
		char ch;
		ch=getch();
		if(ch==27){
			break;
		}
	}
}
