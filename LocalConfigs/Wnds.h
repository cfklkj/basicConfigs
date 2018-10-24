#pragma once
#include<string>

class Wnds
{
public:
	Wnds();
	~Wnds();

	void InitCtrl(CWnd* pWnd);

	void setConfigPath(CString str);
	void setRoomType(int type);
	int getRoomType();
	void setDayUp(bool isTrue);
	bool getDayUp();

	void setRouter(CString strIpPort);
	CString getRouter();

	void setDBsubscrib(CString topic);
	CString getDBsubscrib();

	void setLogSubscrib(CString topic);
	CString getLogSubscrib();

	void setChargeServer(CString topic);
	CString getChargeServer(); 
	void setChargeSubscrib(CString topic);
	CString getChargeSubscrib();

	void setPlayerLogSubscrib(CString topic);
	CString getPlayerLogSubscrib();

	void setBrodcastSubscrib(CString topic);
	CString getBrodcastSubscrib();

	void treeItemExpand();
	HTREEITEM insertTreeItem(CString name);
	void delTreeItem(HTREEITEM item);
	void selectTreeItem(HTREEITEM item);
private:
	void setEdit(int ID, CString str);
	CString getEdit(int ID);
private:
	CWnd * m_pWnd;
	HTREEITEM m_treeRoot;
};

