object Form1: TForm1
  Left = 327
  Top = 295
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Analise Gramatical'
  ClientHeight = 232
  ClientWidth = 618
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 184
    Top = 8
    Width = 270
    Height = 37
    Caption = 'An'#225'lise Gramatical'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 192
    Width = 46
    Height = 13
    Caption = 'Senten'#231'a'
  end
  object frase: TEdit
    Left = 64
    Top = 192
    Width = 449
    Height = 21
    OEMConvert = True
    TabOrder = 0
  end
  object radio: TRadioGroup
    Left = 8
    Top = 48
    Width = 601
    Height = 129
    TabOrder = 1
  end
  object um: TRadioButton
    Left = 16
    Top = 72
    Width = 561
    Height = 17
    Caption = 'S -> [L] | a      L -> S; L | S      (exemplo do professor)'
    TabOrder = 2
  end
  object dois: TRadioButton
    Left = 16
    Top = 96
    Width = 577
    Height = 17
    Caption = 'S -> S+T | T     T -> F*T | F     F -> a | (S)'
    TabOrder = 3
  end
  object tres: TRadioButton
    Left = 16
    Top = 120
    Width = 577
    Height = 17
    Caption = 'E -> EvT | T      T -> T && F | F     F -> not F | d'
    TabOrder = 4
  end
  object quatro: TRadioButton
    Left = 16
    Top = 144
    Width = 585
    Height = 17
    Caption = 'S -> S => S | not S | (S) | p | q'
    TabOrder = 5
  end
  object BitBtn1: TBitBtn
    Left = 528
    Top = 192
    Width = 75
    Height = 25
    Caption = 'Testar'
    TabOrder = 6
    OnClick = BitBtn1Click
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
      555555555555555555555555555555555555555555FF55555555555559055555
      55555555577FF5555555555599905555555555557777F5555555555599905555
      555555557777FF5555555559999905555555555777777F555555559999990555
      5555557777777FF5555557990599905555555777757777F55555790555599055
      55557775555777FF5555555555599905555555555557777F5555555555559905
      555555555555777FF5555555555559905555555555555777FF55555555555579
      05555555555555777FF5555555555557905555555555555777FF555555555555
      5990555555555555577755555555555555555555555555555555}
    NumGlyphs = 2
  end
  object terminais: TStringGrid
    Left = 456
    Top = 8
    Width = 81
    Height = 120
    ColCount = 1
    FixedCols = 0
    RowCount = 20
    FixedRows = 0
    TabOrder = 7
    Visible = False
  end
  object token: TStringGrid
    Left = 536
    Top = 8
    Width = 73
    Height = 120
    ColCount = 1
    FixedCols = 0
    RowCount = 50
    FixedRows = 0
    TabOrder = 8
    Visible = False
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24)
  end
end
