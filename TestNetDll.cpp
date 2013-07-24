// TestNetDll.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "TestNetDll.h"
#include "TestNetDllDlg.h"


#include "WavFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestNetDllApp

BEGIN_MESSAGE_MAP(CTestNetDllApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTestNetDllApp ����

CTestNetDllApp::CTestNetDllApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CTestNetDllApp ����

CTestNetDllApp theApp;


// CTestNetDllApp ��ʼ��

BOOL CTestNetDllApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	CWavFile file;
	WAVEFORMAT formt;
	file.Open(&formt,"");

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CTestNetDllDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˴����ô����ʱ�á�ȷ�������ر�
		//  �Ի���Ĵ���
		//MessageBox("INT_PTR nResponse = dlg.DoModal();\n if (nResponse == IDOK)\n");
		//MessageBox(this,"aa","ss",MB_OK);
		//MessageBox(NULL,_T("Not enough timers available for this window."),_T("Sound Test "), MB_OK);
		::MessageBoxA(NULL,"asdf","dd",MB_OK);
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ�á�ȡ�������ر�
		//  �Ի���Ĵ���
		//MessageBox("INT_PTR nResponse = dlg.DoModal();\n nResponse == IDCANCEL\n");
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
