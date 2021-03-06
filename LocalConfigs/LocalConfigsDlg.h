
// LocalConfigsDlg.h: 头文件
//

#pragma once

#include "configs.h"
#include "Wnds.h"
#include "configApp.h"
#include "serverMgr.h"

// CLocalConfigsDlg 对话框
class CLocalConfigsDlg : public CDialogEx
{
// 构造
public:
	CLocalConfigsDlg(CWnd* pParent = nullptr);	// 标准构造函数

	void openConfig(CString path);
	void upConfig();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOCALCONFIGS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	configs* Config() { return &m_config; };
	Wnds* Wnd() { return &m_wnd; };
	configApp* ConfigApp() { return &m_configApp; };
	serverMgr* ServerMgr() { return &m_serverMgr; };
private:
	configs m_config;  //服务器配置
	Wnds m_wnd;
	configApp m_configApp;
	serverMgr m_serverMgr;
// 实现
protected:
	HICON m_hIcon;
	HTREEITEM m_selectItem;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1(); 
	afx_msg void OnNMRClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButton2();
};
