//---------------------------------------------------------------------------

#ifndef energizadoautoH
#define energizadoautoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <NMsmtp.hpp>
#include <Psock.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button1;
        TButton *Button2;
        TTimer *Timer1;
   TNMSMTP *SMTP;
   TLabel *Label3;
   TShape *conec;
   TLabel *Label4;
   TShape *env;
   TLabel *Label5;
   TDataSource *dsinsere;
   TDatabase *Database1;
   TQuery *qinsere;
   TButton *Button3;
   TLabel *Label6;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall SMTPConnect(TObject *Sender);
   void __fastcall SMTPDisconnect(TObject *Sender);
   void __fastcall SMTPSendStart(TObject *Sender);
   void __fastcall SMTPSuccess(TObject *Sender);
   void __fastcall SMTPFailure(TObject *Sender);
   void __fastcall SMTPConnectionFailed(TObject *Sender);
   void __fastcall Button3Click(TObject *Sender);
   void __fastcall Label6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
      int ultimo,novo;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
