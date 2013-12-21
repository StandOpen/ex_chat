; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_ChatDlg
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_Chat.h"

ClassCount=4
Class1=CEx_ChatApp
Class2=CEx_ChatDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CChatSocket
Resource3=IDD_EX_CHAT_DIALOG

[CLS:CEx_ChatApp]
Type=0
HeaderFile=Ex_Chat.h
ImplementationFile=Ex_Chat.cpp
Filter=N

[CLS:CEx_ChatDlg]
Type=0
HeaderFile=Ex_ChatDlg.h
ImplementationFile=Ex_ChatDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON_SEND

[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_ChatDlg.h
ImplementationFile=Ex_ChatDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EX_CHAT_DIALOG]
Type=1
Class=CEx_ChatDlg
ControlCount=14
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_COMBO_TYPE,combobox,1344340226
Control4=IDC_BUTTON_RUN,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_LIST_MSG,listbox,1352728835
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_MSG,edit,1350631552
Control9=IDC_BUTTON_SEND,button,1342242817
Control10=IDC_EDIT1,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_BUTTON1,button,1342242816
Control13=IDC_COMBO_NUMBER,combobox,1344340226
Control14=IDC_STATIC,static,1342308352

[CLS:CChatSocket]
Type=0
HeaderFile=ChatSocket.h
ImplementationFile=ChatSocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CChatSocket

