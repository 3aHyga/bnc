//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("bnc.res");
USEFORM("bnc1.cpp", bncForm);
USEFORM("options.cpp", OptionsDialog);
USEFORM("About.cpp", AboutBox);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = "Bulls and Cows";
        Application->CreateForm(__classid(TbncForm), &bncForm);
        Application->CreateForm(__classid(TOptionsDialog), &OptionsDialog);
        Application->CreateForm(__classid(TAboutBox), &AboutBox);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
