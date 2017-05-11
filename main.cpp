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
	TreeView_Modified = false;

	slSaDict_key = new TStringList(); // 字典的單字
	slSaDict_val = new TStringList(); // 字典的內容

	LoadSanskritDict("sanskrit.txt");   // 載入梵文字典
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::btLoadFileClick(TObject *Sender)
{
	Memo1->Lines->LoadFromFile("Y37_sa.txt",TEncoding::UTF8);
	TreeView1->LoadFromFile("Y37_sa_tree.txt",TEncoding::UTF8);
	check_treeview();
}

//---------------------------------------------------------------------------
// 文字有 + 都要打勾勾
void __fastcall TfmMain::check_treeview()
{
 	int iCount = TreeView1->Items->Count;

	for(int i=0; i<iCount; i++)
	{
		TTreeNode * tn = TreeView1->Items->Item[i];
		UnicodeString usLast = tn->Text.LastChar();
		if(usLast == "+")   // + 打勾
		{
			tn->ImageIndex = 1;
			tn->SelectedIndex = 1;
			tn->Text = tn->Text.SetLength(tn->Text.Length()-1);
		}
		else if(usLast == "=")  // = 灰色
		{
			tn->ImageIndex = 2;
			tn->SelectedIndex = 2;
			tn->Text = tn->Text.SetLength(tn->Text.Length()-1);
		}
	}

	// 檢查是不是符合字典的字

	for(int i=0; i<iCount; i++)
	{
		TTreeNode * tn = TreeView1->Items->Item[i];

		if(tn->HasChildren)
		{
			UnicodeString sWord = tn->Text;
			int iPos = sWord.Pos("(");
			sWord.SetLength(iPos-1);

			int ii;
			if(slSaDict_key->Find(sWord, ii))
			{
				tn->StateIndex = 3; // 加上紅圈
			}
        }

	}

	TreeView1->Refresh();
}

//---------------------------------------------------------------------------

