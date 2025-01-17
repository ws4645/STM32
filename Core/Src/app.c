/*
 * app.c
 *
 *  Created on: Jan 16, 2025
 *      Author: ws464
 */

#include "app.h"
#include "math.h"

// 장치 선언
extern TIM_HandleTypeDef htim1;

// time1의 duty 변경
void setDuty(uint8_t duty_r, uint8_t duty_g, uint8_t duty_b){
	htim1.Instance->CCR1 = (duty_r) * 10;
	htim1.Instance->CCR2 = (duty_g) * 10;
	htim1.Instance->CCR3 = (duty_b) * 10;
}

void app(){
	// 타이머 장치 시작
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);

	while(1){
		static int angleR = 0;
		static int angleG = 120;
		static int angleB = 240;
		angleR++;
		angleG++;
		angleB++;
		angleR %= 360;
		angleG %= 360;
		angleB %= 360;
		uint8_t valueR = sin(angleR * M_PI / 180) * 50 + 49;
		uint8_t valueG = sin(angleG * M_PI / 180) * 50 + 49;
		uint8_t valueB = sin(angleB * M_PI / 180) * 50 + 49;
		setDuty(valueR, valueG, valueB);
		HAL_Delay(10);
	}
}
