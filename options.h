//----------------------------------------------------------------------------
#ifndef OCBH
#define OCBH
//----------------------------------------------------------------------------
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//----------------------------------------------------------------------------
class TOptionsDialog : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
    TRadioGroup *LanguageGroup;
    TRadioGroup *NumberSizeGroup;
    TCheckBox *CheckBox1;
    void __fastcall CancelBtnClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall OKBtnClick(TObject *Sender);
private:
public:
	virtual __fastcall TOptionsDialog(TComponent* AOwner);
    int Flanguage;  //user language
    int FNumberSize;//размер числа 3 или 4

};
//----------------------------------------------------------------------------
extern PACKAGE TOptionsDialog *OptionsDialog;
//----------------------------------------------------------------------------
#endif
