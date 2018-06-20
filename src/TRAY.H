//---------------------------------------------------------------------------

#ifndef trayH
#define trayH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>

//---------------------------------------------------------------------------
class TfrmTray : public TForm
{
__published:	// IDE-managed Components
        TPopupMenu *pmMenu;
        TMenuItem *pmNew;
        TMenuItem *pmS2;
        TMenuItem *pmExit;
        TMenuItem *pmAbout;
        TMenuItem *pmS1;
        void __fastcall Create(TObject *Sender);
        void __fastcall Destroy(TObject *Sender);
        void __fastcall pmExitClick(TObject *Sender);
        void __fastcall pmNewClick(TObject *Sender);
        void __fastcall pmAboutClick(TObject *Sender);
        void __fastcall OnShow(TObject *Sender);
private:	// User declarations
        unsigned int iconmessage;
        void AddTrayIcon();
        void RemoveTrayIcon();
        bool CreateNewPaper();
protected:
        virtual void __fastcall WndProc(Messages::TMessage &Message);
public:		// User declarations
        __fastcall TfrmTray(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTray *frmTray;
//---------------------------------------------------------------------------
#endif
