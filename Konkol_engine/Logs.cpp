//Copyright Danzo Systems. Created by Daniel Skorski
#include "Logs.h"

#include <iostream>
#include <fstream>
#include <filesystem>

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
}

void Error(const std::string str)
{
	if (str.empty()) { return; }
	output << "ERROR:" << str << '\n';
	errlog << str << '\n';
}

void WriteLog(const std::string str)
{
	if (str.empty()) { return; }
	output << str << '\n';
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