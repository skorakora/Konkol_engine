//Copyright Danzo Systems. Created by Daniel Skorski


#include "Logs.h"

#include "stdafx.h"
#include "Globals.h"


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
	if (Global.debugMode)
	{
		RedirectIOToConsole();//initialization of cmd window
	}
}

void ErrorLog(const std::string str)
{
	if (str.empty()) { return; }
	output << "ERROR:" << str << '\n';
	if (Global.debugMode)//write log to console
	{
		_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE); //some weird stuff neded to display command on cmd window.
		_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
		_RPT0(_CRT_WARN, "ERROR:"); //Win32 version of "cout"
		_RPT0(_CRT_WARN, str.c_str());
		_RPT0(_CRT_WARN, "\n");
	}
	errlog << str << '\n';
}

void WriteLog(const std::string str)
{
	if (str.empty()) { return; }
	output << str << '\n';
	if (Global.debugMode)//write log to console
	{
		_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);//some weird stuff neded to display command on cmd window.
		_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
		_RPT0(_CRT_WARN, str.c_str());//Win32 version of "cout"
		_RPT0(_CRT_WARN, "\n");
	}
}

void CloseLog()
{
	output.flush();
	errlog.flush();
	output.close();
	errlog.close();
}

void RedirectIOToConsole()
{
	static const WORD MAX_CONSOLE_LINES = 500;
	int hConHandle;
	long lStdHandle;
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	FILE* fp;

	// allocate a console for this app
	AllocConsole();

	// set the screen buffer to be big enough to let us scroll text
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	coninfo.dwSize.Y = MAX_CONSOLE_LINES;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coninfo.dwSize);

	// redirect unbuffered STDOUT to the console
	lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
	fp = _fdopen(hConHandle, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);

	// redirect unbuffered STDIN to the console
	lStdHandle = (long)GetStdHandle(STD_INPUT_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
	fp = _fdopen(hConHandle, "r");
	*stdin = *fp;
	setvbuf(stdin, NULL, _IONBF, 0);

	// redirect unbuffered STDERR to the console
	lStdHandle = (long)GetStdHandle(STD_ERROR_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
	fp = _fdopen(hConHandle, "w");
	*stderr = *fp;
	setvbuf(stderr, NULL, _IONBF, 0);

	// make cout, wcout, cin, wcin, wcerr, cerr, wclog and clog
	// point to console as well
	std::ios::sync_with_stdio();
}

//TODO:
//-OpenGL log system