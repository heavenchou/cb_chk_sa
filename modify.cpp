//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modify.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmModify *fmModify;
//---------------------------------------------------------------------------
__fastcall TfmModify::TfmModify(TComponent* Owner)
	: TForm(Owner)
{
	cbReason->Items->LoadFromFile("Reason.txt",TEncoding::UTF8);
}
//---------------------------------------------------------------------------
void __fastcall TfmModify::btOKClick(TObject *Sender)
{
	if(edOrig->Text == edModi->Text)
	{
		ShowMessage("修訂文字沒有改變");
		return;
	}

	UnicodeString sOut = "<note>[" + edOrig->Text + ">" + edModi->Text + "]" + cbReason->Text + "</note>";

	fmMain->Memo1->SelText = edModi->Text;
	int iRow = SendMessage(fmMain->Memo1->Handle, EM_LINEFROMCHAR, fmMain->Memo1->SelStart, 0);

	fmMain->Memo1->Lines->Insert(iRow+1, sOut);

	// 把理由寫入 combobox

	int iIndex = cbReason->Items->IndexOf(cbReason->Text);
	cbReason->Items->Insert(0,cbReason->Text);
	if(iIndex != -1)
	{
		cbReason->Items->Delete(iIndex+1);
	}
	Close();

}
//---------------------------------------------------------------------------
void __fastcall TfmModify::btCancelClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TfmModify::FormClose(TObject *Sender, TCloseAction &Action)
{
	cbReason->Items->SaveToFile("Reason.txt",TEncoding::UTF8);
}
//---------------------------------------------------------------------------
