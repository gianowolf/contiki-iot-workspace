#include "contiki.h"

/* Drivers */
#include "dev/leds.h"
#include "dev/button-sensor.h"

/* Utils */
#include <stdio.h>

/* Constants */
#define N_LEDS  3

#define S_DISABLED 0
#define S_ENABLED  1

#define T_BLUE  3
#define T_RED   5
#define T_GREEN 7

#define L_BLUE  0
#define L_RED   1
#define L_GREEN 2

/* Types */
typedef unsigned char uint8_t;

/* Functions */
uint8_t toggling(uint8_t led, uint8_t led_counter, uint8_t led_reset_time);

/********************* Processes *********************/
PROCESS(timer_process, "Timer Process");
PROCESS(button_process, "Button Process");

//AUTOSTART_PROCESSES(&timer_process, &button_process);
AUTOSTART_PROCESS(&timer_process);
/*****************************************************/

/* Globals */
uint8_t counters[N_LEDS] = {T_BLUE, T_RED, T_GREEN};
uint8_t leds_enabled = S_DISABLED; 

/* Threads */
PROCESS_THREAD(timer_process, ev, data)
{
	
	static struct etimer et;
	printf("holamundo");
	
	PROCESS_BEGIN();
	printf("PROCESS_THREAD 'Process Timer' Started succesfully");

		while(1)
		{
			etimer_set(&et, CLOCK_SECOND);
			
			PROCESS_WAIT_EVENT();

			if(etimer_expired(&et))
			{
				if(leds_enabled)
				{
					if(--counters[L_BLUE] == 0)
					{
						leds_toggle(LEDS_BLUE);
						counters[L_BLUE] = T_BLUE;
					}
				
					if(--counters[L_RED] == 0)
					{
						leds_toggle(LEDS_RED);
						counters[L_RED] = T_BLUE;
					}

					if(--counters[L_GREEN] == 0)
					{
						leds_toggle(LEDS_GREEN);
						counters[L_GREEN] = T_GREEN;
					}
				}
				etimer_reset(&et);
			}

		}
	PROCESS_END();	
}

PROCESS_THREAD(button_process, ev, data)
{
	PROCESS_BEGIN();
		SENSORS_ACTIVATE(button_sensor);
		
		printf("comenzando thread button");
		
		while(1)
		{
			PROCESS_WAIT_EVENT_UNTIL(
				(ev == sensors_event)
				&&
				(data == &button_sensor));

			leds_enabled = !leds_enabled;
		}
	PROCESS_END();
}

/* Toggles a target led and reset the led counter */
uint8_t toggling(uint8_t led, uint8_t led_counter, uint8_t led_reset_time)
{
	leds_toggle(led);
	led_counter = led_reset_time;
	return 0;
}
