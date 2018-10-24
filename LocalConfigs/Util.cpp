#include "stdafx.h"
#include "Util.h"
#include <string>
 



#define RECIEVE_FORMAT_DATA(format, retString) \
{ \
char* va_dataResult = NULL; \
int va_bufferLen = 4096; \
int va_actualLen = 0; \
va_list list; \
va_start(list, format); \
do {\
	if(va_dataResult) {\
		free(va_dataResult);	\
	}\
	va_bufferLen *= 2;\
	va_dataResult = (char*)calloc(1, va_bufferLen);\
	va_actualLen = vsnprintf(va_dataResult, va_bufferLen, format, list);\
} while(va_actualLen == va_bufferLen);	\
va_end(list); \
retString = va_dataResult; \
free(va_dataResult); \
}

//¸ñÊ½»¯×Ö·û´®
std::string format(const char *formatStr, ...)
{
	std::string retStr = "";
	RECIEVE_FORMAT_DATA(formatStr, retStr);
	return retStr;
}

CStringA W2C(CString &wcharBuff)
{
	int nL = WideCharToMultiByte(0, 0, wcharBuff, (int)wcharBuff.GetLength(), NULL, 0, NULL, NULL);
	if (nL < 1)
		return NULL;
	char* str = new char[nL + 1];
	if (!str)
		return NULL;
	WideCharToMultiByte(0, 0, wcharBuff, (int)wcharBuff.GetLength(), str, nL, NULL, NULL);
	str[nL] = 0;
	CStringA strOut = str;
	delete[]str;
	str = NULL;
	return strOut;
}

std::string GetFileContext(const char* fileName)
{
	FILE* file = NULL;
	fopen_s(&file, fileName, "rb");
	if (!file) {
		return "";
	}
	char readBuffer[4096] = {};
	std::string outData;
	while (!feof(file)) {
		size_t len = fread(readBuffer, 1, sizeof(readBuffer), file);
		outData.append(readBuffer, len);
	}
	fclose(file);
	return outData;
}

void setFileContext(const char* fileName, const char* txt, int size)
{
	FILE* file = NULL;
	fopen_s(&file, fileName, "w");
	if (!file) {
		return;
	}
	fwrite(txt, 1, size, file);
	fclose(file);
}
std::string getIndexStr(int index, std::string buff, char split)
{
	if (buff.size() < 1)
		return "";
	int findDex = 0;
	int start = -1;
	for (int i = 0; i < buff.size(); i++)
	{
		if (buff.at(i) == split)
		{
			findDex++;
			i++;
		}
		if (findDex + 1 == index)
		{
			start = i;
			break;
		}
	}
	if (start == -1)
		return "";
	std::string temp = "";
	for (int j = start; j < buff.size(); j++)
	{
		if (buff.at(j) == split)
		{
			break;
		}
		temp.push_back(buff.at(j));
	}
	return temp;
}