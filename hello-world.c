/**
 * \file
 *         A very simple Contiki application showing how Contiki programs look
 * \author
 *        Gian Franco Lasala 
 */

#include "contiki.h"

#include <stdio.h> /* For printf() */

/*---------------------------------------------------------------------------*/

PROCESS(process_leds, "LEDs Process");
PROCESS(process_timer, "Timer Process");

AUTOSTART_PROCESSES(&process_leds, &process_timer);

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(process_leds, ev, data)
{
  PROCESS_BEGIN();

  printf("RUNNING LEDs Process...\n");
  
  PROCESS_END();
}

PROCESS_THREAD(process_timer, ev, data)
{
  PROCESS_BEGIN();

  printf("RUNNING Timer Process...\n");
  
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
