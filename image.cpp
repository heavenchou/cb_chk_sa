//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "image.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmImage *fmImage;
//---------------------------------------------------------------------------
__fastcall TfmImage::TfmImage(TComponent* Owner)
	: TForm(Owner)
{
	MouseDown = false;
}
//---------------------------------------------------------------------------
void __fastcall TfmImage::btZoomInClick(TObject *Sender)
{
	Image1->Width = Image1->Width + Image1->Picture->Width * 0.1;
	Image1->Height = Image1->Height + Image1->Picture->Height * 0.1;

}
//---------------------------------------------------------------------------
void __fastcall TfmImage::btZoomOutClick(TObject *Sender)
{
	Image1->Width = Image1->Width - Image1->Picture->Width * 0.1;
	Image1->Height = Image1->Height - Image1->Picture->Height * 0.1;
}
//---------------------------------------------------------------------------
void __fastcall TfmImage::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
	ScrollBox1->VertScrollBar->Position += 100;
}
//---------------------------------------------------------------------------
void __fastcall TfmImage::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
	ScrollBox1->VertScrollBar->Position -= 100;
}
//---------------------------------------------------------------------------
void __fastcall TfmImage::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	if(MouseDown)
	{
		int XDiff = MouseDownX - X;
		ScrollBox1->HorzScrollBar->Position += XDiff;

		int YDiff = MouseDownY - Y;
		ScrollBox1->VertScrollBar->Position += YDiff;
	}
}
//---------------------------------------------------------------------------
void __fastcall TfmImage::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	MouseDown = true;
	MouseDownX = X;
	MouseDownY = Y;

    fmImage->SetZOrder(true);
}
//---------------------------------------------------------------------------
void __fastcall TfmImage::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	MouseDown = false;
}
//---------------------------------------------------------------------------
