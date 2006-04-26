#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int maiusculo(int num){
	if (num > 90){
		return num-32;
	}
	else{
		return num;
	}
}

void main() {
	cout << "Entre com a chave: ";
	char chave[10],mensagem[50];
	gets(chave);
	for (int i=0;i<10;i++) {
		chave[i]=maiusculo(chave[i]);
	}
	int alfa[10],tem_enter=0,cont=0,sub_cont=-1;
	for (i=0;i<10;i++) {
		if (chave[i] == 0) { tem_enter=i-1; }
		if (tem_enter) { alfa[i]=0; }
		else { alfa[i]=chave[i]-65; }
	}
	cout << "Entre com a mensagem a ser codificada: ";
	while(1){
		char tecla;
		tecla=maiusculo(getche());
		if (tecla == 13) { break; }
		sub_cont++;
		if (sub_cont > tem_enter) { sub_cont=0; }
		mensagem[cont]=tecla+alfa[sub_cont];
      if (mensagem[cont] > 90) { mensagem[cont]-=26; }
		cont++;
	}
   cout << "\nMensagem codificada:\n"; 
	for (i=0;i<=cont;i++) { cout << mensagem[i]; }
}

