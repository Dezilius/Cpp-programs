//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Unit4"
#pragma resource "*.dfm"
TForm1 *Form1;

int x, y, win, def_win, score;
int * xx = &x;
int * yy = &y;
String name;
const char* textconv;
vector <string> ScoresRead;

bool kolizja(TImage * ball, TImage * brick)
{    // Collision detection
     if       (ball->Left + ball->Width >= brick->Left - 2 &&
              ball->Left <= brick->Left + brick->Width + 2 &&
              ball->Top + ball->Height >= brick->Top - 2 &&
              ball->Top <= brick->Top + brick->Height + 2)
              {
              if (brick->Visible == true)
              {
              if (*yy <= 0 && *xx <= 0 && abs(ball->Left - (brick->Left + brick->Width)) <= abs(ball->Top - (brick->Top + brick->Height)))
              {*xx = -*xx;}// Vector x < 0, y < 0
              else if (*yy <= 0 && *xx <= 0 && abs(ball->Left - (brick->Left + brick->Width)) > abs(ball->Top - (brick->Top + brick->Height)))
              {*yy = -*yy;}// Vector x < 0, y < 0
              else if (*yy <= 0 && *xx > 0 && abs(brick->Left - (ball->Left + ball->Width)) <= abs(ball->Top - (brick->Top + brick->Height)))
              {*xx = -*xx;}// Vector x > 0, y < 0
              else if(*yy <= 0 && *xx > 0 && abs(brick->Left - (ball->Left + ball->Width)) > abs(ball->Top - (brick->Top + brick->Height)))
              {*yy = -*yy;}// Vector x > 0, y < 0
              else if (*yy > 0 && *xx > 0 && abs(brick->Left - (ball->Left + ball->Width)) > abs(brick->Top - (ball->Top + ball->Height)))
              {*yy = -*yy;}// Vector x > 0, y > 0
              else if (*yy > 0 && *xx > 0 && abs(brick->Left - (ball->Left + ball->Width)) <= abs(brick->Top - (ball->Top + ball->Height)))
              {*xx = -*xx;}// Vector x > 0, y > 0
              else if(*yy > 0 && *xx <= 0 && abs(ball->Left - (brick->Left + brick->Width)) > abs(brick->Top - (ball->Top + ball->Height)))
              {*yy = -*yy;}// Vector x < 0, y > 0
              else if(*yy > 0 && *xx <= 0 && abs(ball->Left - (brick->Left + brick->Width)) <= abs(brick->Top - (ball->Top + ball->Height)))
              {*xx = -*xx;}// Vector x < 0, y > 0
              }
              return true;
              }
     else return false;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
     // ball movement + score update
     ball->Left += x;
     ball->Top += y;
     Form1->Label1->Caption = score;

     // Ball bounce - vector based
     if (ball->Top - 5 <=  tlo->Top) y = -y;
     if (ball->Left - 5 <= tlo->Left) x = -x;
     if (ball->Left + ball->Width + 5 >= tlo->Width) x = -x;

     // loose / win
     if (ball->Top >= paddle->Top + paddle->Height + 10)
     {
      Timer_ball->Enabled = false;
      ball->Visible = false;
      Button1->Caption = "Przegrana! Jeszcze raz?";
      Button1->Visible = true;
     }
     else if (ball->Left > paddle->Left - ball->Width/2 &&
     ball->Left < paddle->Left + paddle->Width &&
     ball->Top + ball->Height > paddle->Top)
               {
                 if (y>0) y = -y;
               }
     if (win <= 0)
     {
      Timer_ball->Enabled = false;
      ball->Visible = false;
      Button1->Caption = "win! Jeszcze raz?";
      Button1->Visible = true;

      // Saving new scores and sort
      ofstream bestScore;
      bestScore.open ("Scores.txt", ios_base::app | ios_base::out);
      name = Frame4->Edit1->Text.c_str();
      bestScore << name.c_str();
      bestScore << "\n";
      bestScore << score + "\n";
      //bestScore <<
      bestScore.close();




      score = 0;
     }

     // Blok1
     if (kolizja(ball, Image1) && Image1->Visible == true)
     {Image1->Visible = false; win--;}
     // Blok2
     if (kolizja(ball, Image2) && Image2->Visible == true)
     {Image2->Visible = false; win--;}
     // Blok3
     if (kolizja(ball, Image3) && Image3->Visible == true)
     {Image3->Visible = false; win--;}
     // Blok4
     if (kolizja(ball, Image4) && Image4->Visible == true)
     {Image4->Visible = false; win--;}
     // Blok5
     if (kolizja(ball, Image5) && Image5->Visible == true)
     {Image5->Visible = false; win--;}
     // Blok6
     if (kolizja(ball, Image6) && Image6->Visible == true)
     {Image6->Visible = false; win--;}
     // Blok7
     if (kolizja(ball, Image7) && Image7->Visible == true)
     {Image7->Visible = false; win--;}
     // Blok8
     if (kolizja(ball, Image8) && Image8->Visible == true)
     {Image8->Visible = false; win--;}
     // Blok9
     if (kolizja(ball, Image9) && Image9->Visible == true)
     {Image9->Visible = false; win--;}
     // Blok10
     if (kolizja(ball, Image10) && Image10->Visible == true)
     {Image10->Visible = false; win--;}
     // Blok11
     if (kolizja(ball, Image11) && Image11->Visible == true)
     {Image11->Visible = false; win--;}
     // Blok12
     if (kolizja(ball, Image12) && Image12->Visible == true)
     {Image12->Visible = false; win--;}
     // Blok13
     if (kolizja(ball, Image13) && Image13->Visible == true)
     {Image13->Visible = false; win--;}
     // Blok14
     if (kolizja(ball, Image14) && Image14->Visible == true)
     {Image14->Visible = false; win--;}
     // Blok15
     if (kolizja(ball, Image15) && Image15->Visible == true)
     {Image15->Visible = false; win--;}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewoTimer(TObject *Sender)
{    // Paddle move left
     if (paddle->Left > 10) paddle->Left -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prawoTimer(TObject *Sender)
{    // Paddle move right
     if (paddle->Left + paddle ->Width < tlo->Width - 10) paddle->Left += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{     // Key pressed detection
      if (Key == VK_LEFT) lewo->Enabled = true;
      if (Key == VK_RIGHT) prawo->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{     // Key released detection
      if (Key == VK_LEFT) lewo->Enabled = false;
      if (Key == VK_RIGHT) prawo->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    // new game button
    Timer_ball->Enabled = false;
    Frame4->Visible = true;
    Button1->Visible = false;

     Image1->Visible = false;
     Image2->Visible = false;
     Image3->Visible = false;
     Image4->Visible = false;
     Image5->Visible = false;
     Image6->Visible = false;
     Image7->Visible = false;
     Image8->Visible = false;
     Image9->Visible = false;
     Image10->Visible = false;
     Image11->Visible = false;
     Image12->Visible = false;
     Image13->Visible = false;
     Image14->Visible = false;
     Image15->Visible = false;
     Image16->Visible = false;
     Image17->Visible = false;
     Image18->Visible = false;
     Image19->Visible = false;
     Image20->Visible = false;
     ball->Visible = false;
     paddle->Visible = false;
     /*
     ball->Left = 70;
     ball->Top = 70;

     Timer_ball->Enabled = true;
     win = def_win;
     Button1->Visible = false;

     ball->Visible = true;
     paddle->Visible = true;
     Image1->Visible = true;
     Image2->Visible = true;
     Image3->Visible = true;
     Image4->Visible = true;
     Image5->Visible = true;
     Image6->Visible = true;
     Image7->Visible = true;
     Image8->Visible = true;
     Image9->Visible = true;
     Image10->Visible = true;
     Image11->Visible = true;
     Image12->Visible = true;
     Image13->Visible = true;
     Image14->Visible = true;
     Image15->Visible = true;*/

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{   // On starting game
    Timer_ball->Enabled = false;
    Frame4->Visible = true;
    Frame4->ComboBox1->Items->Add("Easy");
    Frame4->ComboBox1->Items->Add("Medium");
    Frame4->ComboBox1->Items->Add("Hard");
    Frame4->ComboBox2->Items->Add("Small");
    Frame4->ComboBox2->Items->Add("Average");
    Frame4->ComboBox2->Items->Add("Big");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Frame4Button1Click(TObject *Sender)
{    // Go back from setting
     Form1->Hide();
     Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Frame4Button2Click(TObject *Sender)
{    // Starting new game, loading settings and setting up appropriate game
     if (Frame4->ComboBox1->Items->Strings[Frame4->ComboBox1->ItemIndex] != "" &&
         Frame4->ComboBox2->Items->Strings[Frame4->ComboBox2->ItemIndex] != "" &&
         Frame4->Edit1->Text != "")
         {
           if (Frame4->ComboBox1->Items->Strings[Frame4->ComboBox1->ItemIndex] == "Easy")
              x = -2, y = -2;
           else if (Frame4->ComboBox1->Items->Strings[Frame4->ComboBox1->ItemIndex] == "Medium")
                x = -6, y = -6;
           else if (Frame4->ComboBox1->Items->Strings[Frame4->ComboBox1->ItemIndex] == "Hard")
                x = -9, y = -9;

           if (Frame4->ComboBox2->Items->Strings[Frame4->ComboBox2->ItemIndex] == "Small")
              {win = 10; def_win = win;

                    Form1->ClientHeight = 750;
                    Form1->ClientWidth = 650;

                    Image1->Left = 50;
                    Image1->Top = 50;
                    Image2->Left = 110;
                    Image2->Top = 50;
                    Image3->Left = 170;
                    Image3->Top = 50;
                    Image4->Left = 230;
                    Image4->Top = 50;
                    Image5->Left = 40;
                    Image5->Top = 100;
                    Image6->Left = 100;
                    Image6->Top = 100;
                    Image7->Left = 160;
                    Image7->Top = 100;
                    Image8->Left = 220;
                    Image8->Top = 100;
                    Image9->Left = 50;
                    Image9->Top = 150;
                    Image10->Left = 50;
                    Image10->Top = 150;

                    Image1->Visible = true;
                    Image2->Visible = true;
                    Image3->Visible = true;
                    Image4->Visible = true;
                    Image5->Visible = true;
                    Image6->Visible = true;
                    Image7->Visible = true;
                    Image8->Visible = true;
                    Image9->Visible = true;
                    Image10->Visible = true;

              }
           else if (Frame4->ComboBox2->Items->Strings[Frame4->ComboBox2->ItemIndex] == "Average")
                {win = 15; def_win = win;

                    Form1->ClientHeight = 750;
                    Form1->ClientWidth = 650;

                    Image1->Left = 30;
                    Image1->Top = 50;
                    Image2->Left = 90;
                    Image2->Top = 50;
                    Image3->Left = 150;
                    Image3->Top = 50;
                    Image4->Left = 210;
                    Image4->Top = 50;
                    Image5->Left = 270;
                    Image5->Top = 50;
                    Image6->Left = 330;
                    Image6->Top = 50;
                    Image7->Left = 20;
                    Image7->Top = 110;
                    Image8->Left = 80;
                    Image8->Top = 110;
                    Image9->Left = 140;
                    Image9->Top = 110;
                    Image10->Left = 200;
                    Image10->Top = 110;
                    Image11->Left = 260;
                    Image11->Top = 110;
                    Image12->Left = 320;
                    Image12->Top = 110;
                    Image13->Left = 550;
                    Image13->Top = 100;
                    Image14->Left = 490;
                    Image14->Top = 160;
                    Image15->Left = 560;
                    Image15->Top = 160;

                    Image1->Visible = true;
                    Image2->Visible = true;
                    Image3->Visible = true;
                    Image4->Visible = true;
                    Image5->Visible = true;
                    Image6->Visible = true;
                    Image7->Visible = true;
                    Image8->Visible = true;
                    Image9->Visible = true;
                    Image10->Visible = true;
                    Image11->Visible = true;
                    Image12->Visible = true;
                    Image13->Visible = true;
                    Image14->Visible = true;
                    Image15->Visible = true;

                }
           else if (Frame4->ComboBox2->Items->Strings[Frame4->ComboBox2->ItemIndex] == "Big")
                {win = 20; def_win = win;

                    Form1->ClientHeight = 800;
                    Form1->ClientWidth = 800;

                    Image1->Left = 100;
                    Image1->Top = 200;
                    Image2->Left = 170;
                    Image2->Top = 200;
                    Image3->Left = 240;
                    Image3->Top = 200;
                    Image4->Left = 310;
                    Image4->Top = 200;
                    Image5->Left = 380;
                    Image5->Top = 200;
                    Image6->Left = 450;
                    Image6->Top = 200;
                    Image7->Left = 520;
                    Image7->Top = 250;
                    Image8->Left = 50;
                    Image8->Top = 250;
                    Image9->Left = 120;
                    Image9->Top = 250;
                    Image10->Left = 190;
                    Image10->Top = 250;
                    Image11->Left = 260;
                    Image11->Top = 250;
                    Image12->Left = 330;
                    Image12->Top = 250;
                    Image13->Left = 0;
                    Image13->Top = 300;
                    Image14->Left = 70;
                    Image14->Top = 300;
                    Image15->Left = 140;
                    Image15->Top = 300;
                    Image16->Left = 210;
                    Image16->Top = 300;
                    Image17->Left = 280;
                    Image17->Top = 300;
                    Image18->Left = 350;
                    Image18->Top = 300;
                    Image19->Left = 250;
                    Image19->Top = 350;
                    Image20->Left = 400;
                    Image20->Top = 350;

                    Image1->Visible = true;
                    Image2->Visible = true;
                    Image3->Visible = true;
                    Image4->Visible = true;
                    Image5->Visible = true;
                    Image6->Visible = true;
                    Image7->Visible = true;
                    Image8->Visible = true;
                    Image9->Visible = true;
                    Image10->Visible = true;
                    Image11->Visible = true;
                    Image12->Visible = true;
                    Image13->Visible = true;
                    Image14->Visible = true;
                    Image15->Visible = true;
                    Image16->Visible = true;
                    Image17->Visible = true;
                    Image18->Visible = true;
                    Image19->Visible = true;
                    Image20->Visible = true;


                }

                Timer_ball->Enabled = true;
                Frame4->Visible = false;
                ball->Visible = true;
                paddle->Visible = true;
                ball->Left = Form1->ClientHeight/2 -50;
                ball->Top = Form1->ClientWidth/2 -50;
                paddle->Left = Form1->ClientWidth/2;
                paddle->Top = Form1->ClientHeight - 50;
                Label1->Left = Form1->ClientWidth/2;
                Label1->Top = 10;
                score = 0;
         }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer_scoreTimer(TObject *Sender)
{    // score timer
     score += 1;
}
//---------------------------------------------------------------------------

