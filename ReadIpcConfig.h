
#pragma once


class CTestNetDllDlg;
// CReadIpcConfig �Ի���

class CReadIpcConfig : public CDialog
{
	DECLARE_DYNAMIC(CReadIpcConfig)

public:
	CReadIpcConfig(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CReadIpcConfig();

// �Ի�������
	enum { IDD = IDD_IPCCONFIGREADER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedReadconfig();
	afx_msg void OnSystemControl();
	int OnAUXResponse(LONG lUser,LONG nStateCode,char *pResponse);
private:
	CTestNetDllDlg * m_parent;
	int m_lastSendCmd;
};
