//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Paper.h"
#include "TimerSet.h"
#include <Clipbrd.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "NewRichEdit"
#pragma resource "*.dfm"
TfrmPaper *frmPaper;

#define SC_DRAG_RESIZEL 0xf001   // left resize
#define SC_DRAG_RESIZER 0xf002   // right resize
#define SC_DRAG_RESIZEU 0xf003   // upper resize
#define SC_DRAG_RESIZEUL 0xf004  // upper-left resize
#define SC_DRAG_RESIZEUR 0xf005  // upper-right resize
#define SC_DRAG_RESIZED 0xf006   // down resize
#define SC_DRAG_RESIZEDL 0xf007  // down-left resize
#define SC_DRAG_RESIZEDR 0xf008  // down-right resize
#define SC_DRAG_MOVE 0xf012      // move

//---------------------------------------------------------------------------
__fastcall TfrmPaper::TfrmPaper(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::CreateParams(TCreateParams &Params)
{
     TForm::CreateParams(Params);
     Params.ExStyle = WS_EX_APPWINDOW;
     Params.WndParent = GetDesktopWindow();
}

void __fastcall TfrmPaper::Create(TObject *Sender)
{
        bCheck = false;
        bEditable = true;
        dtSettime=EncodeTime(12,0,0,0);

        HWND hRegion;
        hRegion = CreateRectRgn(2, 2, Width-1, Height-1);
        SetWindowRgn(Handle, hRegion, True);
}
//---------------------------------------------------------------------------


void __fastcall TfrmPaper::pmExitClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        if(Button == mbRight)
        {
                TPoint pt;
                GetCursorPos(&pt);
                if(nrePaper->SelLength==0)
                {
                        if(!Clipboard()->HasFormat(CF_TEXT))
                                pmPaste->Enabled = false;
                        else
                                pmPaste->Enabled = true;
                        pmPMenu->Popup(pt.x, pt.y);
                }
                else
                        pmCMenu->Popup(pt.x, pt.y);
        }
        if(!bEditable)
        {
                TControl *SenderControl = dynamic_cast<TControl *>(Sender);
                int SysCommWparam;

                HideCaret(nrePaper->Handle);

                if(X < 3 && Y < 3)
                        SysCommWparam = SC_DRAG_RESIZEUL;
                else
                        if(X > SenderControl->Width-8 && Y > SenderControl->Height-8)
                                SysCommWparam = SC_DRAG_RESIZEDR;
                        else
                                if(X < 3 && Y > SenderControl->Height-8)
                                        SysCommWparam = SC_DRAG_RESIZEDL;
                                else
                                        if(X > SenderControl->Width-8 && Y < 3)
                                                SysCommWparam = SC_DRAG_RESIZEUR;
                                        else
                                                if(X < 3)
                                                        SysCommWparam = SC_DRAG_RESIZEL;
                                                else
                                                        if(X > SenderControl->Width-8)
                                                                SysCommWparam = SC_DRAG_RESIZER;
                                                        else
                                                                if(Y < 3)
                                                                        SysCommWparam = SC_DRAG_RESIZEU;
                                                                else
                                                                        if(Y > SenderControl->Height-8)
                                                                                SysCommWparam = SC_DRAG_RESIZED;
                                                                        else
                                                                                SysCommWparam = SC_DRAG_MOVE;

                ReleaseCapture();
                SendMessage(Handle, WM_SYSCOMMAND, SysCommWparam, 0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::BlkClick(TObject *Sender)
{
        if(bEditable)
        {
                HideCaret(nrePaper->Handle);
                bEditable = false;
                nrePaper->ReadOnly = true;
                nrePaper->Cursor = crSizeAll;
        }
        else
        {
                ShowCaret(nrePaper->Handle);
                bEditable = true;
                nrePaper->ReadOnly = false;
                nrePaper->Cursor = crDefault;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        TControl *SenderControl = dynamic_cast<TControl *>(Sender);

        if(!bEditable)
        {
                if((X < 3 && Y < 3) || (X > SenderControl->Width-8 && Y > SenderControl->Height-8))
                        SenderControl->Cursor = crSizeNWSE;
                else
                        if((X < 3 && Y > SenderControl->Height-8) || (X > SenderControl->Width-8 && Y < 3))
                                SenderControl->Cursor = crSizeNESW;
                        else
                                if(X < 3 || X > SenderControl->Width-8)
                                        SenderControl->Cursor = crSizeWE;
                                else
                                        if(Y < 3 || Y > SenderControl->Height-8)
                                                SenderControl->Cursor = crSizeNS;
                                        else
                                                SenderControl->Cursor = crSizeAll;
        }
        else
                SenderControl->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::WMGetMinMaxInfo(TWMGetMinMaxInfo &Msg)
{
        Msg.MinMaxInfo->ptMinTrackSize.x = 100;
        Msg.MinMaxInfo->ptMinTrackSize.y = 40;
}
void __fastcall TfrmPaper::Resize(TObject *Sender)
{
        HWND hRegion;
        hRegion = CreateRectRgn(2, 2, Width-1, Height-1);
        SetWindowRgn(Handle, hRegion, True);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::Timer(TObject *Sender)
{
        if(bCheck)
        {
                unsigned short hour,min,sec,msec;
                unsigned short h,m,s,ms;
                DecodeTime(Time(),hour,min,sec,msec);
                DecodeTime(dtSettime,h,m,s,ms);
                if(hour == h && min == m && sec == s)
                {
                        Beep();
                        ShowMessage("시간이 되었습니다");
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmFontClick(TObject *Sender)
{
        if(fdFont->Execute());
                nrePaper->SelAttributes->Assign(fdFont->Font);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmColorClick(TObject *Sender)
{
        if(cdColor->Execute())
                nrePaper->Color = cdColor->Color;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmTransparentClick(TObject *Sender)
{
        pmTransparent->Checked = !pmTransparent->Checked;
        if(pmTransparent->Checked == true)
        {
                SetWindowLong(Handle, GWL_EXSTYLE, GetWindowLong(Handle, GWL_EXSTYLE) | WS_EX_LAYERED);
                SetLayeredWindowAttributes(Handle, 0, 180, LWA_ALPHA);
        }
        else
        {
                SetWindowLong(Handle, GWL_EXSTYLE, GetWindowLong(Handle, GWL_EXSTYLE) | WS_EX_LAYERED);
                SetLayeredWindowAttributes(Handle, 0, 255, LWA_ALPHA);
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmTimerClick(TObject *Sender)
{
        TfrmTimerSet *timerset = new TfrmTimerSet(this, dtSettime, bCheck);
        timerset->ShowModal();
        if(timerset->ModalResult==mrOk)
        {
                switch(timerset->nResult)
                {
                        case 1:
                                bCheck = true;
                                dtSettime = timerset->st;
                                break;
                        case 2:
                                bCheck = false;
                                break;
                        case 0:
                        default:
                                break;
                }
                timerset->Close();
                delete timerset;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmLeftClick(TObject *Sender)
{
        nrePaper->Paragraph->Alignment = taLeftJustify;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmCenterClick(TObject *Sender)
{
        nrePaper->Paragraph->Alignment = taCenter;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmRightClick(TObject *Sender)
{
        nrePaper->Paragraph->Alignment = taRightJustify;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmClearClick(TObject *Sender)
{
        if(nrePaper->Modified)
        {
                int result = MessageBox(Handle, "현재 기록된 내용을 저장할까요?", "현재 내용 지우기", MB_YESNOCANCEL | MB_ICONWARNING);
                if(result == IDYES) pmSaveClick(Sender);
                if(result == IDCANCEL) return;
        }

        if(nrePaper->Lines->Count > 0) nrePaper->Clear();
        sdSave->FileName = "";
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmOpenClick(TObject *Sender)
{
        if(nrePaper->Modified)
        {
                int result = MessageBox(Handle, "새 파일을 열기 전에 현재 내용을 저장하시겠습니까?", "열기", MB_YESNOCANCEL | MB_ICONWARNING);
                if(result == IDYES) pmSaveClick(Sender);
                if(result == IDCANCEL) return;
        }
        odOpen->FileName = "";
        if(odOpen->Execute())
        {
                if(nrePaper->Lines->Count > 0) nrePaper->Clear();
                nrePaper->Lines->LoadFromFile(odOpen->FileName);
                sdSave->FileName = odOpen->FileName;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmSaveClick(TObject *Sender)
{
        if(sdSave->FileName != "")
        {
                if(ExtractFileExt(sdSave->FileName) == ".rtf")
                        nrePaper->PlainText = false;
                else
                        nrePaper->PlainText = true;
                nrePaper->Lines->SaveToFile(sdSave->FileName);
                nrePaper->Modified = false;
        }
        else
                pmSaveAsClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmSaveAsClick(TObject *Sender)
{
        sdSave->Title = "다른 이름으로 저장";
        if(sdSave->Execute())
        {
                if(ExtractFileExt(sdSave->FileName) == ".rtf")
                        nrePaper->PlainText = false;
                else
                        nrePaper->PlainText = true;
                nrePaper->Lines->SaveToFile(sdSave->FileName);
                nrePaper->Modified = false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPaper::pmCFontClick(TObject *Sender)
{
        fdFont->Font->Assign(nrePaper->SelAttributes);
        if(fdFont->Execute())
                nrePaper->SelAttributes->Assign(fdFont->Font);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmCColorClick(TObject *Sender)
{
        cdColor->Color = nrePaper->SelAttributes->Color;
        if(cdColor->Execute())
                nrePaper->SelAttributes->Color = cdColor->Color;
}
//---------------------------------------------------------------------------


void __fastcall TfrmPaper::pmCCutClick(TObject *Sender)
{
        nrePaper->CutToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmCCopyClick(TObject *Sender)
{
        nrePaper->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPaper::pmPasteClick(TObject *Sender)
{
        nrePaper->PasteFromClipboard();
}
//---------------------------------------------------------------------------

