//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <string.h>
#pragma hdrstop

#include "bnc1.h"
#include "options.h"
#include "about.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

const char pMistakeR[]="Ошибка";
const char pNewR[]="Новая игра";
const char pGOverR[]="Игра завершена";
const char pGOverDR[]="Игра завершена в ничью";
const char pRogueR[]="Ты плут ?";
const char pWinR[]="Ты знаешь что, я выиграл ?!!";
const char pSeleR[]="Я тебя поздравляю !";
const char pAgainR[]="Играем еще ?";
const char pConfR[]="Ты запутался где-то в ответах";

const char pMistakeE[]="Mistake";
const char pNewE[]="New game";
const char pGOverE[]="Game over";
const char pGOverDE[]="Game over in draw";
const char pRogueE[]="Are you rogue ?";
const char pWinE[]="Are you know what I win ?!!";
const char pSeleE[]="I selebrate you !";
const char pAgainE[]="Again playing?";
const char pConfE[]="You confused somewhat in answers";


TbncForm *bncForm;
//---------------------------------------------------------------------------
__fastcall TbncForm::TbncForm(TComponent* Owner)
    : TForm(Owner)
{
  nCPU=1;
  nPlayer=0;
  ListBox[nPlayer]=ListBox1;
  ListBox[nCPU]=ListBox2;
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::SetLanguage(int l)
{
  switch (l)
    {
    case ENGLISH:
      bncForm->Caption="Bulls and Cows";
      ButtonBull->Caption="B";
      ButtonCow->Caption="C";
      ButtonBull->Hint="Bull";
      ButtonCow->Hint="Cow";
      ButtonEnter->Caption="Enter";
      ButtonBack->Caption="Back";
      NamePlayer[nPlayer]->Text="Player";
      NamePlayer[nCPU]->Text="CPU";
      ListBox[nPlayer]->Hint="You guess Computer's number here";
      ListBox[nCPU]->Hint="Computer guess your number here";
      pMistake=(char*)pMistakeE;
      pNew=(char*)pNewE;
      pGOver=(char*)pGOverE;
      pGOverD=(char*)pGOverDE;
      pRogue=(char*)pRogueE;
      pWin=(char*)pWinE;
      pSele=(char*)pSeleE;
      pAgain=(char*)pAgainE;
      pConf=(char*)pConfE;
      FileM->Caption="&File";
      NewM->Caption="&New";
      ExitM->Caption="E&xit";
      ToolsM->Caption="&Tools";
      OptionsM->Caption="&Options...";
      AboutM->Caption="&About...";
      OptionsDialog->Caption="Options";
      OptionsDialog->CancelBtn->Caption="Cancel";
      OptionsDialog->LanguageGroup->Caption="Language";
      OptionsDialog->LanguageGroup->Items->Strings[RUSSIAN]="Russian";
      OptionsDialog->LanguageGroup->Items->Strings[ENGLISH]="English";
      OptionsDialog->NumberSizeGroup->Caption="Number Size";
      OptionsDialog->NumberSizeGroup->Items->Strings[0]="3 digits";
      OptionsDialog->NumberSizeGroup->Items->Strings[1]="4 digits";
      OptionsDialog->CheckBox1->Caption="Apply Parameters";
      AboutBox->Caption="About Bulls and Cows";
      AboutBox->ProductName->Caption="Bulls and Cows. Version 1.1";
      AboutBox->Copyright->Caption="Copyright © 1998-1999 Pavel Skrylev";
      AboutBox->Comments->Caption="All rights reserved";
      break;
    case RUSSIAN:
    default:
      bncForm->Caption="Быки и Коровы";
      ButtonBull->Caption="Б";
      ButtonCow->Caption="К";
      ButtonBull->Hint="Бык";
      ButtonCow->Hint="Корова";
      ButtonEnter->Caption="Ввод";
      ButtonBack->Caption="Назад";
      NamePlayer[nPlayer]->Text="Игрок";
      NamePlayer[nCPU]->Text="ЦПУ";
      ListBox[nPlayer]->Hint="Здесь вы отгадываете число у компьютера";
      ListBox[nCPU]->Hint="Здесь компьютер отгадывает число у вас";
      pMistake=(char*)pMistakeR;
      pNew=(char*)pNewR;
      pGOver=(char*)pGOverR;
      pGOverD=(char*)pGOverDR;
      pRogue=(char*)pRogueR;
      pWin=(char*)pWinR;
      pSele=(char*)pSeleR;
      pAgain=(char*)pAgainR;
      pConf=(char*)pConfR;
      FileM->Caption="&Файл";
      NewM->Caption="&Новая игра";
      ExitM->Caption="&Выход";
      ToolsM->Caption="&Инструменты";
      OptionsM->Caption="&Настройки...";
      AboutM->Caption="&О программе...";
      OptionsDialog->Caption="Настройки";
      OptionsDialog->CancelBtn->Caption="Отмена";
      OptionsDialog->LanguageGroup->Caption="Язык";
      OptionsDialog->LanguageGroup->Items->Strings[RUSSIAN]="Русский";
      OptionsDialog->LanguageGroup->Items->Strings[ENGLISH]="Английский (English)";
      OptionsDialog->NumberSizeGroup->Caption="Размер числа";
      OptionsDialog->NumberSizeGroup->Items->Strings[0]="3 цифры";
      OptionsDialog->NumberSizeGroup->Items->Strings[1]="4 цифры";
      OptionsDialog->CheckBox1->Caption="Применить параметры";
      AboutBox->Caption="О программе Быки и Коровы";
      AboutBox->ProductName->Caption="Быки и Коровы. Версия 1.1";
      AboutBox->Copyright->Caption="Copyright © 1998-1999 Павел Скрылёв";
      AboutBox->Comments->Caption="Все права защищены";
    }
  Flanguage=l;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TbncForm::ReStoreBuf()
{
  int i,j,k,l,n=0;
  if (numsize==4)
    {
    for (i=0;i<10;i++)
      for(j=0;j<10;j++)
        for(k=0;k<10;k++)
          for(l=0;l<10;l++)
            if ((i!=j)&&(i!=k)&&(i!=l)&&(j!=k)&&(j!=l)&&(k!=l))
              {
              *(aSet+n)= (i<<12)+(j<<8)+(k<<4)+l;
              n++;
              }
    }
  else
    {
    for(j=0;j<10;j++)
      for(k=0;k<10;k++)
        for(l=0;l<10;l++)
          if ((j!=k)&&(j!=l)&&(k!=l))
            {
            *(aSet+n)=(j<<8)+(k<<4)+l;
            n++;
            }
    }
  nNumCPU=n;
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::New(TObject *Sender){
  int i,j,k;
  bool fl;

  nPlayer=0;
  nCPU=1;
  ListBox[nPlayer]=ListBox1;
  ListBox[nCPU]=ListBox2;
  NamePlayer[nPlayer]=Title1;
  NamePlayer[nCPU]=Title2;
  for (i=0;i<2;i++)
    ListBox[i]->Clear();
  nSide=0;
  nTurn=0;
  nPart=NP_NUMBER;
  TurnStr[0]='\0';
  EndCode=0;
  answer=false;
  //new
  language=OptionsDialog->LanguageGroup->ItemIndex;
  numsize=OptionsDialog->NumberSizeGroup->ItemIndex+3;

  randomize();
  for(i=0;i<numsize;i++){
    do{
      fl=false;
      k=random(10);
      for(j=0;j<i;j++)
        if(k==num[j]-'0')
          fl=true;
      } while(fl);
    num[i]=(char) (k+'0');
    }

  //????????????
  ReStoreBuf();

  Button1->Enabled=true;
  Button2->Enabled=true;
  Button3->Enabled=true;
  Button4->Enabled=true;
  Button5->Enabled=true;
  Button6->Enabled=true;
  Button7->Enabled=true;
  Button8->Enabled=true;
  Button9->Enabled=true;
  Button0->Enabled=true;
  ButtonBull->Enabled=false;
  ButtonCow->Enabled=false;
  ButtonEnter->Enabled=false;
  ButtonBack->Enabled=false;

}
//---------------------------------------------------------------------------
void __fastcall TbncForm::Next(){

  if(ReadBCW(nTurn,nSide)==(UINT) (numsize<<8))
    EndCode|=1<<nSide;

  if(answer)
    {
    if(naTurn>nTurn)
      {
      Button1->Enabled=true;
      Button2->Enabled=true;
      Button3->Enabled=true;
      Button4->Enabled=(numsize==4);
      Button5->Enabled=false;
      Button6->Enabled=false;
      Button7->Enabled=false;
      Button8->Enabled=false;
      Button9->Enabled=false;
      Button0->Enabled=false;
      ButtonBull->Enabled=false;
      ButtonCow->Enabled=false;
      ButtonBack->Enabled=false;
      ButtonEnter->Enabled=true;
      nTurn++;
      StrCat(TurnStr,(char*) (ListBox[nCPU]->Items->Strings[nTurn].c_str()));
      return;
      }
    else
      Button1->Enabled=true;
      Button2->Enabled=true;
      Button3->Enabled=true;
      Button4->Enabled=true;
      Button5->Enabled=true;
      Button6->Enabled=true;
      Button7->Enabled=true;
      Button8->Enabled=true;
      Button9->Enabled=true;
      Button0->Enabled=true;
      ButtonBull->Enabled=false;
      ButtonCow->Enabled=false;
      ButtonBack->Enabled=false;
      ButtonEnter->Enabled=false;
      answer=false;
    }

  if(nPart==NP_NUMBER)
    {
    nPart=NP_ANSWER;
    return;
    }
  if(nPart==NP_ANSWER&&nSide==0)
    {
    nSide++;
    }
  else
    {
    nTurn++;
    nSide=0;
    switch (EndCode)
      {
      case 0:
        break;
      case 1:
      case 2:
        if (EndCode-1==nPlayer)
          Application->MessageBox(pRogue,
            pGOver,MB_OK|MB_ICONQUESTION|MB_APPLMODAL);
        else
          Application->MessageBox(pWin,
            pGOver,MB_OK|MB_ICONQUESTION|MB_APPLMODAL);
        break;
      case 3:
        Application->MessageBox(pSele,
          pGOverD,MB_OK|MB_ICONINFORMATION|MB_APPLMODAL);
      }
    if (EndCode)
      {
      if(Application->MessageBox(pAgain,
        pNew,MB_YESNO|MB_ICONQUESTION|MB_APPLMODAL)==IDYES)
          New(NULL);
      else
          Application->Terminate();
      }
    }
  nPart=NP_NUMBER;
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::CPU_Answer(){
  int i,j;
  char cCow,cBull;
  switch (language)
    {
    case ENGLISH:
      cCow=COWE;
      cBull=BULLE;
      break;
    case RUSSIAN:
    default:
      cCow=COWR;
      cBull=BULLR;
    }
  aBull=0;
  aCow=0;
  for (i=0;i<numsize;i++)
    for (j=0;j<numsize;j++)
      if(num[i]==TurnStr[j]){
        if(i==j)
          aBull++;
        else
          aCow++;}
  i=numsize+3;
  if(aBull){
    TurnStr[i]=(char) (aBull+'0');
    i++;
    TurnStr[i]=cBull;
    i++;
    }
  if(aCow){
    TurnStr[i]=(char) (aCow+'0');
    i++;
    TurnStr[i]=cCow;
    i++;
    }
  TurnStr[i]='\0';
  ListBox[nPlayer]->Items->Delete(nTurn);
  ListBox[nPlayer]->Items->Insert(nTurn,TurnStr);

}
//---------------------------------------------------------------------------
UINT __fastcall TbncForm::ReadNum(int n,int side)
{
  unsigned char* pbuf;
  int j,Num=0;
  pbuf=(unsigned char*) ListBox[side]->Items->GetText();
  while (n)
    {
    switch (*(pbuf)){
      case 0:
        return -1;
      case LF:
        n--;}
    pbuf++;
    }
  for(j=0;j<numsize;j++)
    Num+=((*(pbuf+j)-'0')<<((numsize-1-j)*4));
  return Num;
}
//---------------------------------------------------------------------------
UINT __fastcall TbncForm::ReadBCW(int n,int side)
{
  unsigned char* pbuf;
  int bull=0,cow=0,Num=0;
  pbuf=(unsigned char*) ListBox[side]->Items->GetText();
  while (n)
    {
    switch (*(pbuf)){
      case 0:
        return -1;
      case LF:
        n--;}
    pbuf++;
    }
  pbuf+=numsize+3;
  while(*pbuf!=0 && *pbuf!=CR)
    {
    switch (*pbuf)
      {
      case BULLE:
      case BULLR:
        bull=Num;
        break;
      case COWE:
      case COWR:
        cow=Num;
        break;
      default:
        Num=*pbuf-'0';
      }
    pbuf++;
    }
  return ((bull<<8)+cow);
}
//---------------------------------------------------------------------------
UINT __fastcall TbncForm::GetBCW(UINT Num,UINT Que)
{
  int bull=0,cow=0,i,j;
  for(i=(numsize-1)*4;i>=0;i-=4)
    for(j=(numsize-1)*4;j>=0;j-=4)
      if(((Num>>i)&0xf)==((Que>>j)&0xf))
        {
        if(j==i)
          bull++;
        else
          cow++;
        }
  return ((bull<<8)+cow);
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::Verify()
{
  UINT Num,bcw0,bcw1,Num0,Num1;
  int i,j;
  switch (nTurn)
    {
    case 0:
      break;
    case 1:
        j=0;
        bcw0=ReadBCW(0,nCPU);
        bcw1=ReadBCW(1,nCPU);
        Num0=ReadNum(0,nCPU);
        Num1=ReadNum(1,nCPU);
        for (i=0;i<nNumCPU;i++)
          {
          Num=*(aSet+i);
          if((GetBCW(Num,Num0)==bcw0)&&(GetBCW(Num,Num1)==bcw1))
            {
            *(aSet+j)=Num;
            j++;
            }
          }
        if (!j)
          ReQuestion(nCPU);
        else
          nNumCPU=j;
        break;
    default:
        j=0;
        bcw0=ReadBCW(nTurn,nCPU);
        Num0=ReadNum(nTurn,nCPU);
        for (i=0;i<nNumCPU;i++)
          {
          Num=*(aSet+i);
          if(GetBCW(Num,Num0)==bcw0)
            {
            *(aSet+j)=Num;
            j++;
            }
          }
        if (!j)
          ReQuestion(nCPU);
        else
          nNumCPU=j;
    }
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::ReQuestion(int side)
{
  int i;
  Application->MessageBox(pConf,pMistake,MB_OK|MB_ICONEXCLAMATION|MB_APPLMODAL);
  if(answer)
    nTurn=naTurn;
  else
    {
    answer=true;
    naTurn=nTurn;
    }
  for (i=0;i<=nTurn;i++)
    ListBox[nCPU]->Items->Strings[i]=
      ListBox[nCPU]->Items->Strings[i].Delete(numsize+4,4);
  ReStoreBuf();
  nTurn=-1;
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::CPU_Number()
{
  UINT Num,Num0;
  int i;

  switch(nTurn)
    {
    case 0:
      Num=*(aSet+random(nNumCPU));
      break;
    case 1:
      do{
        Num0=ReadNum(0,nCPU);
        i=random(nNumCPU);
        for (i;i<nNumCPU;i++)
          {
          Num=*(aSet+i);
          if(!GetBCW(Num,Num0))
            break;
          }
        }
      while (i==nNumCPU);
      break;
    default:
        Num=*(aSet+random(nNumCPU));
    }
  for (i=0;i<numsize;i++)
    TurnStr[i]=(char) (((Num>>((numsize-1-i)*4))&0xf)+'0');
  TurnStr[i]='\0';
  StrCat(TurnStr," - ");
  ListBox[nCPU]->Items->Insert(nTurn,TurnStr);
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::ButtonClick(TObject *Sender,char *num)
{
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER)){
      StrCat(TurnStr,num);
      ListBox[nPlayer]->Items->Delete(nTurn);
      ListBox[nPlayer]->Items->Insert(nTurn,TurnStr);
      if (StrLen(TurnStr)==(UINT) numsize) {
        Button1->Enabled=false;
        Button2->Enabled=false;
        Button3->Enabled=false;
        Button4->Enabled=false;
        Button5->Enabled=false;
        Button6->Enabled=false;
        Button7->Enabled=false;
        Button8->Enabled=false;
        Button9->Enabled=false;
        Button0->Enabled=false;
        ButtonBull->Enabled=false;
        ButtonCow->Enabled=false;
        ButtonEnter->Enabled=true;}}
  else{
      StrCat(TurnStr,num);
      ListBox[nCPU]->Items->Delete(nTurn);
      ListBox[nCPU]->Items->Insert(nTurn,TurnStr);
      if (StrLen(TurnStr)==(UINT) (numsize+7)) {
        Button1->Enabled=false;
        Button2->Enabled=false;
        Button3->Enabled=false;
        Button4->Enabled=false;
        ButtonBull->Enabled=false;
        ButtonCow->Enabled=false;
        ButtonEnter->Enabled=true;}}
  ButtonBack->Enabled=true;

}
//---------------------------------------------------------------------------
void __fastcall TbncForm::Button1Click(TObject *Sender)
{
  ButtonClick(Sender,"1");
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER))
    Button1->Enabled=false;
  else{
    Button1->Enabled=false;
    Button2->Enabled=false;
    Button3->Enabled=false;
    Button4->Enabled=false;
    ButtonBull->Enabled=true;
    ButtonCow->Enabled=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::Button2Click(TObject *Sender)
{
  ButtonClick(Sender,"2");
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER))
    Button2->Enabled=false;
  else{
    Button1->Enabled=false;
    Button2->Enabled=false;
    Button3->Enabled=false;
    Button4->Enabled=false;
    ButtonBull->Enabled=true;
    ButtonCow->Enabled=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::Button3Click(TObject *Sender)
{
  ButtonClick(Sender,"3");
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER))
    Button3->Enabled=false;
  else{
    Button1->Enabled=false;
    Button2->Enabled=false;
    Button3->Enabled=false;
    Button4->Enabled=false;
    ButtonBull->Enabled=true;
    ButtonCow->Enabled=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::Button4Click(TObject *Sender)
{
  ButtonClick(Sender,"4");
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER))
    Button4->Enabled=false;
  else{
    Button1->Enabled=false;
    Button2->Enabled=false;
    Button3->Enabled=false;
    Button4->Enabled=false;
    ButtonBull->Enabled=true;
    ButtonCow->Enabled=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::Button5Click(TObject *Sender)
{
  ButtonClick(Sender,"5");
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER))
  Button5->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::Button6Click(TObject *Sender)
{
  ButtonClick(Sender,"6");
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER))
  Button6->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::Button7Click(TObject *Sender)
{
  ButtonClick(Sender,"7");
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER))
  Button7->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::Button8Click(TObject *Sender)
{
  ButtonClick(Sender,"8");
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER))
  Button8->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::Button9Click(TObject *Sender)
{
  ButtonClick(Sender,"9");
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER))
  Button9->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::Button0Click(TObject *Sender)
{
  ButtonClick(Sender,"0");
  Button0->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::ButtonBullClick(TObject *Sender)
{
  ButtonBull->Enabled=false;
  ButtonCow->Enabled=false;
  Button1->Enabled=true;
  Button2->Enabled=true;
  Button3->Enabled=true;
  if(numsize==4)
    Button4->Enabled=true;
  switch (language)
    {
    case ENGLISH:
      ButtonClick(Sender,SBULLE);
      break;
    case RUSSIAN:
    default:
      ButtonClick(Sender,SBULLR);
    }
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::ButtonCowClick(TObject *Sender)
{
  ButtonBull->Enabled=false;
  ButtonCow->Enabled=false;
  Button1->Enabled=true;
  Button2->Enabled=true;
  Button3->Enabled=true;
  if(numsize==4)
    Button4->Enabled=true;
  switch (language)
    {
    case ENGLISH:
      ButtonClick(Sender,SCOWE);
      break;
    case RUSSIAN:
    default:
      ButtonClick(Sender,SCOWR);
    }
}
//---------------------------------------------------------------------------


void __fastcall TbncForm::ButtonEnterClick(TObject *Sender)
{
  int t;
  aCow=0;
  aBull=0;
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER)){
    StrCat(TurnStr," - ");
    ListBox[nPlayer]->Items->Delete(nTurn);
    ListBox[nPlayer]->Items->Insert(nTurn,TurnStr);
    Button1->Enabled=true;
    Button2->Enabled=true;
    Button3->Enabled=true;
    Button4->Enabled=(numsize==4);
    ButtonBull->Enabled=false;
    ButtonCow->Enabled=false;
    Next();
    CPU_Answer();
    Next();
    CPU_Number();
    Next();
    }
  else{
    Button1->Enabled=true;
    Button2->Enabled=true;
    Button3->Enabled=true;
    Button4->Enabled=true;
    ButtonBull->Enabled=false;
    ButtonCow->Enabled=false;
    ButtonEnter->Enabled=false;
    ButtonBack->Enabled=false;
    if ((StrLen(TurnStr)==(UINT) (numsize+5)) || (StrLen(TurnStr)==(UINT) (numsize+7))){
      t=TurnStr[numsize+3]-'0';
      switch(TurnStr[numsize+4])
        {
        case BULLE:
        case BULLR:
          aBull=t;
          break;
        case COWE:
        case COWR:
          aCow=t;
        }
      if(StrLen(TurnStr)==(UINT) (numsize+7)){
        t=TurnStr[numsize+5]-'0';
        switch(TurnStr[numsize+4])
          {
          case BULLE:
          case BULLR:
            if (!aBull)
              aBull=t;
            break;
          case COWE:
          case COWR:
            if (!aCow)
              aCow=t;
          }
        }
      }
    else {
      TurnStr[numsize+3]='\0';
      ListBox[nCPU]->Items->Delete(nTurn);
      ListBox[nCPU]->Items->Insert(nTurn,TurnStr);
      }
    TurnStr[0]='\0';
    Verify();
    if (!answer)
      {
      Button5->Enabled=true;
      Button6->Enabled=true;
      Button7->Enabled=true;
      Button8->Enabled=true;
      Button9->Enabled=true;
      Button0->Enabled=true;
      }
    Next();
    }
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::ButtonBackClick(TObject *Sender)
{
  int i;
  bool fl=false;
  if ((nSide==nPlayer)&&(nPart==NP_NUMBER)){
    TurnStr[StrLen(TurnStr)-1]='\0';
    ListBox[nPlayer]->Items->Delete(nTurn);
    ListBox[nPlayer]->Items->Insert(nTurn,TurnStr);
    if(!StrLen(TurnStr))
      ButtonBack->Enabled=false;
    for (i=0;i<(int)StrLen(TurnStr);i++)
      if (TurnStr[i]-'0'==1) {
        fl=true;
        break;
        }
    if (!fl)
      Button1->Enabled=true;
    else
      fl=false;
    for (i=0;i<(int)StrLen(TurnStr);i++)
      if (TurnStr[i]-'0'==2) {
        fl=true;
        break;
        }
    if (!fl)
      Button2->Enabled=true;
    else
      fl=false;
    for (i=0;i<(int)StrLen(TurnStr);i++)
      if (TurnStr[i]-'0'==3) {
        fl=true;
        break;
        }
    if (!fl)
      Button3->Enabled=true;
    else
      fl=false;
    for (i=0;i<(int)StrLen(TurnStr);i++)
      if (TurnStr[i]-'0'==4) {
        fl=true;
        break;
        }
    if (!fl)
      Button4->Enabled=true;
    else
      fl=false;
    for (i=0;i<(int)StrLen(TurnStr);i++)
      if (TurnStr[i]-'0'==5) {
        fl=true;
        break;
        }
    if (!fl)
      Button5->Enabled=true;
    else
      fl=false;
    for (i=0;i<(int)StrLen(TurnStr);i++)
      if (TurnStr[i]-'0'==6) {
        fl=true;
        break;
        }
    if (!fl)
      Button6->Enabled=true;
    else
      fl=false;
    for (i=0;i<(int)StrLen(TurnStr);i++)
      if (TurnStr[i]-'0'==7) {
        fl=true;
        break;
        }
    if (!fl)
      Button7->Enabled=true;
    else
      fl=false;
    for (i=0;i<(int)StrLen(TurnStr);i++)
      if (TurnStr[i]-'0'==8) {
        fl=true;
        break;
        }
    if (!fl)
      Button8->Enabled=true;
    else
      fl=false;
    for (i=0;i<(int)StrLen(TurnStr);i++)
      if (TurnStr[i]-'0'==9) {
        fl=true;
        break;
        }
    if (!fl)
      Button9->Enabled=true;
    else
      fl=false;
    for (i=0;i<(int)StrLen(TurnStr);i++)
      if (TurnStr[i]-'0'==0) {
        fl=true;
        break;
        }
    if (!fl)
      Button0->Enabled=true;

    ButtonEnter->Enabled=false;
    }
  else {
    TurnStr[numsize+3]='\0';
    Button1->Enabled=true;
    Button2->Enabled=true;
    Button3->Enabled=true;
    Button4->Enabled=true;
    ButtonBull->Enabled=false;
    ButtonCow->Enabled=false;
    ButtonBack->Enabled=false;
    ButtonEnter->Enabled=true;
    ListBox[nCPU]->Items->Delete(nTurn);
    ListBox[nCPU]->Items->Insert(nTurn,TurnStr);
    aBull=0;
    aCow=0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::FormDestroy(TObject *Sender)
{
  free((void*) Free);
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::FormCreate(TObject *Sender)
{
  Free=(PBYTE) malloc(32767);
  aSet=((PUINT) Free)+10;
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::Exit(TObject *Sender)
{
  Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::FormKeyPress(TObject *Sender, char &Key)
{
  switch (Key)
    {
    case '0':
      if(Button0->Enabled)
        Button0->Click();
      break;
    case '1':
      if(Button1->Enabled)
        Button1->Click();
      break;
    case '2':
      if(Button2->Enabled)
        Button2->Click();
      break;
    case '3':
      if(Button3->Enabled)
        Button3->Click();
      break;
    case '4':
      if(Button4->Enabled)
        Button4->Click();
      break;
    case '5':
      if(Button5->Enabled)
        Button5->Click();
      break;
    case '6':
      if(Button6->Enabled)
        Button6->Click();
      break;
    case '7':
      if(Button7->Enabled)
        Button7->Click();
      break;
    case '8':
      if(Button8->Enabled)
        Button8->Click();
      break;
    case '9':
      if(Button9->Enabled)
        Button9->Click();
      break;
    case BULLEL:
    case BULLRL:
    case BULLE:
    case BULLR:
      if(ButtonBull->Enabled)
        ButtonBull->Click();
      break;
    case COWEL:
    case COWRL:
    case COWE:
    case COWR:
      if(ButtonCow->Enabled)
        ButtonCow->Click();
      break;
    case CR:
      if(ButtonEnter->Enabled)
        ButtonEnter->Click();
      break;
    case BACK:
      if(ButtonBack->Enabled)
        ButtonBack->Click();
      break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TbncForm::OptionsMClick(TObject *Sender)
{
  OptionsDialog->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TbncForm::AboutMClick(TObject *Sender)
{
  AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

