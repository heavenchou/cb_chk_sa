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
	TSplitter *Splitter1;
	TButton *btLoadFile;
	TMemo *Memo1;
	TButton *btSaveFile;
	TImageList *ImageList1;
	TButton *btOK;
	TButton *btNoOK;
	TTreeView *TreeView1;
	TButton *btModify;
	TEdit *edFind;
	TButton *btFind;
	TLabel *lbFind;
	void __fastcall btLoadFileClick(TObject *Sender);
	void __fastcall TreeView1DblClick(TObject *Sender);
	void __fastcall TreeView1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btOKClick(TObject *Sender);
	void __fastcall btNoOKClick(TObject *Sender);
	void __fastcall btSaveFileClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btModifyClick(TObject *Sender);
	void __fastcall btFindClick(TObject *Sender);
private:	// User declarations
public:		// User declarations

    bool TreeView_Modified;
	TTreeNode * TreeViewSelectNode;

	TStringList * slSaDict_key; // 字典的單字
	TStringList * slSaDict_val; // 字典的內容

	void __fastcall check_treeview();
	void __fastcall LoadSanskritDict(UnicodeString sFileName);      // 載入梵文字典

	__fastcall TfmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmMain *fmMain;
//---------------------------------------------------------------------------
#endif
