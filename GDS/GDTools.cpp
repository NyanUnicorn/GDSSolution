#include "gdtools.h"

Entity* loadEntities(int _entityId, std::string _filename, std::list<GDENTITYRES*>* _ENTITY_LIST) {
	Entity* entityAdr;
	//check for entity id if exist, if 0 get root entity
	if (!_entityId == 0) {
		//access file -- extract entity info
		std::string entityFilePath = ENTITY_FILE_PATH;
		std::string entityFileName = entityFilePath + _filename;
		FILE* entityFile = fopen(entityFileName.c_str(), "r" );
		if (entityFile != NULL) {
			//extract child entity and add to current entity address list
			unsigned long cursorPos;
			int id;
			std::string name;
			GDSIZE* size;
			bool mobile;
			std::string mobileTxt;
			bool rotates;
			std::string rotatesTxt;
			GDCOLOR* dominantColor;
			std::list<GDENTITYRES*> entities;
			std::list<GDCOMPONENTRES> components;
			std::list<GDVERTEX> vertexes;

			fscanf(entityFile, "id:%d;name: %[^;] ; \n size:(< %lf , %lf , %lf >); \n mobile: %[^;] ;rotates: %[^;] ; \n dominant-color:( %lf , %lf , %lf , %lf ); \n "/* entities: %[^;] ; \n components: %[^;] ; \n vertexes: %[^;]; \n "*/, 
				&id, &name, size->x, size->y, size->z, mobileTxt, rotatesTxt, dominantColor->r, dominantColor->g, dominantColor->b, dominantColor->a/*, &entitiesTxt, &componentTxt, &vertexesTxt */);
			fflush(entityFile);
			cursorPos = ftell(entityFile);
			if (mobileTxt == "true") {
				mobile = true;
			}
			else {
				mobile = false;
			}
			if (rotatesTxt == "true") {
				rotates = true;
			}
			else {
				rotates = false;
			}
			entities = fetchEntities(entityFile, &cursorPos);
			for (GDENTITYRES* ent : entities) {
				bool defined = false;
				for (GDENTITYRES* entl : *_ENTITY_LIST) {
					if (ent->id == entl->id) {
						if (entl->entity) {
							defined = true;
							ent->entity = entl->entity;
						}
						else {
							Entity entityToAdd;
							entityToAdd = *loadEntities(entl->id, entl->fileName, _ENTITY_LIST);
							ent->entity = &entityToAdd;
							entl->entity = &entityToAdd;
						}
					}
				}
			}

			//create entity and save address
			fclose(entityFile);
		}
	}
	else {
		//fetch all entities
		FetchEntityList(_ENTITY_LIST);
		//fetch filename for world creation begin
		entityAdr = loadEntities(5, "hhhh", _ENTITY_LIST);
	}
	return entityAdr;
}

void FetchEntityList(std::list<GDENTITYRES*>* _entit_list) {
	FILE* file = fopen("gdsentities.conf", "r");
	int position;
	//position = entityConf::findInConf("Entities", file);
	//fscanf(file, "%s entities:");
}

std::list<GDENTITYRES*> fetchEntities(FILE* _file, unsigned long* _position) {
	std::list<GDENTITYRES*> entityResList;
	char seperator;
	fseek(_file, *_position, SEEK_SET);
	fflush(_file);
	*_position = ftell(_file);
	fscanf(_file, "entities:");
	fscanf(_file, "%c", &seperator);
	while (seperator != ';') {
		if (seperator == '(') {
			GDENTITYRES* entityRes;
			fscanf(_file, "%d ,", entityRes->id);
			fscanf(_file, "%lf ,", entityRes->position->x);
			fscanf(_file, "%lf ,", entityRes->position->y);
			fscanf(_file, "%lf", entityRes->position->z);
			entityResList.push_back(entityRes);
		}
		fscanf(_file, "%c", &seperator);
	}
	return entityResList;
}

namespace entityConf {
	int findInConf(std::string option, FILE* _file) {
		int end;
		end = file::getEnd(_file);
		fseek(_file, 0, SEEK_SET);
		char search[] = "";
		while (option.c_str() == search) {

		}
	}
}