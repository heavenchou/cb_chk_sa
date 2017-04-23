//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmMain *fmMain;
//---------------------------------------------------------------------------
__fastcall TfmMain::TfmMain(TComponent* Owner)
	: TForm(Owner)
{
	TreeViewSelectNode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::btLoadFileClick(TObject *Sender)
{
	TreeView1->LoadFromFile("Y37_sa_tree.txt",TEncoding::UTF8);
	//Memo1->Lines->LoadFromFile("Y37n0037_pure.txt",TEncoding::UTF8);
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::Button1Click(TObject *Sender)
{
	ShowMessage(TreeView1->Selected->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::TreeView1DblClick(TObject *Sender)
{
	if(TreeViewSelectNode == 0) return;
	TTreeNode * SelectNode = TreeViewSelectNode;
	TreeViewSelectNode = 0;

	UnicodeString sStr = SelectNode->Text;

	int iPos = sStr.Pos(",");
	UnicodeString sStr2 = sStr.SubString(iPos+1,100);
	int iPos2 = sStr2.Pos(",");

	UnicodeString sStr3 = sStr2.SubString(iPos2+1,100);
	sStr2 = sStr2.SubString(1,iPos2-1);
	sStr = sStr.SubString(1,iPos-1);

	UnicodeString sss = sStr + "=" + sStr2 + "=" + sStr3;

	if(sStr2.ToIntDef(0)>0)
	{
        //Memo1->sc
    }

}
//---------------------------------------------------------------------------

void __fastcall TfmMain::TreeView1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	TreeViewSelectNode = 0;
	if(Button == mbRight) return;

	THitTests MyHitTest = TreeView1->GetHitTestInfoAt(X,Y);
	if (!MyHitTest.Contains(htOnItem))	return;

	TreeViewSelectNode = TreeView1->GetNodeAt(X, Y);
}
//---------------------------------------------------------------------------

