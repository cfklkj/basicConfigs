#include "stdafx.h"
#include "serverMgr.h"


serverMgr::serverMgr()
{
}


serverMgr::~serverMgr()
{
}

serverInfo serverMgr::getServerItem(HTREEITEM item)
{
	auto iter = m_serverInfo.find(item);
	if (iter != m_serverInfo.end())
	{
		return iter->second;
	}
	serverInfo itemNull;
	return itemNull;
}

CString serverMgr::getServerItemName(HTREEITEM item)
{
	auto iter = m_serverInfo.find(item);
	if (iter != m_serverInfo.end())
	{
		return iter->second.serverName;
	}
	return L"";
}
CString serverMgr::getServerItemPath(HTREEITEM item)
{
	auto iter = m_serverInfo.find(item);
	if (iter != m_serverInfo.end())
	{
		return iter->second.serverPath;
	}
	return L"";
}

void  serverMgr::setServerItem(HTREEITEM item, CString name, CString path)
{
	m_serverInfo[item].serverName = name;
	m_serverInfo[item].serverPath = path;
}

void serverMgr::delServerItem(HTREEITEM item)
{
	auto iter = m_serverInfo.find(item);
	if (iter != m_serverInfo.end())
	{
		m_serverInfo.erase(iter);
	}
}