void __fastcall TfmMain::TreeView1DblClick(TObject *Sender)
{
	if(TreeViewSelectNode == 0) return;
	TTreeNode * SelectNode = TreeViewSelectNode;
	TreeViewSelectNode = 0;

	UnicodeString sStr = SelectNode->Text;	// abc,p0001a01,10

	int iPos = sStr.Pos(",");
	UnicodeString sStr2 = sStr.SubString(iPos+1,100);
	int iPos2 = sStr2.Pos(",");

	// abc,p0001a01,10
	// sStr = "abc" 字串
	// sStr2 = "p0001a01" 行首資訊
	// sStr3 = 10 , 此字串的位移

	UnicodeString sStr3 = sStr2.SubString(iPos2+1,100);
	sStr2 = sStr2.SubString(1,iPos2-1);
	sStr = sStr.SubString(1,iPos-1);

	// treeview item 第三個字是此字的位移
	if(sStr3.ToIntDef(0)>=0)
	{
		int iPos = Memo1->Text.Pos(sStr2);

		int iPos2 = sStr3.ToIntDef(0);

		Memo1->SetFocus();
		Memo1->SelStart = iPos + iPos2 + 8; // +8 就是加上 p0001a01�� 這 8 個字
		Memo1->SelLength = sStr.Length();
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


void __fastcall TfmMain::btOKClick(TObject *Sender)
{
	int iCount = TreeView1->SelectionCount;

	for(int i=0; i<iCount; i++)
	{
		TTreeNode * tn = TreeView1->Selections[i];

		if(tn->HasChildren != true)
		{
			if(tn->ImageIndex == 0)
			{
				tn->ImageIndex = 1;
				tn->SelectedIndex = 1;
				TreeView_Modified = true;

				// 判斷 root 要不要 check

				bool bCheck = true;

				TTreeNode * tnRoot = tn->Parent;
				TTreeNode * tnChild = tnRoot->getFirstChild();

				while(tnChild)
				{
					if(tnChild->ImageIndex == 0)
					{
						bCheck = false;
						break;
					}
					tnChild = tnRoot->GetNextChild(tnChild);
				}

				if(bCheck)
				{
					tn->Parent->ImageIndex = 1;
					tn->Parent->SelectedIndex = 1;
				}
				else
				{
					tn->Parent->ImageIndex = 2;
					tn->Parent->SelectedIndex = 2;
				}
			}
		}
	}
	TreeView1->Repaint();
	TreeView1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btNoOKClick(TObject *Sender)
{
	int iCount = TreeView1->SelectionCount;

	for(int i=0; i<iCount; i++)
	{
		TTreeNode * tn = TreeView1->Selections[i];

		if(tn->HasChildren != true)
		{
			if(tn->ImageIndex != 0)
			{
				tn->ImageIndex = 0;
				tn->SelectedIndex = 0;
				TreeView_Modified = true;

				tn->Parent->ImageIndex = 0;
				tn->Parent->SelectedIndex = 0;

                // 判斷 root 要不要 check

				bool bCheck = false;

				TTreeNode * tnRoot = tn->Parent;
				TTreeNode * tnChild = tnRoot->getFirstChild();

				while(tnChild)
				{
					if(tnChild->ImageIndex == 1)
					{
						bCheck = true;
						break;
					}
					tnChild = tnRoot->GetNextChild(tnChild);
				}

				if(bCheck)
				{
					tn->Parent->ImageIndex = 2;
					tn->Parent->SelectedIndex = 2;
				}
				else
				{
					tn->Parent->ImageIndex = 0;
					tn->Parent->SelectedIndex = 0;
				}
            }
		}
	}
	TreeView1->Repaint();
	TreeView1->SetFocus();
}
//---------------------------------------------------------------------------
// 儲存資料
void __fastcall TfmMain::btSaveFileClick(TObject *Sender)
{
	if(TreeView_Modified)
	{
		int iCount = TreeView1->Items->Count;

		// 打勾的都加上 數字
		for(int i=0; i<iCount; i++)
		{
			TTreeNode * tn = TreeView1->Items->Item[i];
			if(tn->ImageIndex == 1)
				tn->Text = tn->Text + "+";
			else if(tn->ImageIndex == 2)
				tn->Text = tn->Text + "=";
		}
		// 儲存
		TreeView1->SaveToFile("Y37_sa_tree.txt",TEncoding::UTF8);
		TreeView_Modified = false;
		// 移除 數字 (1 打勾 , 2 灰色)
		for(int i=0; i<iCount; i++)
		{
			TTreeNode * tn = TreeView1->Items->Item[i];
			if(tn->ImageIndex == 1 || tn->ImageIndex == 2)
				tn->Text = tn->Text.SetLength(tn->Text.Length()-1);
		}
	}

	if(Memo1->Modified)
	{
		Memo1->Lines->SaveToFile("Y37_sa.txt",TEncoding::UTF8);
		Memo1->Modified = false;
    }

}
//---------------------------------------------------------------------------
void __fastcall TfmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	if(TreeView_Modified || Memo1->Modified)
	{
		WideString a =  "修改尚未儲存，儲存請按 Yes，不儲存請按 No";
		WideString b =  "是否存檔？";
		int iResult = Application->MessageBox(a.c_bstr(), b.c_bstr(), MB_YESNOCANCEL);

		if(iResult == IDCANCEL) Action = caNone;

		if(iResult == IDYES)
		{
			btSaveFile->Click();
			Action = caFree;
		}

		if(iResult == IDNO) Action = caFree;
	}
}
//---------------------------------------------------------------------------
// 載入梵文字典
void __fastcall TfmMain::LoadSanskritDict(UnicodeString sFileName)
{
	// 載入梵文字典

	slSaDict_key->LoadFromFile(sFileName, TEncoding::UTF8);

	for(int i=0; i< slSaDict_key->Count; i++)
	{
		UnicodeString sKey = slSaDict_key->Strings[i];
		int iPos = sKey.Pos(" ");
		sKey.SetLength(iPos-1);
		slSaDict_key->Strings[i] = sKey;
    }
	slSaDict_key->Sort();
}
