#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <GLFW\glfw3.h>
#include <list>
#include <string>
#include <Windows.h>

#include "linmath.h"
#include "file.h"

#include "entity.h"
#include "Component.h"

#define ENTITY_CONFIG_FILE_PATH "/entities/gdsentities.config" ;
#define ENTITY_FILE_PATH "/entities/" ;



typedef struct {
	double r;
	double g;
	double b;
	double a;
}GDCOLOR;
typedef struct {
	double x;
	double y;
	double z;
	GDCOLOR c;
}GDVERTEX;
typedef struct {
	double x;
	double y;
	double z;
}GDSIZE;
typedef struct {
	double x;
	double y;
	double z;
}GDPOSITION;
typedef struct {
	GDVERTEX m;
	GDVERTEX n;
	GDVERTEX o;
}GDTRIANGLE;
typedef struct {
	int id;
	std::string fileName;
	GDPOSITION* position;
	Entity* entity;
}GDENTITYRES;
typedef struct {
	int id;
	GDPOSITION* position;
	Component* entity;
}GDCOMPONENTRES;

//Entity* loadEntities(int entityId, std::string filename, std::list<GDENTITYRES*>* ENTITY_LIST);
std::list<GDENTITYRES*> fetchEntities(FILE* file, unsigned long* position);
GDCOMPONENTRES fetchComponent(FILE* fileName);
void FetchEntityList(std::list<GDENTITYRES*>* entit_list);