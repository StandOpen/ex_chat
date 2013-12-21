 class CWave : public CObject
{
public:
	CWave();
	virtual ~CWave();
public:
	BOOL Open(CString waveFileName);
	void Close();
	void Stop();
	BOOL Play(CWnd *pWnd);
protected:
	WORD m_wDeviceID;
	BOOL m_bOpened;
};