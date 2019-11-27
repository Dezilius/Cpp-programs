//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <fstream>
#include <iostream>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrame3 *Frame3;

std::vector <TLabel*> labels;
//---------------------------------------------------------------------------
__fastcall TFrame3::TFrame3(TComponent* Owner)
    : TFrame(Owner)
{
/*
      std::ifstream file;
      String name[10], temp;
      char x[20];
      int points[10];
      int i = 0;
      file.open("Scores.txt");

      if (!file)
      {
         //std::cout << "Error opening Scores file!";
      }

      while (!file.eof())
      {
            file >> x;
            name[i] = x;
            file >> x;
            temp = x;
            points[i] = atoi(x);
            i++;
      }

      file.close();

    for (int i = 0; i < 10; i++)
    {
        TLabel *label = new TLabel(this);
        label->Parent = this;

        label->Caption = name[i] + " " + points[i];
        label->Top = 20 + i * 20;
        label->Left = 20;

        labels.push_back(label);
    }   */
}
//---------------------------------------------------------------------------

void __fastcall TFrame3::Button1Click(TObject *Sender)
{
     Frame3->Hide();
}
//---------------------------------------------------------------------------
