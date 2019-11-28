//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "Unit4.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TShape *tlo;
    TImage *ball;
    TTimer *Timer_ball;
    TImage *paddle;
    TTimer *lewo;
    TTimer *prawo;
    TImage *Image1;
    TImage *Image2;
    TImage *Image3;
    TImage *Image4;
    TImage *Image5;
    TImage *Image6;
    TImage *Image7;
    TImage *Image8;
    TImage *Image9;
    TImage *Image10;
    TImage *Image11;
    TImage *Image12;
    TImage *Image13;
    TImage *Image14;
    TImage *Image15;
    TButton *Button1;
    TFrame4 *Frame4;
    TImage *Image16;
    TImage *Image17;
    TImage *Image18;
    TImage *Image19;
    TImage *Image20;
    TLabel *Label1;
    TTimer *Timer_score;
    TButton *Button2;
    void __fastcall Timer_ballTimer(TObject *Sender);
    void __fastcall lewoTimer(TObject *Sender);
    void __fastcall prawoTimer(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Frame4Button1Click(TObject *Sender);
    void __fastcall Frame4Button2Click(TObject *Sender);
    void __fastcall Timer_scoreTimer(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
