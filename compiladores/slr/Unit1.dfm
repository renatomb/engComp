object Form1: TForm1
  Left = 192
  Top = 107
  Width = 804
  Height = 612
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
  object Label1: TLabel
    Left = 8
    Top = 24
    Width = 64
    Height = 13
    Caption = 'N'#227'o terminais'
  end
  object Label2: TLabel
    Left = 120
    Top = 24
    Width = 97
    Height = 13
    Caption = 'Regras de produ'#231#227'o'
  end
  object Label3: TLabel
    Left = 8
    Top = 168
    Width = 49
    Height = 13
    Caption = 'Express'#227'o'
  end
  object Label4: TLabel
    Left = 352
    Top = 16
    Width = 57
    Height = 13
    Caption = 'Tabela SLR'
  end
  object slr: TStringGrid
    Left = 296
    Top = 32
    Width = 249
    Height = 153
    ColCount = 2
    DefaultColWidth = 35
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
  end
  object naoterm: TStringGrid
    Left = 8
    Top = 40
    Width = 89
    Height = 113
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 1
    OnSetEditText = naotermSetEditText
  end
  object nt_mais: TButton
    Left = 80
    Top = 8
    Width = 17
    Height = 17
    Caption = '+'
    TabOrder = 2
    OnClick = nt_maisClick
  end
  object nt_menos: TButton
    Left = 80
    Top = 24
    Width = 17
    Height = 17
    Caption = '-'
    TabOrder = 3
    OnClick = nt_menosClick
  end
  object regras: TStringGrid
    Left = 112
    Top = 40
    Width = 153
    Height = 113
    ColCount = 3
    DefaultColWidth = 40
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 4
    OnSetEditText = regrasSetEditText
  end
  object rg_mais: TButton
    Left = 248
    Top = 8
    Width = 17
    Height = 17
    Caption = '+'
    TabOrder = 5
    OnClick = rg_maisClick
  end
  object rg_menos: TButton
    Left = 248
    Top = 24
    Width = 17
    Height = 17
    Caption = '-'
    TabOrder = 6
    OnClick = rg_menosClick
  end
  object transicoes: TStringGrid
    Left = 656
    Top = 16
    Width = 129
    Height = 153
    ColCount = 1
    DefaultColWidth = 30
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 7
  end
  object slr_mais: TButton
    Left = 528
    Top = 0
    Width = 17
    Height = 17
    Caption = '+'
    TabOrder = 8
    OnClick = slr_maisClick
  end
  object slr_menos: TButton
    Left = 528
    Top = 16
    Width = 17
    Height = 17
    Caption = '-'
    TabOrder = 9
    OnClick = slr_menosClick
  end
  object status: TStringGrid
    Left = 8
    Top = 192
    Width = 777
    Height = 377
    ColCount = 3
    DefaultColWidth = 245
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 10
  end
  object inicia: TButton
    Left = 216
    Top = 160
    Width = 73
    Height = 25
    Caption = 'Valida'
    Default = True
    TabOrder = 11
    OnClick = iniciaClick
  end
  object exp: TEdit
    Left = 64
    Top = 160
    Width = 145
    Height = 21
    TabOrder = 12
  end
end
