// CAddDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "LocalConfigs.h"
#include "CAddDlg.h"
#include "afxdialogex.h"


// CAddDlg 对话框

IMPLEMENT_DYNAMIC(CAddDlg, CDialogEx)

CAddDlg::CAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAddDlg 消息处理程序


void CAddDlg::OnBnClickedOk()
{
	GetDlgItem(IDC_EDIT1)->GetWindowText(m_serverName);
	GetDlgItem(IDC_EDIT2)->GetWindowText(m_filePath);
	if (m_serverName.IsEmpty() || (!m_filePath.IsEmpty() && !PathFileExists(m_filePath)))
	{
		MessageBox(L"填写信息错误！请重试");
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

CString CAddDlg::getServerName()
{
	return m_serverName;
}
CString CAddDlg::getFilePath()
{
	return m_filePath;
}

void CAddDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, L"脚本(*.json)|*.json", NULL,

		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,

		L"脚本(*.json)|*.json|(*.*)|*.*||", this);
	if (dlg.DoModal() == IDOK)
	{
		CString filePath = dlg.GetPathName();
		if (PathFileExists(filePath))
		{
			GetDlgItem(IDC_EDIT2)->SetWindowText(filePath);
		}
	}
}
