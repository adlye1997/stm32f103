#ifndef __LED_H
#define __LED_H

#include "stm32f1xx_hal.h"
#include "main.h"

#define LED_RED_ON HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
#define LED_RED_OFF HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
#define LED_GREEN_ON HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
#define LED_GREEN_OFF HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

typedef struct
{
	uint8_t mode;
	uint16_t dt;
}LED_config_t;

typedef struct
{
	uint8_t light_state;
}LED_state_t;

typedef struct
{
	LED_config_t config;
	LED_state_t state;
	void (*init)(void);
	void (*task)(void);
}LED_t;

extern LED_t LED;

void LED_init(void);
void LED_task(void);

#endif
