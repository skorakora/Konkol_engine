//Copyright Danzo Systems. Created by Daniel Skorski


#include "stdafx.h"
#include "engine.h"
#include "Globals.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int result = 0;

	Konkol_Engine engine;

	try
	{
		InitLog();
		result = engine.init();
			if (result == 0)
			{
				result = engine.run();
				engine.exit();
			}
	}
	catch (std::bad_alloc const& Error)
	{
		ErrorLog("Critical error, memory allocation failure: " + std::string(Error.what()));
	}
	ErrorLog("engine exception code =" + result);
	CloseLog();
	return result;
}
