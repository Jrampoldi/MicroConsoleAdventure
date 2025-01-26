#include "screen.h"

int TITLE_AREA[2][2] = {{0, 0}, {SCREEN_SIZE - 1, (SCREEN_SIZE / 8) - 1}};
char* TITLE = "Adventure Unlimited";

void showStart(int cursorPos){
	SSD1327_Clear(BLACK);
	char* startMenuStrings[] = {"New Game", "Load Game", "Show Summary", "Settings"};
	int yPos = TITLE_AREA[1][1] + 16;
	int xPos = 0;
	GFX_DrawString(60 - ((strlen(TITLE) * 5) / 2), 6, TITLE, WHITE, BLACK);
	GFX_DrawLine(TITLE_AREA[0][0], TITLE_AREA[1][1], TITLE_AREA[1][0], TITLE_AREA[1][1],WHITE / 2);
	for (int word = 0; word < 4; word++){
		xPos = (64 - (strlen(startMenuStrings[word]) * 5) / 2);
		
		if (cursorPos == word){
			GFX_DrawFillRectangle(xPos - 5, yPos, (strlen(startMenuStrings[word]) + 3) * 5, 8, WHITE);
			GFX_DrawString(xPos, yPos, startMenuStrings[word], BLACK, WHITE);
		} else {
			GFX_DrawString(xPos, yPos, startMenuStrings[word], WHITE, BLACK);
		}

		yPos += (((SCREEN_SIZE - 1) - TITLE_AREA[1][1]) / 4) - 8;
	}
	SSD1327_Display();
}

char* typeNameMenu(int cursorPos){
	//display letters while letting player cycle through
}
