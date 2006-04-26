//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
   TMemo *editor;
   TSpeedButton *botao_abrir;
   TOpenDialog *abrir;
   TSaveDialog *salvar;
   TSpeedButton *botao_salvar;
   TSpeedButton *SpeedButton3;
   TSpeedButton *SpeedButton4;
   TBitBtn *botao_processar;
   TStringGrid *tab_toke;
   TBitBtn *alternar;
   TButton *btok1;
   TButton *btok2;
   TStringGrid *palavras;
   void __fastcall botao_abrirClick(TObject *Sender);
   void __fastcall botao_salvarClick(TObject *Sender);
   void __fastcall botao_processarClick(TObject *Sender);
   void __fastcall SpeedButton3Click(TObject *Sender);
   void __fastcall SpeedButton4Click(TObject *Sender);
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall alternarClick(TObject *Sender);
   void __fastcall btok1Click(TObject *Sender);
   void __fastcall btok2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
//Variaveis publicas:
   bool flag_espaco;
   bool flag_comentario;
   bool flag_string;
   __fastcall TForm1(TComponent* Owner);
//Funcoes criadas:
   bool removeletra (int lin, int col) {
      AnsiString linha,retorno;
      linha=editor->Lines->Strings[lin];
      for(int k=1;k<=linha.Length();k++){
         if (k != col){
            retorno=retorno+linha[k];
         }
      }
      editor->Lines->Strings[lin]=retorno;
      return true;
   }
   bool adiciona_palavra (AnsiString palavra, int pos) {
      if (palavra.Length() > 0) {
         int prox_posicao;
         AnsiString tipo;
         prox_posicao=palavras->RowCount-1;
         palavras->RowCount++;
         bool constante=true,busca=true;
         for (int n=1;n<=palavra.Length();n++){
            int le=palavra[n];
            if (le < 48 || le > 57) {
               constante=false;
               busca=true;
            }
            if (le == 34) {
               tipo="STRING";
               busca=false;
               break;
            }
         }
         if (constante) {
            tipo="CONSTANTE";
         }
         else {
            if (busca) {
               tipo="VARIÁVEL";
               for (int r=1;r<tab_toke->RowCount;r++) {
                  if (palavra == tab_toke->Cells[0][r]) {
                     tipo=tab_toke->Cells[1][r];
                  }
               }
            }
         }
         palavras->Cells[0][prox_posicao]=palavra;
         palavras->Cells[1][prox_posicao]=tipo;
         palavras->Cells[2][prox_posicao]=pos+1;
      }
   }
   void limpa_arquivo(){
      for(int i=0;i<editor->Lines->Count;i++) {
         int tam_linha;
         tam_linha=editor->Lines->Strings[i].Length();
         if (tam_linha > 0) {
            flag_espaco=true;
            for (int j=1;j<=tam_linha;j++){
               int letra=editor->Lines->Strings[i][j];
               if (!flag_string && !flag_comentario && !flag_espaco) {
                  if (letra == 32) { // 32 = Espaco em branco ASCII;
                     flag_espaco=true;
                  }
                  if (letra == 123) { // 123 = Abre chaves ASCII;
                     flag_comentario=true;
                     removeletra(i,j);
                     j--; tam_linha--;
                  }
                  if (letra == 34) { // 34 = Aspas duplas ASCII;
                     flag_string=true;
                  }
                  if (letra == 9) { // 9 = TAB ASCII;
                     removeletra(i,j);
                     j--; tam_linha--;
                  }
               }
               else {
                  if (flag_string) {
                     if (letra == 34) { // 34 = Aspas duplas ASCII;
                        flag_string=false;
                     }
                  }
                  if (flag_comentario) {
                     if (letra == 125) { // 125 = Fecha chaves ASCII;
                        flag_comentario=false;
                     }
                     removeletra(i,j);
                     j--; tam_linha--;
                  }
                  if (flag_espaco) {
                     if (letra == 32) {
                        removeletra(i,j);
                        j--; tam_linha--;
                     }
                     else {
                        if (letra == 9) { // 9 = TAB ASCII;
                           removeletra(i,j);
                           j--; tam_linha--;
                        }
                        else {
                           if (letra == 123) { // 123 = Abre chaves ASCII;
                              flag_comentario=true;
                              removeletra(i,j);
                              j--; tam_linha--;
                           }
                           if (letra == 34) { // 34 = Aspas duplas ASCII;
                              flag_string=true;
                           }
                           flag_espaco=false;
                        }
                     }
                  }
               }
            }
         }
         if (editor->Lines->Strings[i].Length() == 0) {
            editor->Lines->Delete(i);
            i--;
         }
      }
   }
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
