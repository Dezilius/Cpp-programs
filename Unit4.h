//---------------------------------------------------------------------------


#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFrame4 : public TFrame
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TComboBox *ComboBox1;
    TComboBox *ComboBox2;
    TLabel *Label3;
    TButton *Button1;
    TButton *Button2;
    TLabel *Label2;
    TEdit *Edit1;
private:	// User declarations
public:		// User declarations
    __fastcall TFrame4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame4 *Frame4;
//---------------------------------------------------------------------------
#endif
