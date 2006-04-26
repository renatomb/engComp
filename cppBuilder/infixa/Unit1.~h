//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
   TLabel *Label1;
   TEdit *infixa;
   TLabel *Label2;
   TLabel *Label3;
   TCheckBox *ver_pilha;
   TButton *OK;
   TEdit *prefixa;
   TEdit *posfixa;
   TEdit *pilha_pos;
   TEdit *pilha_pre;
   TLabel *lab1;
   TLabel *lab2;
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall ver_pilhaClick(TObject *Sender);
   void __fastcall OKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TForm1(TComponent* Owner);
   void erro(AnsiString mensagem){
      ShowMessage("ERRO!!!\n"+mensagem);
      prefixa->Text="";
      posfixa->Text="";
   }
   AnsiString descarrega_pos(int pos) {
      AnsiString retorno,caractere;
      for (int i=pilha_pos->Text.Length();i>=pos;i--){
         caractere=pilha_pos->Text.SubString(i,1);
         if (caractere != "(") {
            retorno=retorno+caractere;
         }
      }
      if (pos > 1) {
         pilha_pos->Text=pilha_pos->Text.SubString(1,pos-1);
      }
      else {
         pilha_pos->Text="";
      }
      return retorno;
   }
   int localiza_pos(AnsiString operador) {
      for (int i=pilha_pos->Text.Length();i>=1;i--){
         if (pilha_pos->Text.SubString(i,1) == operador) {
            return i;
         }
      }
      return 1;
   }
   AnsiString operador_pos(AnsiString operador) {
      AnsiString retorno,cabeca;
      cabeca=pilha_pos->Text.SubString(pilha_pos->Text.Length(),1);
      if (operador == "+" || operador == "-") {
         while (!(cabeca == "" || cabeca == "(")) {
            retorno=retorno+descarrega_pos(pilha_pos->Text.Length());
            cabeca=pilha_pos->Text.SubString(pilha_pos->Text.Length(),1);
         }
      }
      else {
         if (operador == "*" || operador == "/") {
            while (!(cabeca == "" || cabeca == "(" || cabeca == "+" || cabeca == "-")) {
               retorno=retorno+descarrega_pos(pilha_pos->Text.Length());
               cabeca=pilha_pos->Text.SubString(pilha_pos->Text.Length(),1);
            }
         }
         else {
            if (operador == "^") {
               while (!(cabeca == "" || cabeca == "(" || cabeca == "+" || cabeca == "-") || cabeca == "*" || cabeca == "/") {
                  retorno=retorno+descarrega_pos(pilha_pos->Text.Length());
                  cabeca=pilha_pos->Text.SubString(pilha_pos->Text.Length(),1);
               }
            }
         }
      }
      pilha_pos->Text=pilha_pos->Text+operador;
      return retorno;
   }
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
