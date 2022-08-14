#include <windows.h>
#include <string>
#include <assert.h>
#include <process.h>
#include <filesystem>
#include <fstream>
using std::filesystem::exists;
char* Path_folder()
{
	char szPath[MAX_PATH] = {};
	GetModuleFileNameA(NULL, szPath, MAX_PATH);
	char* lstChr = strrchr(szPath, '\\');
	*lstChr = '\0';
	return szPath;
}

const char* fullPath()
{
	char path[500];
	sprintf_s(path, "%s\\wallhack.ini", Path_folder());
	return path;
}


float ReadFloat(std::string _Section, std::string _Key)
{
	char str[256];
	GetPrivateProfileStringA(_Section.c_str(), _Key.c_str(), NULL, str, sizeof(str), fullPath());
	return std::stof(str);
}

int ReadInt(std::string _Section, std::string _Key)
{
	char str[256];
	GetPrivateProfileStringA(_Section.c_str(), _Key.c_str(), NULL, str, sizeof(str), fullPath());
	return std::stoi(str);
}

void checkConfig()
{
	if (!exists("wallhack.ini"))
	{
		std::ofstream config("wallhack.ini");
		config << "[settings]\nisenable=1\ndist=1000\nwalls=0" << std::endl;
	}
}