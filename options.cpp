//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "options.h"
#include "bnc1.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TOptionsDialog *OptionsDialog;
//---------------------------------------------------------------------
__fastcall TOptionsDialog::TOptionsDialog(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TOptionsDialog::CancelBtnClick(TObject *Sender)
{
  LanguageGroup->ItemIndex=Flanguage;
  NumberSizeGroup->ItemIndex=FNumberSize;
}
//---------------------------------------------------------------------------

void __fastcall TOptionsDialog::FormActivate(TObject *Sender)
{
  Flanguage=LanguageGroup->ItemIndex;
  FNumberSize=NumberSizeGroup->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TOptionsDialog::OKBtnClick(TObject *Sender)
{
  if(CheckBox1->Checked&&Flanguage!=LanguageGroup->ItemIndex)
    bncForm->language=LanguageGroup->ItemIndex;
}
//---------------------------------------------------------------------------

