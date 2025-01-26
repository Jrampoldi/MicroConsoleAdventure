#ifndef SCREEN_H_
#define SCREEN_H_

#include <string.h>
#include "OLED_SSD1327.h"
#include "GFX_SSD1327.h"
#include "fonts.h"

#define SCREEN_SIZE 128


void showStart(int cursorPos);
char* typeNameMenu(int cursorPos);
#endif
