// Ex_ChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Chat.h"
#include "Ex_ChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnSmall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ChatDlg dialog

CEx_ChatDlg::CEx_ChatDlg(CWnd* pParent /*=NULL*/)
: CDialog(CEx_ChatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEx_ChatDlg)
	m_strMsg = _T("");
	m_ip = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx_ChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_ChatDlg)
	DDX_Control(pDX, IDC_COMBO_NUMBER, m_number);
	DDX_Control(pDX, IDC_LIST_MSG, m_listMsg);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_comboType);
	DDX_Text(pDX, IDC_EDIT_MSG, m_strMsg);
	DDX_Text(pDX, IDC_EDIT1, m_ip);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEx_ChatDlg, CDialog)
//{{AFX_MSG_MAP(CEx_ChatDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_CBN_SELCHANGE(IDC_COMBO_TYPE, OnSelchangeComboType)
ON_WM_CLOSE()
ON_BN_CLICKED(IDC_BUTTON_RUN, OnButtonRun)
ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
ON_WM_LBUTTONDBLCLK()
ON_WM_TIMER()
ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
ON_CBN_SELCHANGE(IDC_COMBO_NUMBER, OnSelchangeComboNumber)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ChatDlg message handlers

BOOL CEx_ChatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetTimer(10,100,0);
	m_comboType.AddString("服务器");
    m_comboType.AddString("客户机");
	m_comboType.SetCurSel(0);
    m_number.AddString("语音");
    m_number.AddString("1000语音");
	m_number.AddString("1001语音");
    m_number.AddString("1002语音");
	m_number.AddString("1003语音");
    m_number.AddString("1004语音");
	m_number.AddString("1005语音");
    m_number.AddString("1006语音");
	m_number.AddString("1007语音");
    m_number.AddString("1008语音");
	m_number.AddString("1009语音");
    m_number.AddString("1010语音");
	m_number.AddString("1011语音");
    m_number.AddString("2000语音");
	m_number.AddString("2001语音");
    m_number.AddString("2002语音");
	m_number.AddString("2003语音");
	m_number.AddString("2004语音");
	m_number.AddString("2005语音");
	m_number.AddString("2006语音");
	m_number.AddString("2007语音");
	m_number.AddString("2008语音");
	m_number.AddString("2009语音");
	m_number.AddString("2010语音");
	m_number.AddString("2011语音");
	m_number.AddString("2012语音");
	m_number.SetCurSel(25);
	OnSelchangeComboType();
	m_asServer.m_pDlg=this;
	m_asClient.m_pDlg=this;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEx_ChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEx_ChatDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CBitmap m_bitmap;
		m_bitmap.LoadBitmap(IDB_BITMAP1);
		CDC memdc;
		memdc.CreateCompatibleDC(&dc);
		memdc.SelectObject(&m_bitmap);
		int width,height;
		BITMAP bmp;
		m_bitmap.GetBitmap(&bmp);
		width=bmp.bmWidth;
		height=bmp.bmHeight;
		CRect rect;
		this->GetClientRect(&rect);
		dc.StretchBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memdc,0,0,width,height,SRCCOPY);
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEx_ChatDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEx_ChatDlg::OnSelchangeComboType() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_comboType.GetCurSel();
	if(nIndex==CB_ERR)
		return;
	CString str;
	m_comboType.GetLBText(nIndex,str);
	if(str=="服务器")
	{
		m_bServer=TRUE;
		WSADATA wsd;
		WSAStartup(MAKEWORD(2,2),&wsd);
		DWORD nSize=MAX_COMPUTERNAME_LENGTH+1;
		char Buffer[MAX_COMPUTERNAME_LENGTH+1];
		GetComputerName(Buffer,&nSize);
		CString str="";
		struct hostent * pHost;
		pHost=gethostbyname(Buffer);
		for(int i=0;i<4;i++)
		{
			CString addr;
			if(i>0)
			{
				str+=".";
			}
			addr.Format("%u",(unsigned int)((unsigned char*)pHost->h_addr_list[0])[i]);
			str+=addr;
		}
		GetDlgItem(IDC_EDIT1)->SetWindowText(str);
		GetDlgItem(IDC_BUTTON_RUN)->SetWindowText("运行");
	}
	else
	{
		m_bServer=FALSE;
		GetDlgItem(IDC_EDIT1)->SetWindowText("");
		GetDlgItem(IDC_BUTTON_RUN)->SetWindowText("连接");
	}
	   
}

void CEx_ChatDlg::OnClose() 
{
	if(m_bServer)
		m_asServer.Close();
	else
		m_asClient.Close();
    OnCancel();	
	CDialog::OnClose();
}

void CEx_ChatDlg::OnAccept()
{
	m_asServer.Accept(m_asClient);
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
	
}

