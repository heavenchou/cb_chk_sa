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
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
//---------------------------------------------------------------------------
class TfmMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TTreeView *TreeView1;
	TSplitter *Splitter1;
	TButton *btLoadFile;
	TMemo *Memo1;
	TButton *btSaveFile;
	TImageList *ImageList1;
	TButton *btOK;
	TButton *btNoOK;
	void __fastcall btLoadFileClick(TObject *Sender);
	void __fastcall TreeView1DblClick(TObject *Sender);
	void __fastcall TreeView1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btOKClick(TObject *Sender);
	void __fastcall btNoOKClick(TObject *Sender);
	void __fastcall btSaveFileClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations

    bool TreeView_Modified;
	TTreeNode * TreeViewSelectNode;
	void __fastcall check_treeview();

	__fastcall TfmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmMain *fmMain;
//---------------------------------------------------------------------------
#endif
