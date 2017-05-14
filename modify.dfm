object fmModify: TfmModify
  Left = 0
  Top = 0
  Caption = #20462#35330
  ClientHeight = 274
  ClientWidth = 497
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -20
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 24
  object Label1: TLabel
    Left = 32
    Top = 27
    Width = 40
    Height = 24
    Caption = #21407#25991
  end
  object Label2: TLabel
    Left = 32
    Top = 83
    Width = 60
    Height = 24
    Caption = #20462#35330#25991
  end
  object Label3: TLabel
    Left = 32
    Top = 139
    Width = 40
    Height = 24
    Caption = #29702#30001
  end
  object edOrig: TEdit
    Left = 128
    Top = 24
    Width = 321
    Height = 32
    TabOrder = 0
  end
  object edModi: TEdit
    Left = 128
    Top = 80
    Width = 321
    Height = 32
    TabOrder = 1
  end
  object cbReason: TComboBox
    Left = 128
    Top = 136
    Width = 321
    Height = 32
    TabOrder = 2
  end
  object btOK: TButton
    Left = 192
    Top = 200
    Width = 105
    Height = 49
    Caption = #30906#23450
    TabOrder = 3
    OnClick = btOKClick
  end
  object btCancel: TButton
    Left = 344
    Top = 200
    Width = 105
    Height = 49
    Caption = #21462#28040
    TabOrder = 4
    OnClick = btCancelClick
  end
end
