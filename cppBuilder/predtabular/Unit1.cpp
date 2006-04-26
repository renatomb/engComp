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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   if (qtok->Text.ToInt() > 0) {
      token->RowCount=qtok->Text.ToInt();
   }
   else {
      ShowMessage("Quantidade mínima deve ser 1!");
   }
   if (qfun->Text.ToInt() > 0) {
      func->RowCount=qfun->Text.ToInt();
   }
   else {
      ShowMessage("Quantidade mínima deve ser 1!");
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   for (int i=0;i<token->RowCount;i++){
      token->Cells[0][i]="";
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
   for (int i=0;i<func->RowCount;i++){
      func->Cells[0][i]="";
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
   tabela->RowCount=func->RowCount+1;
   tabela->ColCount=token->RowCount+2;
   tabela->FixedCols=1;
   tabela->FixedRows=1;
   for (int i=0;i<=tabela->RowCount;i++){
      for (int j=0;j<tabela->ColCount;j++) {
         if ((j == 0) && (i > 0)) {
            tabela->Cells[j][i]=func->Cells[0][i-1];
         }
         if ((i == 0) && (j > 0)) {
            tabela->Cells[j][i]=token->Cells[0][j-1];
         }
      }
   }
   tabela->Cells[tabela->ColCount-1][0]="$";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
   bool continua;
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
//      ShowMessage("Loop");
      AnsiString tvp,fvp,tva;
      proc->Cells[0][i]=pilha;
      proc->Cells[1][i]=analise;
      if (pilha == "$") {
         tvp="$";
         if (analise == "$") {
            proc->Cells[2][i]="Sentença Aceita!";
            continua=false;
            break;
         }
      }
      else {
         tva="";
         for (int j=0;j<token->RowCount;j++){ // Determinacao do token da vez na pilha (tvp) e token da vez na analise (tva)
            int tam_token,tam_pilha,tam_analise;
            tam_token=token->Cells[0][j].Length();
            tam_pilha=pilha.Length();
            tam_analise=analise.Length();
            if (pilha.SubString(tam_pilha-tam_token+1,tam_token) == token->Cells[0][j]) {
               tvp=token->Cells[0][j];
               fvp="";
//               ShowMessage("Achei um token!!!"+tvp);
            }
            if (analise.SubString(1,tam_token) == token->Cells[0][j]) {
               tva=token->Cells[0][j];
//               ShowMessage("Achei um token na analise!!!"+tva);
            }
         }
         if (tva == "") { tva=analise; }
         for (int j=0;j<func->RowCount;j++){ // Determinacao da funcao da vez na pilha (fvp)
            int tam_func,tam_pilha;
            tam_func=func->Cells[0][j].Length();
            tam_pilha=pilha.Length();
            if (pilha.SubString(tam_pilha-tam_func+1,tam_func) == func->Cells[0][j]) {
               tvp="";
               fvp=func->Cells[0][j];
//               ShowMessage("Achei uma funcao!!!"+fvp);
            }
         }
      }
      if (tvp == tva) {
         proc->Cells[2][i]="Desempilha e lê símbolo.";
         pilha=pilha.SubString(1,pilha.Length()-tvp.Length());
         analise=analise.SubString(tva.Length()+1,analise.Length()-tva.Length());
      }
      if (fvp != "") {
         int r,w;
         for (r=1;r<tabela->RowCount;r++) {
            if (tabela->Cells[0][r] == fvp) {
               break;
            }
         }
         for (w=1;w<=tabela->ColCount;w++) {
//            ShowMessage("Busca por: "+tva);
            if (tabela->Cells[w][0] == tva) {
               break;
            }
         }
         AnsiString regradavez;
         regradavez=tabela->Cells[w][r];
         if (regradavez == "") {
            proc->Cells[2][i]="Sentença RECUSADA!";
            continua=false;
            break;
         }
         else {
            pilha=pilha.SubString(1,pilha.Length()-fvp.Length());
            proc->Cells[2][i]=fvp+"=>"+regradavez;
            if (regradavez != vazio->Text) {
               while (regradavez != "") {
                  AnsiString localizado;
                  localizado="";
                  for(int s=0;s<token->RowCount;s++){ //Busca por tokens
                     int tam_token,tam_regra;
                     tam_token=token->Cells[0][s].Length();
                     tam_regra=regradavez.Length();
                     if (regradavez.SubString(tam_regra-tam_token+1,tam_token) == token->Cells[0][s]) {
                        localizado=token->Cells[0][s];
                     }
                  }
                  for(int s=0;s<func->RowCount;s++){ //Busca por funcoes
                     int tam_func,tam_regra;
                     tam_func=func->Cells[0][s].Length();
                     tam_regra=regradavez.Length();
                     if (regradavez.SubString(tam_regra-tam_func+1,tam_func) == func->Cells[0][s]) {
                        localizado=func->Cells[0][s];
                     }
                  }
                  if (localizado == "") {
                     continua=false;
                     break;
                  }
                  else {
                     regradavez=regradavez.SubString(1,regradavez.Length()-localizado.Length());
                     pilha=pilha+localizado;
                  }
               }
            }
         }
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::tokenDblClick(TObject *Sender)
{
   exp->Text=exp->Text+token->Cells[0][token->Row];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::funcDblClick(TObject *Sender)
{
   msgp->Caption="Inicio da pilha: "+func->Cells[0][func->Row];
   pilha="$"+func->Cells[0][func->Row];
}
//---------------------------------------------------------------------------
