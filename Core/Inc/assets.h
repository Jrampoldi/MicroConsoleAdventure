#ifndef ASSETS_H_
#define ASSETS_H_

#include "fatfs.h"


typedef struct {
	char* filePath;
	char* pageDescription;
	char* playerOptions[];
}Path;

typedef struct {
	char* username;
	char* currentPath;
	char* displayToPlayer;
}Player;



#endif
