//---------------------------------------------------------------------------

#ifndef modifyH
#define modifyH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TfmModify : public TForm
{
__published:	// IDE-managed Components
	TEdit *edOrig;
	TEdit *edModi;
	TComboBox *cbReason;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *btOK;
	TButton *btCancel;
	void __fastcall btOKClick(TObject *Sender);
	void __fastcall btCancelClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TfmModify(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmModify *fmModify;
//---------------------------------------------------------------------------
#endif
