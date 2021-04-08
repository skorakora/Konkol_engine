#pragma once
#include "stdafx.h"

#include <SDL2/SDL.h>


class Display
{
public:
	void Update();
	bool IsClosed();

	Display(int widith, int height, const std::string & title);
	~Display();

private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;

};

