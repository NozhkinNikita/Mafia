//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//---------------------------------------------------------------------------
class TForm4 : public TForm
{
private:
    friend class TForm1;

    __published:    // IDE-managed Components
            TMemo * Memo1;
    TLabel *Label1;
    TButton *Button1;
    TEdit *Edit1;

    void __fastcall Button1Click(TObject *Sender);

private:    // User declarations
public:        // User declarations
    __fastcall TForm4(TComponent *Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm4 * Form4;
//---------------------------------------------------------------------------
#endif
