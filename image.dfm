object fmImage: TfmImage
  Left = 0
  Top = 0
  Caption = #21407#26360#22294#27284
  ClientHeight = 528
  ClientWidth = 711
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -20
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  PixelsPerInch = 120
  TextHeight = 24
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 711
    Height = 65
    Align = alTop
    TabOrder = 0
    object btZoomIn: TButton
      Left = 8
      Top = 12
      Width = 75
      Height = 34
      Caption = #25918#22823
      TabOrder = 0
      OnClick = btZoomInClick
    end
    object btZoomOut: TButton
      Left = 104
      Top = 12
      Width = 75
      Height = 34
      Caption = #32302#23567
      TabOrder = 1
      OnClick = btZoomOutClick
    end
  end
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 65
    Width = 711
    Height = 463
    Align = alClient
    TabOrder = 1
    object Image1: TImage
      Left = 3
      Top = 4
      Width = 542
      Height = 397
      Stretch = True
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
      OnMouseUp = Image1MouseUp
    end
  end
end
