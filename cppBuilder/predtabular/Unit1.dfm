object Form1: TForm1
  Left = 81
  Top = 184
  Width = 812
  Height = 565
  Caption = 'Método preditivo tabular'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 162
    Height = 13
    Caption = 'Informe a quantidade de terminais:'
  end
  object Label2: TLabel
    Left = 8
    Top = 40
    Width = 145
    Height = 13
    Caption = 'Informe a qtd de não-terminais:'
  end
  object Label3: TLabel
    Left = 264
    Top = 8
    Width = 45
    Height = 13
    Caption = 'Terminais'
  end
  object Label4: TLabel
    Left = 376
    Top = 8
    Width = 68
    Height = 13
    Caption = 'Não Terminais'
  end
  object Label5: TLabel
    Left = 8
    Top = 80
    Width = 95
    Height = 13
    Caption = 'Expressão a validar:'
  end
  object msgp: TLabel
    Left = 8
    Top = 128
    Width = 3
    Height = 13
  end
  object qtok: TEdit
    Left = 184
    Top = 8
    Width = 33
    Height = 21
    TabOrder = 0
  end
  object qfun: TEdit
    Left = 184
    Top = 40
    Width = 33
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 144
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Definir'
    TabOrder = 2
    OnClick = Button1Click
  end
  object token: TStringGrid
    Left = 232
    Top = 24
    Width = 97
    Height = 113
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 3
    OnDblClick = tokenDblClick
  end
  object func: TStringGrid
    Left = 360
    Top = 24
    Width = 97
    Height = 113
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 4
    OnDblClick = funcDblClick
    RowHeights = (
      24)
  end
  object Button2: TButton
    Left = 336
    Top = 24
    Width = 17
    Height = 113
    Caption = 'L'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 464
    Top = 24
    Width = 17
    Height = 113
    Caption = 'L'
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 232
    Top = 144
    Width = 249
    Height = 25
    Caption = 'Gerar tabela'
    TabOrder = 7
    OnClick = Button4Click
  end
  object tabela: TStringGrid
    Left = 488
    Top = 8
    Width = 297
    Height = 161
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 8
  end
  object exp: TEdit
    Left = 8
    Top = 96
    Width = 217
    Height = 21
    TabOrder = 9
  end
  object Button5: TButton
    Left = 8
    Top = 152
    Width = 217
    Height = 17
    Caption = 'Validar'
    TabOrder = 10
    OnClick = Button5Click
  end
  object proc: TStringGrid
    Left = 16
    Top = 184
    Width = 769
    Height = 329
    ColCount = 3
    FixedCols = 0
    RowCount = 2
    TabOrder = 11
    ColWidths = (
      205
      329
      206)
  end
  object vazio: TEdit
    Left = 15
    Top = 60
    Width = 31
    Height = 21
    TabOrder = 12
    Text = '#'
  end
end
