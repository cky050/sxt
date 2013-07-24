#pragma once

#include "afxcmn.h"

#include "../NetSDKDLL/NetSDKDLL.h"
// CIpcSearchDlg �Ի���

class CIpcSearchDlg : public CDialog
{
	DECLARE_DYNAMIC(CIpcSearchDlg)

public:
	CIpcSearchDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CIpcSearchDlg();

// �Ի�������
	enum { IDD = IDD_IPCSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStartsearch();
public:
	CListCtrl m_ipclist;
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_nLastCount;
public:
	afx_msg void OnBnClickedModify1();
public:
	afx_msg void OnBnClickedModify2();
public:
	afx_msg void OnDestroy();
};
