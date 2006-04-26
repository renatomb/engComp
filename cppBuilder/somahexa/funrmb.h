#include <math.h>

//Bloco de busca na optab
AnsiString busca(AnsiString whatlook, int pos){
   int plusflag=0;
   if (whatlook.SubString(1,1) == "+"){
      plusflag++;
      whatlook=whatlook.SubString(2,whatlook.Length());
   }
   for(int i=0;i<59;i++){
      if(opcode_table[i][0] == whatlook.UpperCase()) {
         if (!plusflag){
            return opcode_table[i][pos];
         }
         else {
            if (opcode_table[i][2] == "3") {
               if (pos == 2){ return "4"; }
               else { return opcode_table[i][pos]; }
            }
         }
      }
   }
   return "-1";
}
AnsiString formato(AnsiString wtl){
   return busca(wtl,2);
}
AnsiString codop(AnsiString wtl){
   return busca(wtl,1);
}

//Bloco de soma de hexadecimais
int ishexa(AnsiString param) {
   int erros=0;
   for(int i=1;i<=param.Length();i++) {
      int letra;
      letra=param[i];
      if ((letra < 48 || letra > 57) && !(letra >=65 && letra <=70) && !(letra == 45)) {
         erros++;
         break;
      }
   }
   if (!erros) { return 1; }
   else { return 0; }
}
int cln(char c) {
   int alfa;
   switch(c) {
      case 'A':alfa=10;break;
      case 'B':alfa=11;break;
      case 'C':alfa=12;break;
      case 'D':alfa=13;break;
      case 'E':alfa=14;break;
      case 'F':alfa=15;break;
      case '0':alfa=0;break;
      case '1':alfa=1;break;
      case '2':alfa=2;break;
      case '3':alfa=3;break;
      case '4':alfa=4;break;
      case '5':alfa=5;break;
      case '6':alfa=6;break;
      case '7':alfa=7;break;
      case '8':alfa=8;break;
      case '9':alfa=9;break;
   }
   return alfa;
}
AnsiString hextoint(AnsiString num) {
   int n_ch, n_int=0;
   n_ch=num.Length();
   for(int i=n_ch; i>0; i=i-1){
      if ((i == 1) && (num[i] == 45)) {
         n_int=n_int*(-1);
      }
      else {
         n_int=n_int+(cln(num[i])*pow(16,n_ch-i));
      }
   }
   return IntToStr(n_int);
}
AnsiString inttohex(AnsiString num) {
   int numero,n_ch;
   AnsiString retorno, valor;
   if (num.Length() > 0) {
      numero=StrToInt(num);
      do {
         switch(numero%16){
            case 10:valor=valor+'A';break;
            case 11:valor=valor+'B';break;
            case 12:valor=valor+'C';break;
            case 13:valor=valor+'D';break;
            case 14:valor=valor+'E';break;
            case 15:valor=valor+'F';break;
            default:valor=valor+(numero%16);break;
         }
         numero=numero/16;
      } while (numero>0);
      for(int i=valor.Length(); i>0; i=i-1){
         retorno=retorno+valor[i];
      }
   }
   return retorno;
}
AnsiString somahex(AnsiString um, AnsiString dois) {
   int soma;
   soma=StrToInt(hextoint(um))+StrToInt(hextoint(dois));
   return inttohex(soma);
}

//Bloco de remocao de spacos duplicados
AnsiString alltrim(AnsiString texto){
   AnsiString retorno;
   int contc=0;
   for(int i=1;i<=texto.Length();i++){
      if ((texto[i] != 32) && (texto[i] != 9)){
         retorno=retorno+texto[i];
         contc=0;
      }
      else{
         contc++;
         if (contc == 1) {
            retorno=retorno+" ";
         }
      }
   }
   return retorno;
}

//Bloco de funcoes em teste nuclear
AnsiString nextspace(AnsiString texto){
   return texto.SubString(1,texto.Pos(" "));
}
int posspace(AnsiString texto){
   return texto.Pos(" ");
}

