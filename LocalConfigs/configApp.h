#pragma once
#include "serverMgr.h"
#include <string>
#include <vector>
class configApp
{
public:
	configApp();
	~configApp();

	void loadServer();
	void unLoadServer(); 
	//index start from  1
	bool getServer(int index, serverInfo& rstInfo);
	bool addServer(serverInfo info);
	bool delServer(serverInfo info);
private:
	std::string m_path=".\\mgrConfigs.config";
	std::string m_buff = "";
};

