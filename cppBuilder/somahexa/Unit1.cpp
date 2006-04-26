//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "optab.h"
#include "funrmb.h"
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
   for(int i=0;i<61;i++){
      if (i==0) {
         g1->Cells={"Mnemonico","Opcode","Formato"};
      }
   }
}
//---------------------------------------------------------------------------
