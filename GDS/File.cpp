#include "file.h"

namespace file {
	int getEnd(FILE* _file) {
		int position = 0;
		fseek(_file, position, SEEK_END);
		fflush(_file);
		position = ftell(_file);
		return position;
	}
}