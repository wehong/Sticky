//---------------------------------------------------------------------------

#ifndef AboutH
#define AboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmAbout : public TForm
{
__published:	// IDE-managed Components
        TImage *imgIcon;
        TPanel *pnTitle;
        TLabel *lbVer;
        TLabel *lbAuthor;
        TLabel *lbSubtitle;
        TMemo *mmComment;
        TButton *btnOk;
        void __fastcall btnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAbout *frmAbout;
//---------------------------------------------------------------------------
#endif
