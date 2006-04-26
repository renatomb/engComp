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
   TStringGrid *slr;
        TStringGrid *naoterm;
        TLabel *Label1;
   TButton *nt_mais;
   TButton *nt_menos;
   TStringGrid *regras;
   TLabel *Label2;
   TButton *rg_mais;
   TButton *rg_menos;
   TStringGrid *transicoes;
   TButton *slr_mais;
   TButton *slr_menos;
   TStringGrid *status;
   TButton *inicia;
   TEdit *exp;
   TLabel *Label3;
   TLabel *Label4;
        void __fastcall nt_maisClick(TObject *Sender);
   void __fastcall nt_menosClick(TObject *Sender);
   void __fastcall naotermSetEditText(TObject *Sender, int ACol, int ARow,
          const AnsiString Value);
   void __fastcall rg_maisClick(TObject *Sender);
   void __fastcall rg_menosClick(TObject *Sender);
   void __fastcall slr_maisClick(TObject *Sender);
   void __fastcall slr_menosClick(TObject *Sender);
   void __fastcall regrasSetEditText(TObject *Sender, int ACol, int ARow,
          const AnsiString Value);
   void __fastcall iniciaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
      AnsiString pilha,entrada,acao;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
