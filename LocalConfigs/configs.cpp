#include "stdafx.h"
#include "configs.h"
#include <fileapi.h>
#include <algorithm>
#include <iostream>
#include "Util.h"
#pragma warning(disable:4996)

configs::configs()
{
}


configs::~configs()
{
}


void configs::setValue(std::string section, int value)
{ 
	std::string buff;
	buff = format("%d", value); 
	setValue(section, buff, false);
}

void configs::setValue(std::string section, std::string value, bool isStr)
{
	size_t index = m_buff.find(section);
	if (index != std::string::npos)
	{
		std::string buff;
		int first = index;
		int i = 0;
		int last = 0;
		for (;m_buff.at(first) != ':';first++);  //find start

		for (i = ++first;m_buff.at(i) != ',' && m_buff.at(i) != '\r' && m_buff.at(i) != '\n'; i++) //find end
		{
			last = i;
			if (m_buff.at(i) == ' ')
				continue;
		} 
		if (isStr)
		{
			buff = format("\"%s\"", value.c_str()); 
		}
		else
		{
			buff = value;
		}
		for (int i = last + 1; i < m_buff.size(); i++)
		{
			buff.push_back(m_buff.at(i));
		}
		m_buff.erase(first, m_buff.size());
		m_buff += buff;
	}
	return;
}

std::string configs::getValueString(std::string section)
{
	size_t index = m_buff.find(section);
	if (index != std::string::npos)
	{
		int first = index;
		int i = 0;
		for (;m_buff.at(first) != ':';first++);  //find start

		for (i = ++first;i < m_buff.size() && (m_buff.at(i) == ':' || m_buff.at(i) == ' '); first = i++);  

		if (m_buff.at(i) == ',' && m_buff.at(i) != '\r' && m_buff.at(i) != '\n') 
		{
			return "";
		}
		std::string buff;
		for (int i = first;i < m_buff.size()  && m_buff.at(i) != ',' && m_buff.at(i) != '\r' && m_buff.at(i) != '\n'; i++)  //check end
		{
			if (m_buff.at(i) == ' ')
				continue;
			buff.push_back(m_buff.at(i));
		}
		return buff.c_str();
	}
	return "";
}

int configs::getValueInt(std::string section)
{ 
	std::string value = getValueString(section);
	std::transform(value.begin(), value.end(), value.begin(), ::tolower);
	if (value.find("true") != std::string::npos)
	{
		return 1;
	}
	return atoi(value.c_str());;
}

void configs::openConfig(CString path)
{ 
	m_buff = GetFileContext(W2C(path));
	if (m_buff.size() > 1) {
		m_path = path; 
	}
	else {
		m_path = "";
	}	 
}
void configs::closeConfig()
{
	if (m_path != "")
	{ 
		setFileContext(W2C(m_path), m_buff.c_str(), m_buff.size());
	}
}
//-------------------------------------------------------------

void configs::setRoomType(int type)
{ 
	setValue("roomType", type);
}
int configs::getRoomType()
{ 
	return getValueInt("roomType");
}


void configs::setDayUp(bool isTrue)
{
	setValue("isMainCommonServer", isTrue);
}
bool configs::getDayUp()
{
	return getValueInt("isMainCommonServer");
}

void configs::setRouter(CString strIpPort)
{
	std::string str = W2C(strIpPort);
	setValue("routerServerAddr", str, true);
}
CString configs::getRouter()
{
	CString rst = L"";
	rst += getValueString("routerServerAddr").c_str();
	return rst;
}


void configs::setDBsubscrib(CString strIpPort)
{
	std::string str = W2C(strIpPort);
	setValue("dbService", str, true);
}
CString configs::getDBsubscrib()
{
	CString rst = L"";
	rst += getValueString("dbService").c_str();
	return rst;
}


void configs::setLogSubscrib(CString strIpPort)
{
	std::string str = W2C(strIpPort);
	setValue("dbLogTopic", str, true);
}
CString configs::getLogSubscrib()
{
	CString rst = L"";
	rst += getValueString("dbLogTopic").c_str();
	return rst;
}


void configs::setChargeServer(CString strIpPort)
{
	std::string str = W2C(strIpPort);
	setValue("countTopic", str, true);
}
CString configs::getChargeServer()
{
	CString rst = L"";
	rst += getValueString("countTopic").c_str();
	return rst;
}


void configs::setChargeSubscrib(CString strIpPort)
{
	std::string str = W2C(strIpPort);
	setValue("chargeTopic", str, true);
}
CString configs::getChargeSubscrib()
{
	CString rst = L"";
	rst += getValueString("chargeTopic").c_str();
	return rst;
}


void configs::setPlayerLogSubscrib(CString strIpPort)
{
	std::string str = W2C(strIpPort);
	setValue("playerLogTopic", str, true);
}
CString configs::getPlayerLogSubscrib()
{
	CString rst = L"";
	rst += getValueString("playerLogTopic").c_str();
	return rst;
}


void configs::setBrodcastSubscrib(CString strIpPort)
{
	std::string str = W2C(strIpPort);
	setValue("brocastTopic", str, true);
}
CString configs::getBrodcastSubscrib()
{
	CString rst = L"";
	rst += getValueString("brocastTopic").c_str();
	return rst;
}