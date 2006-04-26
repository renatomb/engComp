//---------------------------------------------------------------------------

#ifndef simuladorH
#define simuladorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Arquivo1;
        TMenuItem *Abrir1;
        TOpenDialog *OpenDialog1;
        TMemo *Memo1;
        TButton *Button1;
        TEdit *Edit1;
        TMenuItem *Gravar1;
        TSaveDialog *SaveDialog1;
        TStatusBar *StatusBar1;
        TTimer *Timer1;
        TEdit *Edit2;
        TEdit *Edit3;
   TEdit *linha;
   TEdit *conta;
        void __fastcall Abrir1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Gravar1Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
