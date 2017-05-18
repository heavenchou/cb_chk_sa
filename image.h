//---------------------------------------------------------------------------

#ifndef imageH
#define imageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfmImage : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *btZoomIn;
	TButton *btZoomOut;
	TScrollBox *ScrollBox1;
	TImage *Image1;
	void __fastcall btZoomInClick(TObject *Sender);
	void __fastcall btZoomOutClick(TObject *Sender);
	void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);

private:	// User declarations
public:		// User declarations

    bool MouseDown;
	int MouseDownX;
	int MouseDownY;

	__fastcall TfmImage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmImage *fmImage;
//---------------------------------------------------------------------------
#endif
