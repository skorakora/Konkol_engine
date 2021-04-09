#pragma once
//Copyright Danzo Systems. Created by Daniel Skorski


#include "stdafx.h"

#include <GL/glew.h>


class Shader           //shader class
{
public:
	

	void Bind(); 
	Shader(const std::string& fileName);
	~Shader();
private:
	static const unsigned int NUM_SHADERS = 2; //todo change here to "3" for geometry shader support
	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS]; 

};