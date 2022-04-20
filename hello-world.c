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

/* Functions */
int check_leds();

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
    
    etimer_set(&et, CLOCK_SECOND);        /* SET: 1s */

    while(1)
    {
      PROCESS_WAIT_EVENT();                 /* WAIT EVENT */  
      if (etimer_expired(&et))              /* IF Timer Expired */
      {
        check_leds();                       /* Do Tasks */
        etimer_reset(&et);                  /* Reset Timer */
      }
    }
  }
  PROCESS_END();
}

PROCESS_THREAD(process_timer, ev, data)
{
  PROCESS_BEGIN();
  {
    printf("RUNNING Timer Process...\n");
    
  }
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/

check_leds()
{
  printf("Check Leds\n");

  return 0;
}