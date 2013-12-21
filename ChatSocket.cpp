// ChatSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Chat.h"
#include "ChatSocket.h"
#include"Ex_ChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChatSocket

CChatSocket::CChatSocket()
{
}

CChatSocket::~CChatSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CChatSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CChatSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CChatSocket member functions

void CChatSocket::OnAccept(int nErrorCode) 
{
    if(nErrorCode==0)
		m_pDlg->OnAccept();
	CAsyncSocket::OnAccept(nErrorCode);
}

void CChatSocket::OnClose(int nErrorCode) 
{
   	if(nErrorCode==0)
		m_pDlg->DoClose();
	CAsyncSocket::OnClose(nErrorCode);
}

void CChatSocket::OnConnect(int nErrorCode) 
{
       if(nErrorCode==0)
		m_pDlg->OnConnect();	
	CAsyncSocket::OnConnect(nErrorCode);
}

void CChatSocket::OnReceive(int nErrorCode) 
{
      if(nErrorCode==0)
		m_pDlg->OnReceive();	
	CAsyncSocket::OnReceive(nErrorCode);
}
