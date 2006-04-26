#include <iostream.h>

void main() {
	void copy();
	int media=0, masc=0, femi=0, idade;
	float ma_a, mb_a, altura;
	char sexo, ma_s, mb_s;
//	cout << "Entre com a quantidade de alunos da turma: ";
//	cin >> alunos;
	do {
		cout << "Entre com a idade, o sexo e a altura do aluno: ";
		cin >> idade >> sexo >> altura;
		if (media==0) {
			ma_s=sexo;
			mb_s=sexo;
			ma_a=altura;
			mb_a=altura;
		}
		if (idade == 0) {
			break;
		}
		media=media+idade;
		if (altura < mb_a) {
			mb_s=sexo;
			mb_a=altura;
		}
		if (altura > ma_a) {
			ma_s=sexo;
			ma_a=altura;
		}
		if (sexo == 'M' || sexo == 'm') {
			masc=masc++;
		}
		if (sexo == 'F' || sexo == 'f') {
			femi=femi++;
		}
	} while (idade != 0);
	media=media/(masc+femi);
	cout << "\na) A media de idade dos alunos é: " << media;
	cout << "\nb) Alunos homens: " << masc;
	cout << "\nc) Alunas mulheres: " << femi;
	cout << "\nd) O aluno mais alto é do sexo " << ma_s << " e sua altura é: " << ma_a;
	cout << "\ne) O aluno mais baixo é do sexo " << mb_s << " e sua altura é: " << mb_a;
	copy();
}

void copy() {
	cout << "\n(C) 2001 - Renato Monteiro Batista (Pré-engenheiro 1º Ano UnP)\n";
	cout << "    CCCC   +     +          eee  h           DDDD    +  \n";
	cout << "   C       +     +         e   e h           D   D   +  \n";
	cout << "   C     +++++ +++++       eeee  hhhh        D   D +++++\n";
	cout << "   C       +     +         e     h   h       D   D   +  \n";
	cout << "    CCCC   +     +          eeee h   h       DDDD    +  \n";
}
