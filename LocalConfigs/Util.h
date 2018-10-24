#pragma once
#include <string>

std::string format(const char *formatStr, ...);
CStringA W2C(CString &wcharBuff);
std::string GetFileContext(const char* fileName);
void setFileContext(const char* fileName, const char* txt, int size);
std::string getIndexStr(int index, std::string buff, char split);