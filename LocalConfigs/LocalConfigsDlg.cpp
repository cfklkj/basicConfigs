
// LocalConfigsDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "LocalConfigs.h"
#include "LocalConfigsDlg.h"
#include "afxdialogex.h"
#include "CAddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP() 
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLocalConfigsDlg 对话框



CLocalConfigsDlg::CLocalConfigsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOCALCONFIGS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLocalConfigsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLocalConfigsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLocalConfigsDlg::OnBnClickedButton1) 
	ON_NOTIFY(NM_RCLICK, IDC_TREE1, &CLocalConfigsDlg::OnNMRClickTree1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CLocalConfigsDlg::OnTvnSelchangedTree1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLocalConfigsDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CLocalConfigsDlg 消息处理程序

BOOL CLocalConfigsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	Wnd()->InitCtrl(this);
	
	serverInfo infoItem; 
	int i = 1;
	HTREEITEM item = NULL;
	while (ConfigApp()->getServer(i, infoItem))
	{
		i++;
		item = Wnd()->insertTreeItem(infoItem.serverName);
		ServerMgr()->setServerItem(item, infoItem.serverName, infoItem.serverPath);
	} 
	Wnd()->treeItemExpand();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLocalConfigsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLocalConfigsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLocalConfigsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLocalConfigsDlg::openConfig(CString path)
{
	Config()->openConfig(path);
	Wnd()->setConfigPath(path);
	Wnd()->setRoomType(Config()->getRoomType());
	Wnd()->setRouter(Config()->getRouter());
	Wnd()->setDayUp(Config()->getDayUp());
	Wnd()->setDBsubscrib(Config()->getDBsubscrib());
	Wnd()->setLogSubscrib(Config()->getLogSubscrib());
	Wnd()->setPlayerLogSubscrib(Config()->getPlayerLogSubscrib());
	Wnd()->setBrodcastSubscrib(Config()->getBrodcastSubscrib());
	Wnd()->setChargeServer(Config()->getChargeServer());
	Wnd()->setChargeSubscrib(Config()->getChargeSubscrib());
}

void CLocalConfigsDlg::upConfig()
{ 
	Config()->setRoomType(Wnd()->getRoomType());
	Config()->setRouter(Wnd()->getRouter());
	Config()->setDayUp(Wnd()->getDayUp());
	Config()->setDBsubscrib(Wnd()->getDBsubscrib());
	Config()->setLogSubscrib(Wnd()->getLogSubscrib());
	Config()->setPlayerLogSubscrib(Wnd()->getPlayerLogSubscrib());
	Config()->setBrodcastSubscrib(Wnd()->getBrodcastSubscrib());
	Config()->setChargeServer(Wnd()->getChargeServer());
	Config()->setChargeSubscrib(Wnd()->getChargeSubscrib());
	Config()->closeConfig();
}

void CLocalConfigsDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	upConfig();
	MessageBox(L"执行了更新操作");
}
 
 

HTREEITEM GetSelectTree(CTreeCtrl *treeHwnd)
{
	CPoint pt;
	GetCursorPos(&pt);//得到当前鼠标的位置
	treeHwnd->ScreenToClient(&pt);//将屏幕坐标转换为客户区坐标
	HTREEITEM tree_Item = treeHwnd->HitTest(pt);//调用HitTest找到对应点击的树节点
	return tree_Item;
}

void CLocalConfigsDlg::OnNMRClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CTreeCtrl *treeHwnd = (CTreeCtrl*)GetDlgItem(IDC_TREE1);
	HTREEITEM curItem = m_selectItem = GetSelectTree(treeHwnd);
	NM_TREEVIEW* pNMtreeView = (NM_TREEVIEW*)pNMHDR;
	CMenu menu;
	VERIFY(menu.LoadMenu(IDR_MENU1));			//这里是我们在1中定义的MENU的文件名称
	DWORD dwPos = GetMessagePos();
	CPoint point(LOWORD(dwPos), HIWORD(dwPos));
	int index = 0;
	if (curItem == NULL || curItem == treeHwnd->GetRootItem())
	{
		index = 0;
	}
	else
	{
		index = 1;
	}
	CMenu* popup = menu.GetSubMenu(index);
	popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);

}


void CLocalConfigsDlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	CTreeCtrl *treeHwnd = (CTreeCtrl*)GetDlgItem(IDC_TREE1);
	HTREEITEM curItem = GetSelectTree(treeHwnd);  
	if (curItem != NULL && curItem != treeHwnd->GetRootItem())
	{ 		
		openConfig(ServerMgr()->getServerItemPath(curItem));
	} 
}


BOOL CLocalConfigsDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类


	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE))
		return 1; 
	if (pMsg->message == WM_COMMAND && pMsg->wParam == ID_Add) //添加服务节点
	{
	 	CAddDlg dlg;
		if (dlg.DoModal() == IDOK)
		{
			serverInfo infoItem;
			infoItem.serverName = dlg.getServerName();
			infoItem.serverPath = dlg.getFilePath();
			if (ConfigApp()->addServer(infoItem))
			{
				HTREEITEM item = Wnd()->insertTreeItem(infoItem.serverName);
				ServerMgr()->setServerItem(item, infoItem.serverName, infoItem.serverPath);
			}
			else
			{
				MessageBox(L"服务已存在...", L"添加失败!");
			}
		}
		return 1;
	}
	if (pMsg->message == WM_COMMAND && pMsg->wParam == ID_Del)  //删除服务节点
	{
		CTreeCtrl *treeHwnd = (CTreeCtrl*)GetDlgItem(IDC_TREE1);
		if (m_selectItem != NULL && m_selectItem != treeHwnd->GetRootItem())
		{
			serverInfo info = ServerMgr()->getServerItem(m_selectItem);
			ConfigApp()->delServer(info);
			ServerMgr()->delServerItem(m_selectItem);
			Wnd()->delTreeItem(m_selectItem);
		}
		return 1;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CLocalConfigsDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT8);
	CString path;
	edit->GetWindowText(path);
	CString wtemp = wcsrchr(path, '\\');
	path.Replace(wtemp, L"");
	ShellExecute(this->m_hWnd, L"open", path, NULL, NULL, SW_SHOW);
}
