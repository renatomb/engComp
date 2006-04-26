object Form1: TForm1
  Left = 266
  Top = 165
  Width = 416
  Height = 173
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 121
    Top = 18
    Width = 186
    Height = 29
    Caption = 'Faltou Energia!!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label2: TLabel
    Left = 129
    Top = 18
    Width = 148
    Height = 29
    Caption = 'Energizado!!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label3: TLabel
    Left = 5
    Top = 50
    Width = 131
    Height = 13
    Caption = 'Status do sistema de e-mail:'
  end
  object conec: TShape
    Left = 25
    Top = 70
    Width = 26
    Height = 26
    Shape = stCircle
  end
  object Label4: TLabel
    Left = 15
    Top = 100
    Width = 42
    Height = 13
    Caption = 'Conexão'
  end
  object env: TShape
    Left = 80
    Top = 70
    Width = 26
    Height = 26
    Shape = stCircle
  end
  object Label5: TLabel
    Left = 80
    Top = 100
    Width = 27
    Height = 13
    Caption = 'Envio'
  end
  object Label6: TLabel
    Left = 135
    Top = 127
    Width = 143
    Height = 13
    Caption = '(C) 2003 - RMB / MGV / WCL'
    OnClick = Label6Click
  end
  object Button1: TButton
    Left = 161
    Top = 52
    Width = 113
    Height = 25
    Caption = 'Ligar todos os LEDS'
    TabOrder = 0
    Visible = False
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 281
    Top = 52
    Width = 121
    Height = 25
    Caption = 'Apagra todos os LEDS'
    TabOrder = 1
    Visible = False
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 280
    Top = 100
    Width = 120
    Height = 25
    Caption = 'Visualizar eventos'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 3
  end
  object SMTP: TNMSMTP
    Host = '127.0.0.1'
    Port = 25
    ReportLevel = 0
    OnDisconnect = SMTPDisconnect
    OnConnect = SMTPConnect
    OnConnectionFailed = SMTPConnectionFailed
    UserID = 'swordfish'
    PostMessage.FromAddress = 'rmb@unp.br'
    PostMessage.FromName = 'RMB'
    PostMessage.ToAddress.Strings = (
      'mano@oskarat.com.br')
    PostMessage.Body.Strings = (
      'Ocorreu uma falha eletrica no sistema.')
    PostMessage.Subject = 'Alerta do sistema'
    EncodeType = uuMime
    ClearParams = False
    SubType = mtPlain
    Charset = 'us-ascii'
    OnSendStart = SMTPSendStart
    OnSuccess = SMTPSuccess
    OnFailure = SMTPFailure
    Left = 32
    Top = 3
  end
  object dsinsere: TDataSource
    DataSet = qinsere
    Left = 340
    Top = 5
  end
  object Database1: TDatabase
    AliasName = 'sme'
    Connected = True
    DatabaseName = 'dbinsere'
    LoginPrompt = False
    SessionName = 'Default'
    Left = 375
  end
  object qinsere: TQuery
    DatabaseName = 'dbinsere'
    Left = 65
    Top = 5
  end
end
