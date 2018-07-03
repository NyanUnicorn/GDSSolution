#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GLFW\glfw3.h>
#include <list>
#include <string>

#include "linmath.h"
#include "gdtools.h"

class Component {
public:
	int id;
	std::string name;
	float xMax;
	float yMax;
	float zMax;

	GDPOSITION position;

	bool mobile;
	bool rotates;

	GDCOLOR domColor;

	//render entity
	void render3D();

	Component();
	~Component();

private:
	//vertexList
	std::list<GDVERTEX> vertexList;
};

