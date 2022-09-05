#include "LED.h"

/*
 * ͨ������LED.config.modeʹ�乤���ڲ�ͬģʽ
 * LED_mode = 1  ˫��ͬ����˸
 * LED_mode = 2  ˫���첽��˸
*/

LED_t LED = 
{
	.config = 
	{
		.mode = 2,
	},
	.init = LED_init,
	.task = LED_task,
};

void LED_init(void)
{
	LED_RED_ON
	LED_GREEN_ON
	switch(LED.config.mode)
	{
		case 1:
		case 2:
			LED.config.dt = 500;
			break;
		default:
			LED.config.dt = 1;
			break;
	}
}

void LED_task(void)
{
	switch(LED.config.mode)
	{
		case 1:
			if(LED.state.light_state == 0)
			{
				LED_RED_ON
				LED_GREEN_ON
				LED.state.light_state = 1;
			}
			else 
			{
				LED_RED_OFF
				LED_GREEN_OFF
				LED.state.light_state = 0;
			}
			break;
		case 2:
			if(LED.state.light_state == 0)
			{
				LED_RED_ON
				LED_GREEN_OFF
				LED.state.light_state = 1;
			}
			else 
			{
				LED_RED_OFF
				LED_GREEN_ON
				LED.state.light_state = 0;
			}
			break;
		default:
			break;
	}
}
