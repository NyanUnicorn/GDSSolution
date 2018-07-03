#include "gd.h"





void GD::init() {
	
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	gdwindow = glfwCreateWindow(500, 500, "Opengl example", NULL, NULL);
	if (!gdwindow) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(gdwindow);
	glfwSwapInterval(1);

	
	
	
}

void GD::run() {
	
	while (!glfwWindowShouldClose(gdwindow)) {
		//setup view
		float ratio;
		int height, width;
		glfwGetFramebufferSize(gdwindow, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		//drawing
		drawTriangle();
		//verify items
		//update camera position
		//update item position relative to camera
		//render the environement
		render3D();
		
		
		//swap buffer & event check
		glfwSwapBuffers(gdwindow);
		glfwPollEvents();
	}
	glfwDestroyWindow(gdwindow);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void GD::drawTriangle() {
	glBegin(GL_TRIANGLES);
	glColor3f(0, 1, 0);
	glVertex3f(.4, 0, .9);
	glVertex3f(.4, .4, 0);
	glVertex3f(0, .4, 2);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 1);
	glVertex3f(0, .4, 1);
	glVertex3f(.4, .4, 1);
	glEnd();
}

void GD::render3D() {

}

void GD::load() {
	Entity world;
	world = *loadEntities(NULL, NULL, &ENTITY_LIST);
}

void GD::declarations() {
}



GD::GD() {
	init();
	run();
}

GD::~GD()
{
}
