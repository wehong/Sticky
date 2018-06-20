//---------------------------------------------------------------------------

#include <vcl.h>
#include <shellapi.h>
#pragma hdrstop

#include "tray.h"
#include "Paper.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTray *frmTray;
//---------------------------------------------------------------------------
__fastcall TfrmTray::TfrmTray(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TfrmTray::AddTrayIcon()
{
        NOTIFYICONDATA icondata;
        memset(&icondata, 0, sizeof(icondata));
        icondata.cbSize = sizeof(icondata);
        icondata.hWnd = Handle;
        strncpy(icondata.szTip, "Sticky", sizeof(icondata.szTip));
        icondata.hIcon = Application->Icon->Handle;
        icondata.uCallbackMessage = iconmessage;
        icondata.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
        Shell_NotifyIcon(NIM_ADD, &icondata);
}

void TfrmTray::RemoveTrayIcon()
{
        NOTIFYICONDATA icondata;
        memset(&icondata, 0, sizeof(icondata));
        icondata.cbSize = sizeof(icondata);
        icondata.hWnd = Handle;
        Shell_NotifyIcon(NIM_DELETE, &icondata);
}

void __fastcall TfrmTray::WndProc(Messages::TMessage &Message)
{
        TPoint pt;
        if(Message.Msg == iconmessage)
        {
                if(Message.LParam == WM_LBUTTONDBLCLK)
                {
                        if(!CreateNewPaper())
                        {
                                Beep();
                                ShowMessage("새 쪽지 작성 중 에러가 발생했습니다");
                        }
                }
                if(Message.LParam == WM_RBUTTONDOWN)
                {
                        GetCursorPos(&pt);
                        pmMenu->Popup(pt.x, pt.y);
                }
                return;
        }
        TForm::WndProc(Message);
}
void __fastcall TfrmTray::Create(TObject *Sender)
{
        iconmessage = RegisterWindowMessage("IconNotify");
        AddTrayIcon();
}
//---------------------------------------------------------------------------
void __fastcall TfrmTray::Destroy(TObject *Sender)
{
        RemoveTrayIcon();
}
//---------------------------------------------------------------------------
void __fastcall TfrmTray::pmExitClick(TObject *Sender)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TfrmTray::pmNewClick(TObject *Sender)
{
        if(!CreateNewPaper())
        {
                Beep();
                ShowMessage("새 쪽지 작성 중 에러가 발생했습니다");
        }
}
//---------------------------------------------------------------------------

bool TfrmTray::CreateNewPaper()
{
        TfrmPaper *paper = new TfrmPaper(this);
        if(paper==NULL) return false;

        TRect Rect = Application->MainForm->BoundsRect;
        paper->Left = random(Rect.right);
        paper->Top = random(Rect.Bottom);

        switch(random(7))
        {
                case 0:
                        paper->nrePaper->Color = clCream;
                        break;
                case 1:
                        paper->nrePaper->Color = clYellow;
                        break;
                case 2:
                        paper->nrePaper->Color = clAqua;
                        break;
                case 3:
                        paper->nrePaper->Color = clLime;
                        break;
                case 4:
                        paper->nrePaper->Color = clGrayText;
                        break;
                case 5:
                        paper->nrePaper->Color = clFuchsia;
                        break;
                case 6:
                        paper->nrePaper->Color = clMoneyGreen;
                        break;
        }

        paper->Show();
        return true;
}
void __fastcall TfrmTray::pmAboutClick(TObject *Sender)
{
        TfrmAbout *about = new TfrmAbout(this);
        TRect Rect = Application->MainForm->BoundsRect;

        about->Left = ((Rect.right-Rect.left)-about->Width)/2 + Rect.left;
        about->Top = ((Rect.Bottom-Rect.top)-about->Width)/2 + Rect.top;
        about->ShowModal();
        delete about;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTray::OnShow(TObject *Sender)
{
        ShowWindow(Application->Handle, SW_HIDE);        
}
//---------------------------------------------------------------------------

