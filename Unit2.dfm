object Form2: TForm2
  Left = 883
  Top = 948
  Width = 300
  Height = 400
  BorderWidth = 20
  Caption = 'Main Menu'
  Color = clBtnFace
  Constraints.MaxHeight = 400
  Constraints.MaxWidth = 300
  Constraints.MinHeight = 400
  Constraints.MinWidth = 300
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object BitBtn1: TBitBtn
    Left = 32
    Top = 80
    Width = 177
    Height = 65
    Caption = 'New Game'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 32
    Top = 160
    Width = 177
    Height = 65
    Caption = 'Best Scores'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = BitBtn2Click
  end
  object BitBtn3: TBitBtn
    Left = 32
    Top = 240
    Width = 177
    Height = 65
    Caption = 'Quit'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = BitBtn3Click
  end
  object StaticText1: TStaticText
    Left = 0
    Top = 8
    Width = 159
    Height = 44
    Alignment = taCenter
    Caption = 'Arkanoid!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  inline Frame3: TFrame3
    Left = 8
    Top = -3
    Width = 225
    Height = 324
    TabOrder = 4
    inherited Button1: TButton
      OnClick = Frame31Button1Click
    end
  end
end
