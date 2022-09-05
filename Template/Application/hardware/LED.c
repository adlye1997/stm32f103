#include "LED.h"

/*
 * 通过配置LED.config.mode使其工作在不同模式
 * LED_mode = 1  双灯同步闪烁
 * LED_mode = 2  双灯异步闪烁
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
