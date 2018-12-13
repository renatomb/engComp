/* Opera��es com Arquivos:
 * Objetos STREAM

 fstream{iostream(istream,ostream)}

 *Gravando linha a linha em arquivos disco:

 Exemplo:*/

 #include <fstream.h>//1
 void main()
 {
  ostream fout ("Teste.txt");
  fout<<"universidade potiguar\n";
  fout<<" curso de engenharia de computa��o \n";
  fout<<" programa��o cinent�fica \n";
 }

 // lendo arquivos

 #include<fstream.h>
 void main()
 {
  const int max=80;
  char buff[max];
  ifstream fin("teste.txt");
  while(fin)
  {
	fin.getline(buff,max);
	cout<<buff<<'\n';
  }
 }

 //2

 #include<fstream>
 void main()
 {
  const int max=80;
  char buff[max];
  ifstream fin("teste.txt");
  while(fin.getline(buff,max))//enquanto n�o eof
  cout<<buff<<'\n';
 }

 // Lendo e gravando arquivos em caracter por vez no arquivo
 #include<fstream.h>
 void main()
 {
 ofstream fout("teste1.txt");
 char ch;
 while (cin.get(ch)) fout.put(ch);
 }
 // =================================================================================
 #include<fstream.h>
 void main()
 {
  ifstream fin("teste1.txt");
  char ch;
  while (fin.get(ch)) cout.put(ch);
 }
