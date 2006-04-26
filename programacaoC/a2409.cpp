#include <portugol.h>

programa
inicio
	char resposta=' ';
	int nao=0,sim=0;
	enquanto(resposta != 'T' e resposta !='t')
	inicio
		escreva("Você gostou do Anti-Virus VACALOUCA?");
		leia(resposta);
		se (resposta == 'S' ou resposta == 's')
		inicio
			sim=sim+1;
		fim
		senao
		inicio
			se (resposta == 'N' ou resposta == 'n')
			inicio
				nao=nao+1;
			fim
			se (resposta == 'T' ou resposta == 't')
			inicio
				pare;
			fim
		fim
	fim
	se (sim == nao)
	inicio
		escreva("PRODUTO REGULAR");
	fim
	senao
	inicio
		se (sim<nao)
		inicio
			escreva("PRODUTO RUIM");
		fim
		senao
		inicio
			escreva("PRODUTO EXCELENTE");
		fim
	fim
fim
