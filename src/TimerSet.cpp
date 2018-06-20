//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TimerSet.h"
#include "Paper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "RXClock"
#pragma resource "*.dfm"

TfrmTimerSet *frmTimerSet;
//---------------------------------------------------------------------------
__fastcall TfrmTimerSet::TfrmTimerSet(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TfrmTimerSet::TfrmTimerSet(TComponent* Owner, TDateTime Ti, bool isSet)
        : TForm(Owner)
{
        unsigned short hour, min, sec, msec;

        if(isSet)
        {

                DecodeTime(Ti, hour, min, sec, msec);
                if(hour>12)
                {
                        btnAMPM->Caption = "����";
                        cseHour->Value = hour - 12;
                }
                else
                {
                        btnAMPM->Caption = "����";
                        cseHour->Value = hour;
                }
                cseMin->Value = min;
                cseSec->Value = sec;

                lbIsSet->Font->Color = clRed;
                lbIsSet->Caption = "���� �Ǿ� ����";
        }
        else
        {
                DecodeTime(Time(), hour, min, sec, msec);
                if(hour>12)
                {
                        btnAMPM->Caption = "����";
                        cseHour->Value = hour - 12;
                }
                else
                {
                        btnAMPM->Caption = "����";
                        cseHour->Value = hour;
                }
                cseMin->Value = min;
                cseSec->Value = sec;

                lbIsSet->Font->Color = clWindowText;
                lbIsSet->Caption = "���� ���� ����";
        }
}
//---------------------------------------------------------------------------
void __fastcall TfrmTimerSet::Create(TObject *Sender)
{
        nResult = 0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTimerSet::btnAMPMClick(TObject *Sender)
{
        if(btnAMPM->Caption == "����")
                btnAMPM->Caption = "����";
        else
                btnAMPM->Caption = "����";
}
//---------------------------------------------------------------------------
void __fastcall TfrmTimerSet::btnSetClick(TObject *Sender)
{
        unsigned short h,m,s,ms=0;

        if(btnAMPM->Caption=="����")
                if((unsigned short)cseHour->Value != 12)
                        h = (unsigned short)cseHour->Value + 12;
                else
                        h = 0;
        else
                h = (unsigned short)cseHour->Value;
        m = (unsigned short)cseMin->Value;
        s = (unsigned short)cseSec->Value;
        st = EncodeTime(h,m,s,ms);

        nResult = 1;
        ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTimerSet::btnClearClick(TObject *Sender)
{
        nResult = 2;
        ModalResult = mrOk;
}
//---------------------------------------------------------------------------


void __fastcall TfrmTimerSet::btnCancelClick(TObject *Sender)
{
        nResult = 0;
        ModalResult = mrOk;
}
//---------------------------------------------------------------------------

