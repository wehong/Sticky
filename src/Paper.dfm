object frmPaper: TfrmPaper
  Left = 607
  Top = 200
  BorderStyle = bsNone
  Caption = #51901#51648
  ClientHeight = 200
  ClientWidth = 250
  Color = clBtnFace
  Font.Charset = HANGEUL_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #44404#47548
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = Create
  OnResize = Resize
  PixelsPerInch = 96
  TextHeight = 12
  object nrePaper: TNewRichEdit
    Left = 0
    Top = 0
    Width = 250
    Height = 200
    Hint = #45908#48660#53364#47533#54616#47732' '#51060#46041#54624' '#49688' '#51080#49845#45768#45796
    Align = alClient
    Color = clCream
    ImeName = #54620#44397#50612' '#51077#47141' '#49884#49828#53596' (IME 2000)'
    TabOrder = 0
    OnMouseDown = MouseDown
    OnMouseMove = MouseMove
    OnDblClick = BlkClick
  end
  object pmPMenu: TPopupMenu
    object pmClear: TMenuItem
      Caption = #54788#51116' '#45236#50857' '#51648#50864#44592'(&N)'
      OnClick = pmClearClick
    end
    object pmOpen: TMenuItem
      Caption = #50676#44592'(&O)...'
      OnClick = pmOpenClick
    end
    object pmSave: TMenuItem
      Caption = #51200#51109#54616#44592'(&S)...'
      OnClick = pmSaveClick
    end
    object pmSaveAs: TMenuItem
      Caption = #45796#47480' '#51060#47492#51004#47196' '#51200#51109'(&A)...'
      OnClick = pmSaveAsClick
    end
    object pmS1: TMenuItem
      Caption = '-'
    end
    object pmFont: TMenuItem
      Caption = #44544#44852' '#48148#44984#44592'(&F)...'
      OnClick = pmFontClick
    end
    object pmColor: TMenuItem
      Caption = #48176#44221#49353' '#48148#44984#44592'(&B)...'
      OnClick = pmColorClick
    end
    object pmTransparent: TMenuItem
      Caption = #48152#53804#47749#54616#44172'(&P)'
      OnClick = pmTransparentClick
    end
    object pmS2: TMenuItem
      Caption = '-'
    end
    object pmPaste: TMenuItem
      Caption = #48537#50668#45347#44592'(&T)'
      OnClick = pmPasteClick
    end
    object pmS3: TMenuItem
      Caption = '-'
    end
    object pmLeft: TMenuItem
      Caption = #51340#52769#51221#47148'(&L)'
      OnClick = pmLeftClick
    end
    object pmCenter: TMenuItem
      Caption = #51473#50521#51221#47148'(&J)'
      OnClick = pmCenterClick
    end
    object pmRight: TMenuItem
      Caption = #50864#52769#51221#47148'(&R)'
      OnClick = pmRightClick
    end
    object pmS4: TMenuItem
      Caption = '-'
    end
    object pmTimer: TMenuItem
      Caption = #50508#46988' '#49444#51221'(&E)...'
      OnClick = pmTimerClick
    end
    object pmS5: TMenuItem
      Caption = '-'
    end
    object pmExit: TMenuItem
      Caption = #45803#44592'(&X)'
      OnClick = pmExitClick
    end
  end
  object fdFont: TFontDialog
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #44404#47548
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 128
  end
  object cdColor: TColorDialog
    Ctl3D = True
    Left = 160
  end
  object tmTimer: TTimer
    OnTimer = Timer
    Left = 192
  end
  object odOpen: TOpenDialog
    Filter = 'RTF '#47928#49436'|*.rtf|TXT '#47928#49436'|*.txt|'#47784#46304' '#47928#49436'|*.*'
    Left = 64
  end
  object sdSave: TSaveDialog
    Filter = #47784#46304' '#54028#51068'|*.*'
    Left = 96
  end
  object pmCMenu: TPopupMenu
    Left = 32
    object pmCCut: TMenuItem
      Caption = #51096#46972#45236#44592'(&T)'
      OnClick = pmCCutClick
    end
    object pmCCopy: TMenuItem
      Caption = #48373#49324'(&C)'
      OnClick = pmCCopyClick
    end
    object pmCS1: TMenuItem
      Caption = '-'
    end
    object pmCFont: TMenuItem
      Caption = #44544#44852' '#48320#44221'(&F)...'
      OnClick = pmCFontClick
    end
    object pmCColor: TMenuItem
      Caption = #47928#51088' '#49353#49345' '#48320#44221'(&C)...'
      OnClick = pmCColorClick
    end
  end
end
