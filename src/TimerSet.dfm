object frmTimerSet: TfrmTimerSet
  Left = 470
  Top = 208
  ActiveControl = btnCancel
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = #50508#46988' '#49444#51221
  ClientHeight = 248
  ClientWidth = 282
  Color = clBtnFace
  Font.Charset = HANGEUL_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #44404#47548
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = Create
  PixelsPerInch = 96
  TextHeight = 12
  object gbTimerTime: TGroupBox
    Left = 8
    Top = 72
    Width = 265
    Height = 137
    Caption = ' '#50508#46988' '#49444#51221' '#49884#44036' '
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #44404#47548
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    object lbHour: TLabel
      Left = 112
      Top = 38
      Width = 12
      Height = 12
      Caption = #49884
    end
    object lbMin: TLabel
      Left = 176
      Top = 38
      Width = 12
      Height = 12
      Caption = #48516
    end
    object lbSec: TLabel
      Left = 240
      Top = 38
      Width = 12
      Height = 12
      Caption = #52488
    end
    object lbIsSet: TLabel
      Left = 96
      Top = 64
      Width = 80
      Height = 12
      Caption = #49444#51221' '#46104#51648' '#50506#51020
      Font.Charset = HANGEUL_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #44404#47548
      Font.Style = []
      ParentFont = False
    end
  end
  object gbCurTime: TGroupBox
    Left = 8
    Top = 8
    Width = 265
    Height = 57
    Caption = ' '#54788#51116' '#49884#44036' '
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #44404#47548
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object btnAMPM: TButton
    Left = 24
    Top = 104
    Width = 49
    Height = 21
    Caption = #50724#51204
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #44404#47548
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = btnAMPMClick
  end
  object btnSet: TButton
    Left = 48
    Top = 168
    Width = 75
    Height = 25
    Caption = #49444#51221
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #44404#47548
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = btnSetClick
  end
  object cseHour: TCSpinEdit
    Left = 80
    Top = 104
    Width = 41
    Height = 21
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #44404#47548
    Font.Style = []
    MaxValue = 12
    ParentFont = False
    TabOrder = 2
  end
  object cseMin: TCSpinEdit
    Left = 144
    Top = 104
    Width = 41
    Height = 21
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #44404#47548
    Font.Style = []
    MaxValue = 59
    ParentFont = False
    TabOrder = 3
  end
  object cseSec: TCSpinEdit
    Left = 208
    Top = 104
    Width = 41
    Height = 21
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #44404#47548
    Font.Style = []
    MaxValue = 59
    ParentFont = False
    TabOrder = 4
  end
  object btnClear: TButton
    Left = 160
    Top = 168
    Width = 75
    Height = 25
    Caption = #54644#51228
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #44404#47548
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = btnClearClick
  end
  object RxClockCurrent: TRxClock
    Left = 48
    Top = 24
    Width = 185
    Height = 33
    BevelInner = bvNone
    BevelOuter = bvNone
    TwelveHour = True
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #44404#47548
    Font.Style = [fsBold]
    ParentFont = False
  end
  object btnCancel: TButton
    Left = 192
    Top = 216
    Width = 81
    Height = 25
    Caption = #52712#49548
    TabOrder = 9
    OnClick = btnCancelClick
  end
end
