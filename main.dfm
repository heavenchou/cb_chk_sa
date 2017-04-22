object fmMain: TfmMain
  Left = 0
  Top = 0
  Caption = #27298#26597#26805#25991#24037#20855
  ClientHeight = 594
  ClientWidth = 797
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object Splitter1: TSplitter
    Left = 169
    Top = 81
    Width = 7
    Height = 513
    ExplicitLeft = 162
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 797
    Height = 81
    Align = alTop
    TabOrder = 0
    object btLoadFile: TButton
      Left = 40
      Top = 21
      Width = 89
      Height = 41
      Caption = #38283#21855
      TabOrder = 0
      OnClick = btLoadFileClick
    end
  end
  object TreeView1: TTreeView
    Left = 0
    Top = 81
    Width = 169
    Height = 513
    Align = alLeft
    Indent = 19
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 176
    Top = 81
    Width = 621
    Height = 513
    Align = alClient
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
    ExplicitLeft = 344
    ExplicitTop = 344
    ExplicitWidth = 185
    ExplicitHeight = 89
  end
end
