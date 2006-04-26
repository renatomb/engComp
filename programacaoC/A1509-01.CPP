//Engenharia de computacao - Aula 14/09/2001
//Exercicio FABRICA
//(c) 2001 - Renato Monteiro

#include <iostream.h>

float salario(int producao);
float classe_b(int producao);
float classe_c(int producao);
float sm;

void main() {
	int n, mat, pecas, prodmes=0, maior=-1, m_maior;
	char sexo, s_maior;
	float folha=0;
	cout << "\nEntre com o valor do salario minimo: ";
	cin >> sm;
	cout << "Entre com o numero de funcionarios: ";
	cin >> n;
	cout << "Entre com a matricula, o numero de pecas e o sexo do funcionario:";
	for (int i=1; i<=n; i++) {
		cout << '\n' << i << ": ";
		cin >> mat >> pecas >> sexo;
		cout << "O salario do funcionario " << mat << " eh: " << salario(pecas);
		folha=folha+salario(pecas);
		prodmes=prodmes+pecas;
		if (salario(pecas) > maior) {
			maior=salario(pecas);
			s_maior=sexo;
			m_maior=mat;
		}
	}
	cout << "\n\nTotal de pecas fabricadas no mes: " << prodmes;
	cout << "\nTotal da folha de pagamento da fabrica: " << folha;
	if (m_maior == 'M' || m_maior == 'm') { cout << "\nMatricula do operario de maior salario: " << m_maior; }
	else { cout << "\nMatricula da operaria de maior salario: " << m_maior; }
}

float salario(producao){
	if (producao > 30) {
		if (producao <36) { return classe_b((producao-30)); }
		else { return classe_c((producao-30)); }
	}
	else {
		return sm;
	}

}
float classe_b(producao) {
	return sm+(producao*(sm*0.03));
}
float classe_c(producao) {
	return sm+(producao*(sm*0.05));
}
