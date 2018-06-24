#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GLFW\glfw3.h>

#include "linmath.h"


class GD {
	GLFWwindow* window;
	void init();
	void run();
public:
	GD();

	~GD();
};

