//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
   TDBGrid *DBGrid1;
   TLabel *Label1;
   TDataSource *dsconsulta;
   TTable *tbconsulta;
   TDatabase *dbconsulta;
   TButton *Button1;
   TLabel *Label2;
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall Button1Click(TObject *Sender);
   void __fastcall Label2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
