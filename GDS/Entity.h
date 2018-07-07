#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GLFW\glfw3.h>
#include <list>
#include <string>

#include "linmath.h"
#include "gdtools.h"

#include "entity.h"
#include "Component.h"



class Entity {
public:
	int id;
	std::string name;
	GDSIZE size;
	GDPOSITION position;

	bool mobile;
	bool rotates;

	GDCOLOR domColor;

	//render entity
	void render3D();


	Entity();
	Entity(GDPOSITION);
	~Entity();

private:
	std::list<GDENTITYRES*> Entities;
	std::list<Component*> Components;
	std::list<GDVERTEX*> vertexList;


};

