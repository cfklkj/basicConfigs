#include "stdafx.h"
#include "Wnds.h"
#include "resource.h"

Wnds::Wnds()
{
}


Wnds::~Wnds()
{
}

void Wnds::InitCtrl(CWnd* pWnd)
{
	m_pWnd = pWnd;
	CComboBox* box = (CComboBox*)m_pWnd->GetDlgItem(IDC_RoomType);
	box->AddString(L"普通房");
	box->AddString(L"朋友场");
	box->AddString(L"竞技场"); 

	CTreeCtrl* list = (CTreeCtrl*)m_pWnd->GetDlgItem(IDC_TREE1); 
	m_treeRoot = list->InsertItem(L"服务器:", TVI_ROOT); 
}

HTREEITEM Wnds::insertTreeItem(CString name)
{
	CTreeCtrl* list = (CTreeCtrl*)m_pWnd->GetDlgItem(IDC_TREE1);
	return list->InsertItem(name, m_treeRoot); 
}

void Wnds::treeItemExpand()
{
	CTreeCtrl* list = (CTreeCtrl*)m_pWnd->GetDlgItem(IDC_TREE1); 
	list->Expand(m_treeRoot, TVE_EXPAND);
}

void Wnds::delTreeItem(HTREEITEM item)
{
	CTreeCtrl* list = (CTreeCtrl*)m_pWnd->GetDlgItem(IDC_TREE1);
	list->DeleteItem(item);
}

void Wnds::selectTreeItem(HTREEITEM item)
{
	if (item == NULL)
		return;
	CTreeCtrl* list = (CTreeCtrl*)m_pWnd->GetDlgItem(IDC_TREE1);
	list->SelectItem(item);
}

void Wnds::setRoomType(int type)
{
	CComboBox* box = (CComboBox*)m_pWnd->GetDlgItem(IDC_RoomType);
	box->SetCurSel(type);
}

int Wnds::getRoomType()
{
	CComboBox* box = (CComboBox*)m_pWnd->GetDlgItem(IDC_RoomType);
	return box->GetCurSel();
}

void Wnds::setDayUp(bool isTrue)
{
	CButton* checkbox = (CButton*)m_pWnd->GetDlgItem(IDC_MasterReward);
	checkbox->SetCheck(isTrue);
}

bool Wnds::getDayUp()
{
	CButton* checkbox = (CButton*)m_pWnd->GetDlgItem(IDC_MasterReward);
	return checkbox->GetCheck();
}

void Wnds::setEdit(int ID, CString str)
{
	CEdit* edit = (CEdit*)m_pWnd->GetDlgItem(ID);
	if (str[0] == '"')
	{ 
		int end = str.GetLength();
		for (;str[end] != '"'; end--);
		edit->SetWindowText(str.Mid(1, --end));
	}
	else
	{
		edit->SetWindowText(str);
	}
}
CString Wnds::getEdit(int ID)
{
	CEdit* edit = (CEdit*)m_pWnd->GetDlgItem(ID);
	CString str;
	edit->GetWindowText(str);
	return str;
}

void Wnds::setConfigPath(CString str)
{
	setEdit(IDC_EDIT8, str);
}
void Wnds::setRouter(CString strIpPort)
{
	setEdit(IDC_EDIT1, strIpPort); 
}
CString Wnds::getRouter()
{ 
	return getEdit(IDC_EDIT1);
}

void Wnds::setDBsubscrib(CString strIpPort)
{
	setEdit(IDC_EDIT2, strIpPort);
}
CString Wnds::getDBsubscrib()
{
	return getEdit(IDC_EDIT2); 
}

void Wnds::setLogSubscrib(CString strIpPort)
{
	setEdit(IDC_EDIT3, strIpPort);
}
CString Wnds::getLogSubscrib()
{
	return getEdit(IDC_EDIT3);
}

void Wnds::setChargeServer(CString strIpPort)
{
	setEdit(IDC_EDIT4, strIpPort);
}
CString Wnds::getChargeServer()
{
	return getEdit(IDC_EDIT4);
}

void Wnds::setChargeSubscrib(CString strIpPort)
{
	setEdit(IDC_EDIT5, strIpPort);
}
CString Wnds::getChargeSubscrib()
{
	return getEdit(IDC_EDIT5);
}

void Wnds::setPlayerLogSubscrib(CString strIpPort)
{
	setEdit(IDC_EDIT6, strIpPort);
}
CString Wnds::getPlayerLogSubscrib()
{
	return getEdit(IDC_EDIT6);
}

void Wnds::setBrodcastSubscrib(CString strIpPort)
{
	setEdit(IDC_EDIT7, strIpPort); 
}
CString Wnds::getBrodcastSubscrib()
{
	return getEdit(IDC_EDIT7);
}
 