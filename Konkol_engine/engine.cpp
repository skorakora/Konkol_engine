//Copyright Danzo Systems. Created by Daniel Skorski


#include "engine.h"



#include "stdafx.h"
#include "Globals.h"
#include "mesh.h"
#include "display.h"
#include "Shader_compiler.h"

#include <SDL2/SDL.h>



int Konkol_Engine::init()
{
	int result = 0;
	InitLog();
	WriteLog("Starting Konkol Engine - Please Wait...");
	WriteLog("Copyright Danzo Systems Software, created by Daniel Skorski");


	return 0;
}

int Konkol_Engine::run()
{
	int result = 0;
	Display display(800, 600, "Konkol Engine");

	
	
	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0.0)), 
						  Vertex(glm::vec3(0.0, 0.5, 0.0)), 
						  Vertex(glm::vec3(0.5, -0.5, 0.0)) };


	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

	Shader shader("./shaders/basicShader");

	while(!display.IsClosed())
	{

		shader.Bind();
		display.Update();
	}
	
	return 0;
}

void Konkol_Engine::exit()
{
	//TODO:
	//-destructors
	//-exit
}

//TODO
//-Result debug system in initialization

