//---------------------------------------------------------------------------
#ifndef bnc1H
#define bnc1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
#define NP_NUMBER    1
#define NP_ANSWER    2

#define NONE         0
#define PLAYER       1
#define CPU          2

#define BULLE        'B'
#define COWE         'C'
#define BULLR        'Б'
#define COWR         'К'

#define BULLEL       'b'
#define COWEL        'c'
#define BULLRL       'б'
#define COWRL        'к'

#define CR           '\r'
#define LF           '\n'
#define BACK         '\b'

#define RUSSIAN      0
#define ENGLISH      1

#define SBULLE       "B"
#define SCOWE        "C"
#define SBULLR       "Б"
#define SCOWR        "К"


class TbncForm : public TForm
{
__published:	// IDE-managed Components
    TListBox *ListBox1;
    TListBox *ListBox2;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
    TButton *Button5;
    TButton *Button6;
    TButton *Button7;
    TButton *Button8;
    TButton *Button9;
    TButton *Button0;
    TButton *ButtonBack;
    TButton *ButtonEnter;
    TEdit *Title1;
    TEdit *Title2;
    TButton *ButtonBull;
    TButton *ButtonCow;
    TMainMenu *MainMenu1;
    TMenuItem *FileM;
    TMenuItem *NewM;
    TMenuItem *N1;
    TMenuItem *ExitM;
    TMenuItem *ToolsM;
    TMenuItem *OptionsM;
    TMenuItem *N2;
    TMenuItem *AboutM;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button7Click(TObject *Sender);
    void __fastcall Button8Click(TObject *Sender);
    void __fastcall Button9Click(TObject *Sender);
    void __fastcall Button0Click(TObject *Sender);
    void __fastcall ButtonBullClick(TObject *Sender);
    void __fastcall ButtonCowClick(TObject *Sender);
    void __fastcall ButtonEnterClick(TObject *Sender);
    void __fastcall ButtonBackClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormKeyPress(TObject *Sender, char &Key);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall New(TObject *Sender);
    void __fastcall Exit(TObject *Sender);
    void __fastcall OptionsMClick(TObject *Sender);


    void __fastcall AboutMClick(TObject *Sender);
private:	// User declarations
    //new
    int Flanguage;  //user language
    void __fastcall SetLanguage(int);
    int FNumberSize;//размер числа 3 или 4
    char* pMistake;
    char* pNew;
    char* pGOver;
    char* pGOverD;
    char* pRogue;
    char* pWin;
    char* pSele;
    char* pAgain;
    char* pConf;

    //old
    void __fastcall Next();
    void __fastcall CPU_Answer();
    void __fastcall CPU_Number();
    void __fastcall ButtonClick(TObject *Sender,char*);
    UINT __fastcall GetBCW(UINT,UINT);
    UINT __fastcall ReadBCW(int,int);
    UINT __fastcall ReadNum(int,int);
    void __fastcall ReQuestion(int);
    void __fastcall Verify();
    void __fastcall ReStoreBuf();
    int nSide;     // ID Current Question List
    int nPlayer;   // ID Player
    int nCPU;      // ID CPU
    int nTurn;     // Number of Turn
    int naTurn;
    int nPart;     // Part - question or answer
    bool answer;
    char TurnStr[14];
    int aBull;
    int aCow;
    char num[5];   //CPU Number
    PUINT aSet;    //Перечень всех возможных вариантов
    PBYTE Free;    //Свободное для действий простанство
    int nNumCPU;   // Число чисел в aSet
    int EndCode;
    TListBox* ListBox[2];
    TEdit* NamePlayer[2];

public:		// User declarations
    __fastcall TbncForm(TComponent* Owner);
    //new
    __property int language={read=Flanguage,write=SetLanguage};
    __property int numsize={read=FNumberSize,write=FNumberSize};
};

//---------------------------------------------------------------------------
extern PACKAGE TbncForm *bncForm;
//--------------------------------------------------------------------------
#endif
