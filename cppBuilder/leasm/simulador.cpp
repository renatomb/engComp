//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "simulador.h"
#include "funrmb.h"
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



void __fastcall TForm1::Abrir1Click(TObject *Sender)
{
   OpenDialog1->DefaultExt = "ASM";
   OpenDialog1->FileName = "*.asm";
   if (OpenDialog1->Execute())
   {
      Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
   }
   for (int i=0; i<=Memo1->Lines->Count; i++){
      Memo1->Lines->Strings[i]=alltrim(Memo1->Lines->Strings[i].Trim());
   }
   linha->Text="0";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   AnsiString linh;
   int l, con=0;
   l=StrToInt(linha->Text);
   linh=Memo1->Lines->Strings[l];
   //Contagem de espacos
   for (int i=1;i<=linh.Length();i++){
      if (linh[i] == 32) {
         con++;
      }
   }
   l++;
   linha->Text=StrToInt(l);
   conta->Text=IntToStr(con);
   AnsiString alfa;
   for (int i=1; i<=(con+1); i++) {
      int ps;
      ps=posspace(linh)+1;
      alfa=nextspace(linh);
      ShowMessage(alfa);
      linh=linh.SubString(ps,linh.Length()-ps);
   }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Gravar1Click(TObject *Sender)
{
  SaveDialog1->DefaultExt = "ASM";
  SaveDialog1->FileName = "*.asm";
  if (SaveDialog1->Execute())
  {
   Memo1->Lines->SaveToFile(SaveDialog1->FileName);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
{
  Form1->WindowState=wsMaximized;
  StatusBar1->Panels->Items[3]->Text = Date();
  StatusBar1->Panels->Items[4]->Text = Time();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   StatusBar1->Panels->Items[3]->Text = " "+Date();
   StatusBar1->Panels->Items[4]->Text = Time();
}
//---------------------------------------------------------------------------

