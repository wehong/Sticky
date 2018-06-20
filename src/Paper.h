//---------------------------------------------------------------------------

#ifndef PaperH
#define PaperH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "NewRichEdit.h"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmPaper : public TForm
{
__published:	// IDE-managed Components
        TPopupMenu *pmPMenu;
        TMenuItem *pmExit;
        TMenuItem *pmFont;
        TFontDialog *fdFont;
        TColorDialog *cdColor;
        TMenuItem *pmColor;
        TMenuItem *pmTransparent;
        TTimer *tmTimer;
        TMenuItem *pmS4;
        TMenuItem *pmTimer;
        TMenuItem *pmS2;
        TMenuItem *pmS1;
        TMenuItem *pmClear;
        TMenuItem *pmOpen;
        TMenuItem *pmSave;
        TOpenDialog *odOpen;
        TSaveDialog *sdSave;
        TMenuItem *pmSaveAs;
        TNewRichEdit *nrePaper;
        TPopupMenu *pmCMenu;
        TMenuItem *pmCFont;
        TMenuItem *pmCColor;
        TMenuItem *pmS3;
        TMenuItem *pmLeft;
        TMenuItem *pmCenter;
        TMenuItem *pmRight;
        TMenuItem *pmCS1;
        TMenuItem *pmCCopy;
        TMenuItem *pmCCut;
        TMenuItem *pmS5;
        TMenuItem *pmPaste;
        void __fastcall WMGetMinMaxInfo(TWMGetMinMaxInfo &Msg);
        void __fastcall Create(TObject *Sender);
        void __fastcall pmExitClick(TObject *Sender);
        void __fastcall MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Resize(TObject *Sender);
        void __fastcall pmFontClick(TObject *Sender);
        void __fastcall pmColorClick(TObject *Sender);
        void __fastcall pmTransparentClick(TObject *Sender);
        void __fastcall Timer(TObject *Sender);
        void __fastcall pmTimerClick(TObject *Sender);
        void __fastcall pmClearClick(TObject *Sender);
        void __fastcall pmOpenClick(TObject *Sender);
        void __fastcall pmSaveClick(TObject *Sender);
        void __fastcall pmSaveAsClick(TObject *Sender);
        void __fastcall BlkClick(TObject *Sender);
        void __fastcall pmCFontClick(TObject *Sender);
        void __fastcall pmCColorClick(TObject *Sender);
        void __fastcall pmLeftClick(TObject *Sender);
        void __fastcall pmCenterClick(TObject *Sender);
        void __fastcall pmRightClick(TObject *Sender);
        void __fastcall pmCCutClick(TObject *Sender);
        void __fastcall pmCCopyClick(TObject *Sender);
        void __fastcall pmPasteClick(TObject *Sender);
        void __fastcall CreateParams(TCreateParams &Params);
private:	// User declarations
        bool bCheck;
        bool bEditable;
        TDateTime dtSettime;
public:		// User declarations
        __fastcall TfrmPaper(TComponent* Owner);

BEGIN_MESSAGE_MAP
        MESSAGE_HANDLER(WM_GETMINMAXINFO, TWMGetMinMaxInfo, WMGetMinMaxInfo)
END_MESSAGE_MAP(TForm);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPaper *frmPaper;
//---------------------------------------------------------------------------
#endif
