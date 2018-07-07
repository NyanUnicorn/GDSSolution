#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GLFW\glfw3.h>
#include <list>

#include "linmath.h"
#include "gdtools.h"

#include "entity.h"


class GD {
	GLFWwindow* gdwindow;
	std::list<GDENTITYRES*> Entities;
	void init();
	void run();
	void drawTriangle();
	void render3D();
public:
	void load();
	void declarations();
	std::list<GDENTITYRES*> ENTITY_LIST;


	GD();

	~GD();
};

