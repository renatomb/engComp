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

void __fastcall TForm1::defineClick(TObject *Sender)
{
   if (qtok->Text.ToInt() > 0) {
      regras->RowCount=qtok->Text.ToInt();
   }
   else {
      ShowMessage("Quantidade mínima deve ser 1!");
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::limpaClick(TObject *Sender)
{
   for (int i=0;i<regras->RowCount;i++){
      regras->Cells[0][i]="";
      regras->Cells[1][i]="";
   }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::validaClick(TObject *Sender)
{
   pilha="$";
   bool continua, bandeira=false;
   for(int i=0;i<proc->RowCount;i++){
      for (int j=0;j<proc->ColCount;j++) {
         proc->Cells[j][i]="";
      }
   }
   proc->Cells[0][0]="Pilha";
   proc->Cells[1][0]="Entrada";
   proc->Cells[2][0]="Ação";
   continua=true;
   analise=exp->Text+"$";
   for(int i=1;continua;i++){
      proc->RowCount=i+1;
      proc->Cells[0][i]=pilha;
      proc->Cells[1][i]=analise;
      if ((analise == "$") && (pilha == "$"+inicial)) {
         proc->Cells[2][i]="Sentença Aceita!";
         continua=false;
         break;
      }
      else {
         if (analise == "$") {
            bandeira=true;
         }
         AnsiString palavra;
         int y=2;
         bool reduziu=false;
         for (int h=pilha.Length()-1;h>=1;h=h-1) {
            palavra=pilha.SubString(y,h);
//            ShowMessage("Tentando: "+palavra);
            for (int r=0;r<regras->RowCount;r++) {
               if (palavra == regras->Cells[1][r]) {
                  proc->Cells[2][i]="Reduz: "+regras->Cells[0][r]+"=>"+regras->Cells[1][r];
                  pilha=pilha.SubString(1,pilha.Length()-regras->Cells[1][r].Length())+regras->Cells[0][r];
                  reduziu=true;
                  break;
               }
            }
            y++;
         }
         if (!reduziu) {
            if (bandeira) {
               proc->Cells[2][i]="Sentença recusada";
               continua=false;
            }
            else {
               AnsiString letra;
               letra=analise.SubString(1,1);
               analise=analise.SubString(2,analise.Length()-1);
               pilha=pilha+letra;
               proc->Cells[2][i]="Empilha: "+letra;
            }
         }
         else { bandeira=false; }
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::regrasDblClick(TObject *Sender)
{
   inicial=regras->Cells[0][regras->Row];
   msgp->Caption="Símbolo Inicial: "+inicial;
   pilha="$";
   valida->Enabled=true;
}
//---------------------------------------------------------------------------



