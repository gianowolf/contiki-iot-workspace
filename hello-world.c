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
AUTOSTART_PROCESSES(&process_leds);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(process_leds, ev, data)
{
  PROCESS_BEGIN();

  printf("RUNNING LEDs Process...\n");
  
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
