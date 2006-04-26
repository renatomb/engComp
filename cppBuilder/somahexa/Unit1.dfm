object Form1: TForm1
  Left = 192
  Top = 107
  Width = 544
  Height = 375
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 272
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Le optab'
    TabOrder = 0
    OnClick = Button1Click
  end
  object g1: TStringGrid
    Left = 0
    Top = 24
    Width = 217
    Height = 185
    ColCount = 3
    FixedCols = 0
    RowCount = 60
    FixedRows = 0
    TabOrder = 1
  end
end
