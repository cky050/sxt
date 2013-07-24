

// IpcSearchDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestNetDll.h"
#include "IpcSearchDlg.h"
#include "comutil.h"

// CIpcSearchDlg �Ի���

IMPLEMENT_DYNAMIC(CIpcSearchDlg, CDialog)



CIpcSearchDlg::CIpcSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIpcSearchDlg::IDD, pParent)
{
}

CIpcSearchDlg::~CIpcSearchDlg()
{
}

void CIpcSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ipclist);
}


BEGIN_MESSAGE_MAP(CIpcSearchDlg, CDialog)
	ON_BN_CLICKED(IDC_STARTSEARCH, &CIpcSearchDlg::OnBnClickedStartsearch)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_MODIFY1, &CIpcSearchDlg::OnBnClickedModify1)
	ON_BN_CLICKED(IDC_MODIFY2, &CIpcSearchDlg::OnBnClickedModify2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()




void CIpcSearchDlg::OnBnClickedStartsearch()
{
	CString nowtext;
	GetDlgItemText(IDC_STARTSEARCH,nowtext);
	if(nowtext.Compare(_T("��ʼ����"))==0)
	{
		m_nLastCount=0;
		SetDlgItemText(IDC_STARTSEARCH,_T("ֹͣ����"));
		IP_NET_DVR_StartSearchIPC();
		m_nLastCount=0;
		m_ipclist.DeleteAllItems();
	}
	else
	{
		SetDlgItemText(IDC_STARTSEARCH,_T("��ʼ����"));
		IP_NET_DVR_StopSearchIPC();
	}
}


BOOL CIpcSearchDlg::OnInitDialog()
{
	m_nLastCount=0;
	CDialog::OnInitDialog();
	m_ipclist.InsertColumn(0,_T("SN"),0,200);
	m_ipclist.InsertColumn(1,_T("�豸����"),0,100);
	m_ipclist.InsertColumn(2,_T("IP��ַ"),0,200);
	m_ipclist.InsertColumn(3,_T("MAC��ַ"),0,200);

	m_ipclist.ModifyStyle(0, LVS_EX_FULLROWSELECT |  LVS_EX_CHECKBOXES);

	SetTimer(100,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CIpcSearchDlg::OnTimer(UINT_PTR nIDEvent)
{
	char buffer[10240];
	if(nIDEvent==100)
	{
		int nowcount=IP_NET_DVR_GetSearchIPCCount();
		if(nowcount>m_nLastCount)
		{
			for(int idx=m_nLastCount;idx<nowcount;idx++)
			{
				IPC_ENTRY info;
				int ErrorCode=IP_NET_DVR_GetIPCInfo(idx,&info);
				if(ErrorCode>=0)
				{//���ɹ���
					int newidx=m_ipclist.InsertItem(idx,_bstr_t(info.ipc_sn));
					m_ipclist.SetItemText(newidx,1,_bstr_t(info.deviceType));
					m_ipclist.SetItemText(newidx,2,_bstr_t(info.lanCfg.IPAddress));
					m_ipclist.SetItemText(newidx,3,_bstr_t(info.lanCfg.MACAddress));		
				}

				int xmlLen=IP_NET_DVR_GetIPCInfoXML(idx,NULL,0);

				if(xmlLen<0)
				{//���ɶ�

				}else if(xmlLen>10240)
				{//�ڴ治��

				}else
				{
					xmlLen=IP_NET_DVR_GetIPCInfoXML(idx,buffer,xmlLen+1);
					if(xmlLen>=0)
					{//�ɹ���

					}
				}
			}
			m_nLastCount=nowcount;
		}

		char countmsg[20];
		sprintf(countmsg,"����IPC������:%d��",m_nLastCount);
		SetDlgItemText(IDC_ALLCOUNTMSG,_bstr_t(countmsg));
	}
}

void CIpcSearchDlg::OnBnClickedModify1()
{
		IPC_ENTRY info;
		int idx=0;
		if(m_nLastCount<idx)
		{

		}

		int ErrorCode=IP_NET_DVR_GetIPCInfo(idx,&info);


		if(ErrorCode>=0)
		{//���ɹ���
			//��������޸�
			int Error=IP_NET_DVR_ModifyIPC(idx,&info);
			if(Error>=0)
			{
				MessageBox(_T("�޸ĳɹ�"));
			}else
			{
				MessageBox(_T("�޸�ʧ��"));
			}
		}
		else
		{
			MessageBox(_T("����������IPC���ٽ��д˲���"));
		}
}

void CIpcSearchDlg::OnBnClickedModify2()
{
	int idx=0;
	char buffer[10240];
	int xmlLen=IP_NET_DVR_GetIPCInfoXML(idx,NULL,0);
	if(xmlLen<0)
	{//���ɶ�

	}else if(xmlLen>10240)
	{//�ڴ治��

	}else
	{
		xmlLen=IP_NET_DVR_GetIPCInfoXML(idx,buffer,xmlLen+1);
		if(xmlLen>=0)
		{//�ɹ���
			//����Ҫ���޸�XML��Ȼ����������XML���ٽ����޸�
			int Error=IP_NET_DVR_ModifyIPCXML(idx,buffer);
			if(Error>=0)
			{
				MessageBox(_T("�޸ĳɹ�"));
			}else
			{
				MessageBox(_T("�޸�ʧ��"));
			}
		}
		else
		{
			MessageBox(_T("����������IPC���ٽ��д˲���"));
		}
	}
}

void CIpcSearchDlg::OnDestroy()
{
	IP_NET_DVR_StopSearchIPC();//ֹͣ����
	CDialog::OnDestroy();
}
