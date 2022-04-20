/**
 * \file
 *         A very simple Contiki application showing how Contiki programs look
 * \author
 *        Gian Franco Lasala 
 */

/* Drivers */
#include "contiki.h"
#include "dev/leds.h"
#include "dev/button-sensor.h"

/* Utils */
#include <stdio.h> /* For printf() */

/* Types */
typedef unsigned char uint8;

/*---------------------------------------------------------------------------*/

PROCESS(process_leds, "LEDs Process");
PROCESS(process_timer, "Timer Process");

AUTOSTART_PROCESSES(&process_leds, &process_timer);

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(process_leds, ev, data)
{
  PROCESS_BEGIN();
  {
    static struct etimer et;
    printf("RUNNING LEDs Process...\n"); 
    
    while(1)
    {
      etimer_set(&et, CLOCK_SECOND);
      PROCESS_WAIT_EVENT();
      if (etimer_expired(&et))
      {
        printf("timer expired\n");
        etimer_reset(&et);
      }
    }
  }
  PROCESS_END();
}

PROCESS_THREAD(process_timer, ev, data)
{
  PROCESS_BEGIN();

  printf("RUNNING Timer Process...\n");
  SENSORS_ACTIVATE(button_sensor);
  
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
