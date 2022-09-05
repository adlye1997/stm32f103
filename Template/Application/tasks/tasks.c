#include "tasks.h"
#include "LED.h"
#include "math.h"

void StartDefaultTask(void const * argument)
{
	LED_init();
  for(;;)
  {
		LED.task();
		osDelay(LED.config.dt);
  }
}
