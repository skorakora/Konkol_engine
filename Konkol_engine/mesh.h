#pragma once
#include "stdafx.h"
#include <glm/glm.hpp>
#include <GL/glew.h>


class Vertex
{
public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}

private:
	glm::uvec3 pos;

};


class Mesh
{
public:
	void Draw();

	Mesh(Vertex* vertices, unsigned int numVertices);
	~Mesh();

private:

	enum 
	{
		POSITION_VB,
		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_VertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;

};





