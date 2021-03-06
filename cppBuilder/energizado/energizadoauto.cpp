//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "energizadoauto.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define LPT1 0x378
//Envia um byte para a porta 
void outportb(short int EndPorta, unsigned char ByteValor)
{
    _DX = EndPorta; 
    _AL = ByteValor; 
    __emit__( 0xEE ); 
}

//--------------------------------------------------------------------------------------
//Recebe um byte da porta
unsigned char inportb(short int EndPorta)
{
    _DX = EndPorta; 
    __emit__ (0xEC); 
    return(_AL); 
} 


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//Envia sinal para a Porta Paralela LPT1:
    unsigned char Valor1=255; //Em bin�rio: 10000000
    outportb(LPT1, Valor1); // Envia para a Porta LPT1

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//Envia sinal para a Porta Paralela LPT1:
    unsigned char Valor1=0; //Em bin�rio: 10000000
    outportb(LPT1, Valor1); // Envia para a Porta LPT1        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
int Byte;
    Byte = inportb(0x379);    //Ler um byte da Porta Paralela
    if(Byte!=120)
    {
      Label2->Visible=true;
      Label1->Visible=false;
      novo=1;
    }
    else
    {
      Label1->Visible=true;
      Label2->Visible=false;
      novo=0;
    }
    if (novo != ultimo) {
      ultimo=novo;
      if(novo){
         SMTP->PostMessageA->Subject="Aviso";
         SMTP->PostMessageA->Body->Text="Nivel eletrico voltou ao normal.";
         if (SMTP->Connected){
            SMTP->SendMail();
         }
         else {
            SMTP->Connect();
         }
         qinsere->SQL->Text="insert into eventos values (now(),'Reestabelecimento da energia.');";
         qinsere->ExecSQL();
      }
      else {
         SMTP->PostMessageA->Subject="Alerta";
         SMTP->PostMessageA->Body->Text="Ocorreu um problema eletrico.";
         if (SMTP->Connected){
            SMTP->SendMail();
         }
         else {
            SMTP->Connect();
         }
         qinsere->SQL->Text="insert into eventos values (now(),'Interrupcao na energia.');";
         qinsere->ExecSQL();
      }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   novo=1;
   ultimo=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SMTPConnect(TObject *Sender)
{
   conec->Brush->Color=clLime;
   SMTP->SendMail();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SMTPDisconnect(TObject *Sender)
{
   conec->Brush->Color=clWhite;
   env->Brush->Color=clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SMTPSendStart(TObject *Sender)
{
   env->Brush->Color=clYellow;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SMTPSuccess(TObject *Sender)
{
   env->Brush->Color=clLime;
   SMTP->Disconnect();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SMTPFailure(TObject *Sender)
{
   env->Brush->Color=clRed;
   SMTP->Disconnect();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SMTPConnectionFailed(TObject *Sender)
{
   conec->Brush->Color=clRed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
   Form2->Show();   
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label6Click(TObject *Sender)
{
   Form3->ShowModal();   
}
//---------------------------------------------------------------------------

