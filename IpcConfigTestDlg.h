#pragma once

#include "resource.h" 
#include "CDIPCConfigOcx.h"
#include "afxcmn.h"

// CtestipcconfigDlg �Ի���
class CIpcConfigTestDlg : public CDialog
{
// ����
public:
	CIpcConfigTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TESTIPCCONFIG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CIPCConfigOcx * m_pDlg;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedReload();
	afx_msg void OnBnClickedCh();
	afx_msg void OnBnClickedEn();
	CTreeCtrl m_PtzLoginTree;
	afx_msg void OnDestroy();
};
