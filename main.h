//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfmMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TTreeView *TreeView1;
	TSplitter *Splitter1;
	TButton *btLoadFile;
	TMemo *Memo1;
	TButton *Button1;
	void __fastcall btLoadFileClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall TreeView1DblClick(TObject *Sender);
	void __fastcall TreeView1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
private:	// User declarations
public:		// User declarations

    TTreeNode * TreeViewSelectNode;

	__fastcall TfmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmMain *fmMain;
//---------------------------------------------------------------------------
#endif
