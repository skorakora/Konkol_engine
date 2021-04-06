#pragma once
//Copyright Danzo Systems. Created by Daniel Skorski
#include "stdafx.h"

//This is simple log system used by engine
void InitLog();
void ErrorLog(const std::string str);
void WriteLog(const std::string str);
void CloseLog();

void RedirectIOToConsole();//create debug console