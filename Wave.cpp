#include"stdafx.h"
#include"Wave.h"
#include<mmsystem.h>
#pragma comment (lib,"winmm.lib")
CWave::CWave()
{
	m_bOpened=FALSE;
	m_wDeviceID=0;
}
CWave::~CWave()
{
	Close();
}
BOOL CWave::Play(CWnd *pWnd)
{
	Stop();
	MCI_PLAY_PARMS playParms;
	playParms.dwCallback=(DWORD)pWnd->m_hWnd;
	mciSendCommand (m_wDeviceID, MCI_SEEK,MCI_SEEK_TO_START,NULL);
	if(mciSendCommand(m_wDeviceID,MCI_PLAY,MCI_NOTIFY,(DWORD)(LPVOID) &playParms))
		return FALSE;
	else 
		return TRUE;
}
void CWave::Stop()
{
	mciSendCommand (m_wDeviceID,MCI_STOP,NULL,NULL);
}
void CWave::Close()
{
	m_bOpened=FALSE;
	if(m_wDeviceID)
	{
		mciSendCommand(m_wDeviceID,MCI_STOP,MCI_WAIT,NULL);
		mciSendCommand(m_wDeviceID,MCI_CLOSE,NULL,NULL);
	}
	m_wDeviceID=0;
}
BOOL CWave::Open(CString waveFileName)
{
	if(m_bOpened)
		Close();
	MCI_OPEN_PARMS openParms;
	openParms.lpstrDeviceType="waveaudio";
	openParms.lpstrElementName=waveFileName;
	if(mciSendCommand(NULL,MCI_OPEN,MCI_OPEN_ELEMENT|MCI_OPEN_TYPE|MCI_WAIT,
		(DWORD)(LPVOID) &openParms))
		return FALSE;
	m_wDeviceID=openParms.wDeviceID;
	m_bOpened=TRUE;
	return TRUE;
}