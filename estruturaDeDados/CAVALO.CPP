#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<iostream.h>
int n,x,y,h[8][8],z,nsqr,q;
void cavalo (int i,int x,int y,int q);

void main(){
	int i,j;
	cout<<("\nDigite o tamanho do tabuleiro ate 8 .");
	cin>>n;
	cout<< ("\nEntre com a posicao inicial:")<<("\nX = ");
	cin>>x;
	cout<< ("\nY = ");
	cin>>y;
	for( i=0;i<n;i++){
		for( j=0;j<n;j++){
			h[i][j]=0;
		}
	}
	nsqr=n*n;
	h[x][y]=1;
	q=0;
	cavalo(2,x,y,q);
	if (q!=0){
		for( i=0;i<n;i++){
			for( j=0;j<n;j++){
				cout<<h[i][j];
			}
		}
	}
	else{
		cout<<"\nSEM CAMINHO";
	}
}



void cavalo (int i,int x,int y,int q){
	int k,u,v,q1;
	int dx[8]={2,1,-1,-2,-2,-1,1,2},dy[8]={1,2,2,1,-1,-2,-2,-1};
	k=0;
	do{
		q1=0;
		u=x+dx[k];
		v=y+dy[k];
		if((0<=u)&&(u<=n)&&(0<=v)&&(v<=n)&&(h[u,v]==0)){
			h[u][v]=i;
		}
		if(i<nsqr){
			cavalo(i+1,u,v,q1);
			if(q1==1){
				h[u][v]=0;
			}
			else{
				q1=1;
			}
		}
		k=k++;
	}while((q1)||(k==7));
	q=q1;
}






