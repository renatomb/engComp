object Form1: TForm1
  Left = 124
  Top = 153
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = ' Simulador --> Assembler --> Linker --> Load'
  ClientHeight = 361
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  WindowState = wsMaximized
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 24
    Top = 24
    Width = 337
    Height = 497
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object Button1: TButton
    Left = 440
    Top = 24
    Width = 265
    Height = 25
    Caption = 'Por Gentileza, Aperte com Sutileza AQUI!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 440
    Top = 72
    Width = 81
    Height = 21
    TabOrder = 2
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 342
    Width = 628
    Height = 19
    Panels = <
      item
        Text = 'MGV / RMB / WCL / EMS'
        Width = 402
      end
      item
        Text = ' -->Software Básico<--'
        Width = 130
      end
      item
        Text = ' -->Professora: Nadja<--'
        Width = 130
      end
      item
        Width = 70
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object Edit2: TEdit
    Left = 536
    Top = 72
    Width = 73
    Height = 21
    TabOrder = 4
  end
  object Edit3: TEdit
    Left = 624
    Top = 72
    Width = 81
    Height = 21
    TabOrder = 5
  end
  object linha: TEdit
    Left = 448
    Top = 112
    Width = 41
    Height = 21
    TabOrder = 6
    Text = '0'
  end
  object conta: TEdit
    Left = 496
    Top = 112
    Width = 33
    Height = 21
    TabOrder = 7
  end
  object MainMenu1: TMainMenu
    Left = 544
    Top = 13
    object Arquivo1: TMenuItem
      Caption = 'Arquivo'
      object Abrir1: TMenuItem
        Caption = 'Abrir'
        OnClick = Abrir1Click
      end
      object Gravar1: TMenuItem
        Caption = 'Gravar'
        OnClick = Gravar1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 496
    Top = 13
  end
  object SaveDialog1: TSaveDialog
    Left = 448
    Top = 13
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 400
    Top = 16
  end
end
