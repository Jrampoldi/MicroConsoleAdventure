#ifndef GAME_HANDLER_H_
#define GAME_HANDLER_H_

#include "stm32f4xx_hal.h"
#include "assets.h"
#include "OLED_SSD1327.h"
#include "GFX_SSD1327.h"
#include "fonts.h"
#include "screen.h"

extern volatile char playerStartGame;
extern volatile char playerSwitchMode;
extern volatile char playerSelectOption;

void gameInit(SPI_HandleTypeDef* hi2c,TIM_HandleTypeDef* htim, Player* plr);
void gameUpdate(Player* plr);
void clearPlayerSelect();
void updateCursorPos(TIM_HandleTypeDef* htim);

#endif
