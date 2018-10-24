#include "stdafx.h"
#include "configApp.h"
#include "Util.h"


configApp::configApp()
{
	loadServer();
}


configApp::~configApp()
{
	unLoadServer();
}

void configApp::loadServer()
{
	m_buff = GetFileContext(m_path.c_str());
}

void configApp::unLoadServer()
{
	setFileContext(m_path.c_str(), m_buff.c_str(), m_buff.size());
}
bool configApp::getServer(int index, serverInfo& rstInfo)
{
	std::string tempSplit = getIndexStr(index, m_buff, '|');
	rstInfo.serverName = getIndexStr(1, tempSplit, ',').c_str();
	rstInfo.serverPath = getIndexStr(2, tempSplit, ',').c_str();
	return !tempSplit.empty();
}

bool configApp::addServer(serverInfo info)
{
	std::string serverString = info.serverName + ",";
	auto pos = m_buff.find(serverString);
	if (pos != std::string::npos)
	{
		return false;
	}
	serverString  += info.serverPath + "|";
	if (serverString.size() < 5)
	{
		return false;
	}
	m_buff += serverString;
	return true;
}

bool configApp::delServer(serverInfo info)
{
	std::string serverString = info.serverName + "," + info.serverPath + "|";
	auto pos = m_buff.find(serverString);
	if (pos == std::string::npos)
	{
		return false; 
	} 
	m_buff.replace(pos,serverString.size(), "");
	return true;
}

