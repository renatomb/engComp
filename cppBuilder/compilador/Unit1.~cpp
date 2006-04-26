//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::botao_abrirClick(TObject *Sender)
{
   if (abrir->Execute()){
      editor->Lines->LoadFromFile(abrir->FileName);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::botao_salvarClick(TObject *Sender)
{
  if (salvar->Execute()) {
   editor->Lines->SaveToFile(salvar->FileName);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::botao_processarClick(TObject *Sender)
{
   botao_processar->Enabled=false;
   botao_processar->Caption="Processando...";
   limpa_arquivo();
   for(int i=0;i<editor->Lines->Count;i++) {
      AnsiString palavra;
      int tam_linha, pos_ult_palavra=-1,j;
      bool flag_string=false, flag_operador=false,flag_palavra=false;
      tam_linha=editor->Lines->Strings[i].Length();
      for (j=1;j<=tam_linha;j++){
         int letra=editor->Lines->Strings[i][j];
         if (!flag_string && !flag_operador && !flag_palavra) {
            if (((letra >= 65) && (letra <= 90)) || ((letra >= 97) && (letra <= 122)) || ((letra >= 48) && (letra <= 57))) {
               flag_palavra=true;
            }
            if (letra == 34) {
               flag_string=true;
            }
            if (letra == 42 || letra == 43 || letra == 45 || letra == 47 || letra == 58 || letra == 94 || (letra >=60 && letra <=62)) {
               flag_operador=true;
            }
            pos_ult_palavra=j;
         }
         else {
            if (letra == 34 && flag_string) {
               flag_string=false;
               palavra=editor->Lines->Strings[i].SubString(pos_ult_palavra,(j+1)-pos_ult_palavra);
               adiciona_palavra(palavra,i);
               pos_ult_palavra=-1;
            }
            if (flag_operador && !(letra == 42 || letra == 43 || letra == 45 || letra == 47 || letra == 58 || letra == 94 || (letra >=60 && letra <=62))){
               flag_operador=false;
               palavra=editor->Lines->Strings[i].SubString(pos_ult_palavra,j-pos_ult_palavra);
               adiciona_palavra(palavra,i);
               j--;
            }
            if (flag_palavra && !(((letra >= 65) && (letra <= 90)) || ((letra >= 97) && (letra <= 122)) || ((letra >= 48) && (letra <= 57)))) {
               flag_palavra=false;
               palavra=editor->Lines->Strings[i].SubString(pos_ult_palavra,j-pos_ult_palavra);
               adiciona_palavra(palavra,i);
               j--;
            }
         }
      }
      if (pos_ult_palavra > 0) {
         palavra=editor->Lines->Strings[i].SubString(pos_ult_palavra,j-pos_ult_palavra);
         adiciona_palavra(palavra,i);
      }
   }
   botao_processar->Caption="Processar";
   botao_processar->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
   editor->CopyToClipboard();   
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
   editor->PasteFromClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   palavras->Cells[0][0]="Palavra";
   palavras->Cells[1][0]="Identificador";
   palavras->Cells[2][0]="Linha";
   tab_toke->Cells[0][0]="Palavra";
   tab_toke->Cells[1][0]="Identificador";
   tab_toke->Cells[0][1]="BEGIN";
   tab_toke->Cells[0][2]="IF";
   tab_toke->Cells[0][3]="THEN";
   tab_toke->Cells[0][4]="END";
   tab_toke->Cells[0][5]="ELSE";
   tab_toke->Cells[0][6]="FOR";
   tab_toke->Cells[0][7]="TO";
   tab_toke->Cells[0][8]="DO";
   tab_toke->Cells[0][9]="WHILE";
   tab_toke->Cells[0][10]="REPEAT";
   tab_toke->Cells[0][11]="UNTIL";
   tab_toke->Cells[0][12]="BREAK";
   tab_toke->Cells[0][13]="VAR";
   tab_toke->Cells[0][14]="WRITE";
   tab_toke->Cells[0][15]="READ";
   tab_toke->Cells[0][16]=">";
   tab_toke->Cells[0][17]="<";
   tab_toke->Cells[0][18]=">=";
   tab_toke->Cells[0][19]="<=";
   tab_toke->Cells[0][20]=":=";
   tab_toke->Cells[0][21]="NOT";
   tab_toke->Cells[0][22]="OR";
   tab_toke->Cells[0][23]="AND";
   tab_toke->Cells[0][24]="^";
   tab_toke->Cells[0][25]="+";
   tab_toke->Cells[0][26]="-";
   tab_toke->Cells[0][27]="/";
   tab_toke->Cells[0][28]="*";
   tab_toke->Cells[1][1]="PALAVRA RESERVADA";
   tab_toke->Cells[1][2]="PALAVRA RESERVADA";
   tab_toke->Cells[1][3]="PALAVRA RESERVADA";
   tab_toke->Cells[1][4]="PALAVRA RESERVADA";
   tab_toke->Cells[1][5]="PALAVRA RESERVADA";
   tab_toke->Cells[1][6]="PALAVRA RESERVADA";
   tab_toke->Cells[1][7]="PALAVRA RESERVADA";
   tab_toke->Cells[1][8]="PALAVRA RESERVADA";
   tab_toke->Cells[1][9]="PALAVRA RESERVADA";
   tab_toke->Cells[1][10]="PALAVRA RESERVADA";
   tab_toke->Cells[1][11]="PALAVRA RESERVADA";
   tab_toke->Cells[1][12]="PALAVRA RESERVADA";
   tab_toke->Cells[1][13]="PALAVRA RESERVADA";
   tab_toke->Cells[1][14]="PALAVRA RESERVADA";
   tab_toke->Cells[1][15]="PALAVRA RESERVADA";
   tab_toke->Cells[1][16]="OPERADOR RELACIONAL";
   tab_toke->Cells[1][17]="OPERADOR RELACIONAL";
   tab_toke->Cells[1][18]="OPERADOR RELACIONAL";
   tab_toke->Cells[1][19]="OPERADOR RELACIONAL";
   tab_toke->Cells[1][20]="OPERADOR DE ATRIBUIÇÃO";
   tab_toke->Cells[1][21]="OPERADOR LÓGICO";
   tab_toke->Cells[1][22]="OPERADOR LÓGICO";
   tab_toke->Cells[1][23]="OPERADOR LÓGICO";
   tab_toke->Cells[1][24]="OPERADOR MATEMÁTICO";
   tab_toke->Cells[1][25]="OPERADOR MATEMÁTICO";
   tab_toke->Cells[1][26]="OPERADOR MATEMÁTICO";
   tab_toke->Cells[1][27]="OPERADOR MATEMÁTICO";
   tab_toke->Cells[1][28]="OPERADOR MATEMÁTICO";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::alternarClick(TObject *Sender)
{
   if (editor->Visible == true) {
      editor->Visible=false;
      tab_toke->Visible=true;
      alternar->Caption="Editor";
      btok1->Visible=true;
      btok2->Visible=true;
      palavras->Visible=true;
   }
   else {
      tab_toke->Visible=false;
      editor->Visible=true;
      alternar->Caption="Tokes";
      btok1->Visible=false;
      btok2->Visible=false;
      palavras->Visible=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btok1Click(TObject *Sender)
{
   tab_toke->RowCount++;   
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btok2Click(TObject *Sender)
{
   tab_toke->RowCount--;   
}
//---------------------------------------------------------------------------

