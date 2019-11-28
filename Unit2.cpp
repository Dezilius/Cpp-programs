//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Unit3"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
     Form2->Hide();
     Form1->Show();
     Form1->Image1->Visible = false;
     Form1->Image2->Visible = false;
     Form1->Image3->Visible = false;
     Form1->Image4->Visible = false;
     Form1->Image5->Visible = false;
     Form1->Image6->Visible = false;
     Form1->Image7->Visible = false;
     Form1->Image8->Visible = false;
     Form1->Image9->Visible = false;
     Form1->Image10->Visible = false;
     Form1->Image11->Visible = false;
     Form1->Image12->Visible = false;
     Form1->Image13->Visible = false;
     Form1->Image14->Visible = false;
     Form1->Image15->Visible = false;
     Form1->Image16->Visible = false;
     Form1->Image17->Visible = false;
     Form1->Image18->Visible = false;
     Form1->Image19->Visible = false;
     Form1->Image20->Visible = false;
     Form1->ball->Visible = false;
     Form1->paddle->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn3Click(TObject *Sender)
{
     Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::BitBtn2Click(TObject *Sender)
{
     Frame3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
     Frame3->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Frame31Button1Click(TObject *Sender)
{
  Frame3->Hide();
}
//---------------------------------------------------------------------------

