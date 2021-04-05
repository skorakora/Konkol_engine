#pragma once
//Copyright Danzo Systems. Created by Daniel Skorski
#include <iostream>

//This is simple log system used by engine
void InitLog();
void Error(const std::string str);
void WriteLog(const std::string str);
void CloseLog();