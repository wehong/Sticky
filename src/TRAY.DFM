object frmTray: TfrmTray
  Left = 192
  Top = 107
  Width = 783
  Height = 540
  Caption = 'Main'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = Create
  OnDestroy = Destroy
  OnShow = OnShow
  PixelsPerInch = 96
  TextHeight = 13
  object pmMenu: TPopupMenu
    object pmNew: TMenuItem
      Caption = #49352' '#51901#51648'(&N)'
      OnClick = pmNewClick
    end
    object pmS1: TMenuItem
      Caption = '-'
    end
    object pmAbout: TMenuItem
      Caption = #54532#47196#44536#47016' '#51221#48372'(&A)'
      OnClick = pmAboutClick
    end
    object pmS2: TMenuItem
      Caption = '-'
    end
    object pmExit: TMenuItem
      Caption = #51333#47308'(&X)'
      OnClick = pmExitClick
    end
  end
end
