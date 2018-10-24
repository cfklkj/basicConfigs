#pragma once
#include <string>

class configs
{
public:
	configs();
	~configs();
	void openConfig(CString path);
	void closeConfig();

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
private:
	void setValue(std::string section, std::string value, bool isStr);
	void setValue(std::string section, int value);
	int getValueInt(std::string section);
	std::string getValueString(std::string section);
private:
	CString m_path; 
	std::string m_buff;
};

