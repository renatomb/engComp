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

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
   j=0;
   token->RowCount=0;
   // Exemplo de alax;
   if (um->Checked) {
      terminais->RowCount=4;
      terminais->Cells[0][0]='a';
      terminais->Cells[0][1]='[';
      terminais->Cells[0][2]=']';
      terminais->Cells[0][3]=';';
   }
   // Primeiro exercicio;
   if (dois->Checked) {
      terminais->RowCount=5;
      terminais->Cells[0][0]='a';
      terminais->Cells[0][1]='+';
      terminais->Cells[0][2]='*';
      terminais->Cells[0][3]='(';
      terminais->Cells[0][4]=')';
   }
   if (tres->Checked) {
      terminais->RowCount=4;
      terminais->Cells[0][0]='d';
      terminais->Cells[0][1]="not ";
      terminais->Cells[0][2]='v';
      terminais->Cells[0][3]='&';
   }
   if (quatro->Checked) {
      terminais->RowCount=6;
      terminais->Cells[0][0]="=>";
      terminais->Cells[0][1]="not ";
      terminais->Cells[0][2]='(';
      terminais->Cells[0][3]=')';
      terminais->Cells[0][4]='p';
      terminais->Cells[0][5]='q';
   }
   laco_teste();
}
//---------------------------------------------------------------------------


