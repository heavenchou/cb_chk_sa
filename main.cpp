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
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::btLoadFileClick(TObject *Sender)
{
	TreeView1->LoadFromFile("Y37_sa_tree.txt",TEncoding::UTF8);
	Memo1->Lines->LoadFromFile("Y37n0037_pure.txt",TEncoding::UTF8);

}
//---------------------------------------------------------------------------