void CEx_ChatDlg::OnReceive()
{
	char *pBuf=new char[1025];
	int nBufSize=1024;
	int number;
	number=10585787;
	CString strReceived,stroff,strpanduan;
	CString strvoice="语音";
	int nRes=m_asClient.Receive(pBuf,nBufSize);
	pBuf[nRes]=NULL;
	strReceived=pBuf;
	if(nRes==SOCKET_ERROR)
	{
		AfxMessageBox("无法接受消息！");
		return;
	}
	for(int i=0;i<strReceived.GetLength();i++)
	{
		char charstring=strReceived[i];
		if(IsDBCSLeadByte(charstring))
		{
			strpanduan=strpanduan+charstring;
		}
	}
	if(strpanduan.Compare(strvoice)==0)
	{
	number=_ttoi(strReceived);
	}
	switch(number)
	{
	case 2:
		{
			CString str,strl;
			str="../Ex_Chat/wave/2.wav";
			if(m_wave.Open(str))
			{
				m_wave.Play(this);
				UpdateData(FALSE);
			}
			else
				MessageBox(str+"文件打不开或操作失败！");
			CRect rect;
			this->GetWindowRect(&rect);
			int off=20;
			for(int i=0;i<10;i++)
			{
				rect.OffsetRect(off,0);
				this->MoveWindow(&rect,true);
				if(off==-20)
					off=20;
				else
					off=-20;
				::Sleep(100);
			}
			break;
		}
	   case 1000:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1000.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 1001:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1001.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 1002:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1002.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 1003:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1003.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 1004:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1004.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 1005:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1005.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 1006:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1006.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 1007:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1007.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 1008:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1008.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 1009:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1009.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 1010:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1010.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 1011:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/1011.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2000:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2000.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2001:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2001.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2002:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2002.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2003:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2003.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2004:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2004.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2005:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2005.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2006:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2006.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2007:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2007.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2008:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2008.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2009:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2009.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2010:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2010.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2012:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2012.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }
		   case 2011:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/2011.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   break;
		   }

	   default:
		   {
			   CString str,strl;
			   str="../Ex_Chat/wave/system.wav";
			   if(m_wave.Open(str))
			   {
				   m_wave.Play(this);
				   UpdateData(FALSE);
			   }
			   else
				   MessageBox(str+"文件打不开或操作失败！");
			   if(m_bServer)
			   {
				   strReceived="来自客户机发送的消息："+strReceived;
				   m_listMsg.InsertString( -1, strReceived);
			   }
			   else
			   {
				   strReceived="来自服务器发送的消息："+strReceived;
				   m_listMsg.InsertString( -1, strReceived);
				   
			   }
		   }
	}
}

void CEx_ChatDlg::OnConnect()
{
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
	GetDlgItem(IDCANCEL)->EnableWindow(TRUE);
}

void CEx_ChatDlg::DoClose()
{
	OnClose();
}

void CEx_ChatDlg::OnButtonRun() 
{
	GetDlgItem(IDC_EDIT1)->GetWindowText(m_ip);
	GetDlgItem(IDC_COMBO_TYPE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_RUN)->EnableWindow(FALSE);
	if(m_bServer)
	{
		m_asServer.Create(2000);
		m_asServer.Listen();
	}
	else
	{
		m_asClient.Create();
		m_asClient.Connect(m_ip,2000);
		GetDlgItem(IDC_BUTTON_RUN)->SetWindowText("已连接");
	}
}

void CEx_ChatDlg::OnButtonSend() 
{
	UpdateData();
	if(m_strMsg.IsEmpty())
	{
		MessageBox("不能发送空消息！");
	}
	char *pBuf=new char[1025];
	int nBufSize=1024;
	int nLen=m_strMsg.GetLength();
	int nRes=m_asClient.Send(LPCTSTR(m_strMsg),nLen);
	if(nRes==SOCKET_ERROR)
	{
		AfxMessageBox("发送消息失败！");
	}
	if(m_bServer)
	{
		m_strMsg="从服务器发送的消息："+m_strMsg;
		m_listMsg.InsertString( -1, m_strMsg);
	}
	else
	{
		m_strMsg="从客户机发送的消息："+m_strMsg;
		m_listMsg.InsertString( -1, m_strMsg);
	}
	m_strMsg.Empty();
	UpdateData(FALSE);
}

void CEx_ChatDlg::OnCancel() 
{
    OnClose();
	OnCancel();
}

void CAboutDlg::OnSmall() 
{
	// TODO: Add your command handler code here
	PostMessage(WM_SYSCOMMAND,SC_MINIMIZE,0);
}

void CEx_ChatDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	PostMessage(WM_SYSCOMMAND,SC_MINIMIZE,0);
	CDialog::OnLButtonDblClk(nFlags, point);
}

void CEx_ChatDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	// TODO: Add your message handler code here and/or call default
	CRect rc;
	CRect rect;
	GetWindowRect(&rect);
	rc.CopyRect(&rect);
	CPoint point;
	GetCursorPos(&point);
	if(rect.top<0&&PtInRect(rect,point))
	{
		rect.top=0;
		MoveWindow(rect.left,rect.top,rc.Width(),rc.Height());
	}
	else if(rect.top>-3&&rect.top<3&&!PtInRect(rect,point))
	{
		rect.top=3-rect.Height();
		MoveWindow(rect.left,rect.top,rc.Width(),rc.Height());
	}
	CDialog::OnTimer(nIDEvent);
}

void CEx_ChatDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString m_str="2";
	m_str=m_str+"语音";
	char *pBuf=new char[1025];
	int nBufSize=1024;
	int nLen=m_str.GetLength();
	int nRes=m_asClient.Send(LPCTSTR(m_str),nLen);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
	Sleep(2000);
    GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
	m_strMsg.Empty();
	UpdateData(FALSE);
}

void CEx_ChatDlg::OnSelchangeComboNumber() 
{
	// TODO: Add your control notification handler code here
	CString strnumber;
	int l=m_number.GetCurSel();
	m_number.GetLBText( l, strnumber );
	if(strnumber.IsEmpty())
	{
		MessageBox("不能发送空消息！");
	}
	char *pBuf=new char[1025];
	int nBufSize=1024;
	int nLen=strnumber.GetLength();
	int nRes=m_asClient.Send(LPCTSTR(strnumber),nLen);
	if(nRes==SOCKET_ERROR)
	{
		AfxMessageBox("发送消息失败！");
	}
	strnumber.Empty();
}

