#pragma once
#include <map>
struct serverInfo { 
	CString serverName;
	CString serverPath;
};

class serverMgr
{
public:
	serverMgr();
	~serverMgr();

	serverInfo getServerItem(HTREEITEM item);
	CString getServerItemName(HTREEITEM item);
	CString getServerItemPath(HTREEITEM item);

	void  setServerItem(HTREEITEM item, CString name, CString path);
	void delServerItem(HTREEITEM item);
private:
	std::map<HTREEITEM, serverInfo> m_serverInfo;
};

