object Form2: TForm2
  Left = 126
  Top = 293
  Width = 782
  Height = 358
  Caption = 'Form2'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 25
    Top = 20
    Width = 141
    Height = 13
    Caption = 'Eventos ocorridos no sistema:'
  end
  object Label2: TLabel
    Left = 310
    Top = 310
    Width = 143
    Height = 13
    Caption = '(C) 2003 - RMB / MGV / WCL'
    OnClick = Label2Click
  end
  object DBGrid1: TDBGrid
    Left = 25
    Top = 40
    Width = 731
    Height = 251
    DataSource = dsconsulta
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object Button1: TButton
    Left = 680
    Top = 10
    Width = 75
    Height = 25
    Caption = 'Atualizar'
    TabOrder = 1
    OnClick = Button1Click
  end
  object dsconsulta: TDataSource
    DataSet = tbconsulta
    Left = 5
  end
  object tbconsulta: TTable
    Active = True
    AutoRefresh = True
    DatabaseName = 'dbconsulta'
    TableName = 'eventos'
    Left = 40
  end
  object dbconsulta: TDatabase
    AliasName = 'sme'
    Connected = True
    DatabaseName = 'dbconsulta'
    KeepConnection = False
    LoginPrompt = False
    ReadOnly = True
    SessionName = 'Default'
    Left = 75
  end
end
