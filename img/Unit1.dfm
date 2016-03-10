object Form1: TForm1
  Left = 368
  Top = 338
  Width = 928
  Height = 471
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
  object DBImage1: TDBImage
    Left = 216
    Top = 64
    Width = 521
    Height = 329
    Stretch = True
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 56
    Top = 136
    Width = 75
    Height = 25
    Caption = 'BitBtn1'
    TabOrder = 1
    OnClick = BitBtn1Click
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 20
    OnTimer = Timer2Timer
    Left = 320
    Top = 24
  end
end
