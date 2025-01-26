#include "game_handler.h"

volatile char playerStartGame = 0x00;
volatile char playerSwitchMode = 0x00;
volatile char playerSelectOption = 0x00;

int playerCursorPos = 0;
int rawEncoderRead = 0;
int lastRawRead = 0;
int direction = 0;

void gameInit(SPI_HandleTypeDef* hspi,TIM_HandleTypeDef* htim, Player* plr){
	SSD1327_SpiInit(hspi);
	GFX_SetFont(font_8x5);
	updateCursorPos(htim);
	while (!playerStartGame){
		int temp_c_pos = -1; // start not matching
		while(!playerSelectOption){
			if (temp_c_pos != playerCursorPos){
				showStart(playerCursorPos);
				temp_c_pos = playerCursorPos;
			}
			updateCursorPos(htim);
		}
		switch(playerCursorPos){
			case 0: 
				/* New Game */
				
				break;
			case 1:
				/* Load Game */
				break;
			case 2:
				/* Show Summary */
				break;
			case 3:
				/* Settings */
				break;
		}
		clearPlayerSelect();
		
	}
}
void gameUpdate(Player* plr){
	
}

void updateCursorPos(TIM_HandleTypeDef* htim){
	rawEncoderRead = __HAL_TIM_GET_COUNTER(htim);
	if (rawEncoderRead % 8 == 0){
		if (rawEncoderRead > lastRawRead){
			direction = 1;
		} else if (rawEncoderRead < lastRawRead){
			direction = -1;
		}

		//Catch wrap around values
		if(rawEncoderRead == 0 && lastRawRead == 65532){
			direction = 1;
		} else if(rawEncoderRead == 65532 && lastRawRead == 0){
			direction = -1;
		}

		if (direction == 1){
			if (playerCursorPos < 3) {playerCursorPos++;}
		} else if (direction == -1){
			if (playerCursorPos > 0){playerCursorPos--;}
		}

		direction = 0;
	}
	lastRawRead = rawEncoderRead;
}

void clearPlayerSelect(){
	__disable_irq();
	playerSelectOption = 0x00;
	__enable_irq();
}
