#include "gd.h"




GD::GD() {
	init();
	run();

	
}

void GD::init() {
	
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	window = glfwCreateWindow(500, 500, "Opengl example", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	
	
	
}

void GD::run() {
	
	while (!glfwWindowShouldClose(window)) {
		//setup view
		float ratio;
		int height, width;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		//drawing
		glBegin(GL_TRIANGLES);
		glVertex3f(0,0,0);
		glVertex3f(0,.124,0);
		glVertex3f(1,0,0);
		glEnd();
		//swap buffer & event check
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}





GD::~GD()
{
}
