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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   Form1->Height=245;
   pilha_pre->Visible=false;
   pilha_pos->Visible=false;
   ver_pilha->Checked=false;
   lab1->Visible=false;
   lab2->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ver_pilhaClick(TObject *Sender)
{
   if (ver_pilha->Checked) {
      Form1->Height=350;
      pilha_pre->Visible=true;
      pilha_pos->Visible=true;
      lab1->Visible=true;
      lab2->Visible=true;
   }
   else {
      Form1->Height=245;
      pilha_pre->Visible=false;
      pilha_pos->Visible=false;
      lab1->Visible=false;
      lab2->Visible=false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OKClick(TObject *Sender)
{
   prefixa->Text="";
   posfixa->Text="";
   pilha_pre->Text="";
   pilha_pos->Text="";
   int parent=0;
   bool pode_operador=false, pode_operando=true, pode_parent=true;
   for(int i=1;i<=infixa->Text.Length();i++){
      if (infixa->Text[i] == 40) { // Parenteses abrindo;
         if (!pode_parent) {
            erro("Parenteses abrindo na posi��o: "+AnsiString(i));
         }
         else {
            pilha_pos->Text=pilha_pos->Text+"(";
            pilha_pre->Text=pilha_pre->Text+"(";
            parent++;
            pode_parent=true;
            pode_operando=true;
            pode_operador=false;
         }
      }
      if (infixa->Text[i] == 41) { // Parenteses fechando
         if (parent <= 0) {
            erro("Parenteses fechando na posi��o: "+AnsiString(i));
         }
         else {
            posfixa->Text=posfixa->Text+descarrega_pos(localiza_pos("("));
//            prefixa->Text=descarrega_pre(localiza_pre("("));
            parent--;
            pode_parent=false;
            pode_operando=false;
            pode_operador=true;
         }
      }
      if ((infixa->Text[i] == 43) || (infixa->Text[i] == 45) || (infixa->Text[i] == 42) || (infixa->Text[i] == 47) || (infixa->Text[i] == 94)) {
         if (!pode_operador) {
            erro("Operador posicionado inadequadamente na posi��o: "+AnsiString(i));
         }
         else {
//         prefixa->Text=operador_pre(infixa->Text.SubString(i,1));
            posfixa->Text=posfixa->Text+operador_pos(infixa->Text.SubString(i,1));
            pode_operador=false;
            pode_operando=true;
            pode_parent=true;
         }
      }
      if ((infixa->Text[i] >= 65 && infixa->Text[i] <= 90) || (infixa->Text[i] >= 97 && infixa->Text[i] <= 122))  {
         if (!pode_operando) {
            erro("Operando posicionado inadequadamente na posi��o: "+AnsiString(i));
         }
         else {
            prefixa->Text=infixa->Text.SubString(i,1)+prefixa->Text;
            posfixa->Text=posfixa->Text+infixa->Text.SubString(i,1);
            pode_operador=true;
            pode_operando=false;
            pode_parent=false;
         }
      }
   }
   if (parent != 0) {
      erro("O n�mero de parenteses abrindo n�o � igual ao n�mero de parenteses fechando.\nVerifique a express�o.");
   }
   else {
//      prefixa->Text=descarrega_pre("c")+prefixa->Text;
      posfixa->Text=posfixa->Text+descarrega_pos(1);
   }
}
//---------------------------------------------------------------------------
