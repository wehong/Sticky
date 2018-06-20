//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("tray.cpp", frmTray);
USEFORM("Paper.cpp", frmPaper);
USEFORM("About.cpp", frmAbout);
USEFORM("TimerSet.cpp", frmTimerSet);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        HANDLE   mutex;
        try
        {
                 HANDLE hMutex;
                 hMutex = CreateMutex(NULL, true, "Sticky");
                 if(hMutex == 0 || GetLastError() != 0)
                         return 0;

                 Application->Initialize();
                 ShowWindow(Application->Handle, SW_HIDE);
                 Application->ShowMainForm = false;
                 Application->Title = "Sticky";
                 Application->CreateForm(__classid(TfrmTray), &frmTray);
                 Application->Run();

                 if(hMutex != 0) CloseHandle(hMutex); 
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
