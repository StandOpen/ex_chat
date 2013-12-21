// Ex_ChatDlg.h : header file
//

#if !defined(AFX_EX_CHATDLG_H__18E6CED7_600D_45E1_89DB_1595015A9FB1__INCLUDED_)
#define AFX_EX_CHATDLG_H__18E6CED7_600D_45E1_89DB_1595015A9FB1__INCLUDED_

#include "ChatSocket.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_ChatDlg dialog
#include"ChatSocket.h"
#include "Wave.h"	// Added by ClassView
class CEx_ChatDlg : public CDialog
{
// Construction
public:
	CWave m_wave;
	void DoClose();
	void OnConnect();
	void OnReceive();
	void OnAccept();
	CChatSocket m_asClient;
	CChatSocket m_asServer;
	BOOL m_bServer;
	CEx_ChatDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_ChatDlg)
	enum { IDD = IDD_EX_CHAT_DIALOG };
	CComboBox	m_number;
	CListBox	m_listMsg;
	CComboBox	m_comboType;
	CString	m_strMsg;
	CString	m_ip;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ChatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_ChatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeComboType();
	afx_msg void OnClose();
	afx_msg void OnButtonRun();
	afx_msg void OnButtonSend();
	virtual void OnCancel();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton1();
	afx_msg void OnSelchangeComboNumber();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CHATDLG_H__18E6CED7_600D_45E1_89DB_1595015A9FB1__INCLUDED_)
