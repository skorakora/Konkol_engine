//Copyright Danzo Systems. Created by Daniel Skorski


#include "Logs.h"

#include "stdafx.h"
#include "Globals.h"
#include "Console.h"

bool debugMode = true;//fix globals - test for console.

std::fstream output;
std::fstream errlog;

void InitLog()
{
	if (!std::filesystem::exists("log"))
	{
		std::filesystem::create_directory("log");
	}
	output.open("log\\log.txt", std::fstream::out);
	errlog.open("log\\errors.txt", std::fstream::out);
	if (debugMode)
	{
		RedirectIOToConsole();
	}
}

void ErrorLog(const std::string str)
{
	if (str.empty()) { return; }
	output << "ERROR:" << str << '\n';
	if (debugMode)
	{
		_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
		_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
		_RPT0(_CRT_WARN, "ERROR:");
		_RPT0(_CRT_WARN, str.c_str());
		_RPT0(_CRT_WARN, "\n");
		//TODO optimalisation
	}
	errlog << str << '\n';
}

void WriteLog(const std::string str)
{
	if (str.empty()) { return; }
	output << str << '\n';
	if (debugMode)
	{
		_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
		_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
		_RPT0(_CRT_WARN, str.c_str());
		_RPT0(_CRT_WARN, "\n");
		//TODO optimalisation
	}
}

void CloseLog()
{
	output.flush();
	errlog.flush();
	output.close();
	errlog.close();
}

//TODO:
//-Console log, that is active only in debug mode
//-read settings from global variable
//-OpenGL log system