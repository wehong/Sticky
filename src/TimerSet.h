//---------------------------------------------------------------------------

#ifndef TimerSetH
#define TimerSetH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "CSPIN.h"
#include "RXClock.hpp"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmTimerSet : public TForm
{
__published:	// IDE-managed Components
        TButton *btnAMPM;
        TButton *btnSet;
        TCSpinEdit *cseHour;
        TCSpinEdit *cseMin;
        TCSpinEdit *cseSec;
        TButton *btnClear;
        TRxClock *RxClockCurrent;
        TGroupBox *gbCurTime;
        TGroupBox *gbTimerTime;
        TLabel *lbHour;
        TLabel *lbMin;
        TLabel *lbSec;
        TButton *btnCancel;
        TLabel *lbIsSet;
        void __fastcall Create(TObject *Sender);
        void __fastcall btnAMPMClick(TObject *Sender);
        void __fastcall btnSetClick(TObject *Sender);
        void __fastcall btnClearClick(TObject *Sender);
        void __fastcall btnCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        int nResult;
        TDateTime st;
        __fastcall TfrmTimerSet(TComponent* Owner);
        __fastcall TfrmTimerSet(TComponent* Owner, TDateTime Ti, bool isSet);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTimerSet *frmTimerSet;
//---------------------------------------------------------------------------
#endif
