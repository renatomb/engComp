//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
   TLabel *Label1;
   TEdit *frase;
   TLabel *Label2;
   TRadioGroup *radio;
   TRadioButton *um;
   TRadioButton *dois;
   TRadioButton *tres;
   TRadioButton *quatro;
   TBitBtn *BitBtn1;
   TStringGrid *terminais;
   TStringGrid *token;
   void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   int i, j, k, erro;
   __fastcall TForm1(TComponent* Owner);
   bool s_exemplo () {
      if (token->Cells[0][k] == 'a') {
         k++;
         return true;
      }
      else {
         if (token->Cells[0][k] == '[') {
            k++;
            if (!l_exemplo()) { return false; }
            else {
               if (token->Cells[0][k] == ']') {
                  k++;
                  return true;
               }
               else { return false; }
            }
         }
         else { return false; }
      }
   }
   bool l_exemplo () {
      int volta;
      volta=k;
      if (s_exemplo()) {
         if (token->Cells[0][k] == ';') {
            k++;
            if (l_exemplo()) { return true; }
            else {
               k=volta;
               return false;
            }
         }
         else {
            k=volta;
            if (s_exemplo()) { return true; }
            else {
               k=volta;
               return false;
            }
         }
      }
      else {
         k=volta;
         return false;
      }
   }
   bool s_ex1 () {
      if (t_ex1()) {
         if (salfa_ex1()) { return true; }
      }
      return false;
   }
   bool salfa_ex1 () {
      int volta;
      volta=k;
      if (token->Cells[0][k] == '+') {
         k++;
         if (t_ex1()) {
            if (salfa_ex1()) { return true; }
         }
         return false;
      }
      else { return true; }
   }
   bool t_ex1 () {
      int volta;
      volta=k;
      if (f_ex1()) {
         if ((token->Cells[0][k] == '*')) {
            k++;
            if (t_ex1()) { return true; }
            else { return false; }
         }
         return true;
      }
      else {
         k=volta;
         return false;
      }
   }
   bool f_ex1() {
      int volta;
      volta=k;
      if (token->Cells[0][k] == 'a') {
         k++;
         return true;
      }
      else {
         if (token->Cells[0][k] == '(') {
            k++;
            if (s_ex1()) {
               if (token->Cells[0][k] == ')') {
                  k++;
                  return true;
               }
            }
         }
      }
      k=volta;
      return false;
   }
   bool e_ex2() {
      if (t_ex2()) {
         if (ealfa_ex2()) { return true; }
      }
      return false;
   }
   bool ealfa_ex2() {
      if (token->Cells[0][k] == 'v') {
         k++;
         if (t_ex2()){
            if (ealfa_ex2()) { return true; }
            else { return false; }
         }
         else { return false; }
      }
      else { return true; }
   }
   bool t_ex2() {
      if (f_ex2()) {
         if (talfa_ex2()) { return true; }
      }
      return false;
   }
   bool talfa_ex2() {
      if (token->Cells[0][k] == '&') {
         k++;
         if (f_ex2()) {
            if (talfa_ex2()) { return true; }
            else { return false; }
         }
         else { return false; }
      }
      else { return true; }
   }
   bool f_ex2() {
      if (token->Cells[0][k].LowerCase() == "not ") {
         k++;
         if (f_ex2()) { return true; }
         else { return false; }
      }
      else {
         if (token->Cells[0][k] == 'd') {
            k++;
            return true;
         }
         else { return false; }
      }
   }
   bool s_ex3() {
      if (token->Cells[0][k].LowerCase() == "not ") {
         k++;
         if (s_ex3()) {
            if (salfa_ex3()) { return true; }
            else { return false; }
         }
         else { return false; }
      }
      else {
         if (token->Cells[0][k] == '(') {
            k++;
            if (s_ex3()) {
               if (token->Cells[0][k] == ')') {
                  k++;
                  if (salfa_ex3()) { return true; }
                  else { return false; }
               }
               else { return false; }
            }
            else { return false; }
         }
         if (token->Cells[0][k] == 'p') {
            k++;
            if (salfa_ex3()) { return true; }
            else { return false; }
         }
         if (token->Cells[0][k] == 'q') {
            k++;
            if (salfa_ex3()) { return true; }
            else { return false; }
         }
         return false;
      }
   }
   bool salfa_ex3() {
      if (token->Cells[0][k].LowerCase() == "=>") {
         k++;
         if (s_ex3()) {
            if (salfa_ex3()) { return true; }
            else { return false; }
         }
         else { return false; }
      }
      else { return true; }
   }
   void laco_teste() {
      for (int r=1;r<=frase->Text.Length();r++) {
         erro=1;
         int compfrase;
         compfrase=frase->Text.Length();
         for (i=0;i<terminais->RowCount;i++) {
            int compterminal;
            compterminal=terminais->Cells[0][i].Length();
            if (frase->Text.SubString(r,compterminal).LowerCase() == terminais->Cells[0][i]) {
               token->Cells[0][j]=frase->Text.SubString(r,compterminal);
               token->RowCount++;
               r+=compterminal-1;
               erro=0;
               j++;
            }
         }
         if ((erro == 1) && (r <= frase->Text.Length())) {
            break;
         }
      }
      if (erro == 1) {
         ShowMessage("Não-terminal desconhecido...");
      }
      else {
         k=0;
         if ((um->Checked && s_exemplo()) || (dois->Checked && s_ex1()) || (tres->Checked && e_ex2()) || (quatro->Checked && s_ex3())) {
            if (k >= j) {
               ShowMessage("Compilação correta");
            }
            else {
               ShowMessage("Compilação incompleta");
            }
         }
         else {
            ShowMessage("Erro de sintaxe");
         }
      }
   }
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
