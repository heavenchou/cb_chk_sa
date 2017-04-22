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
    Width = 0
    Height = 513
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
      Top = 16
      Width = 89
      Height = 41
      Caption = #38283#21855
      TabOrder = 0
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
  object RichEdit1: TRichEdit
    Left = 169
    Top = 81
    Width = 628
    Height = 513
    Align = alClient
    Font.Charset = CHINESEBIG5_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Zoom = 100
    ExplicitLeft = 175
    ExplicitWidth = 622
  end
end
