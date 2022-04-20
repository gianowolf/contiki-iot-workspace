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
int leds_init();
int leds_check();


/* Shareds */


/*---------------------------------------------------------------------------*/

PROCESS(process_leds, "LEDs Process");
PROCESS(process_timer, "Timer Process");

AUTOSTART_PROCESSES(&process_leds, &process_timer);

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(process_leds, ev, data)
{
  PROCESS_BEGIN();
  {
    int counter_leds[3];
    leds_init(&counter_leds);

    static struct etimer et;
    printf("RUNNING LEDs Process...\n"); 
    
    etimer_set(&et, CLOCK_SECOND);        /* SET TIMER 1.00 s */

    while(1)
    {
      PROCESS_WAIT_EVENT();                 /* WAIT EVENT */  
      if (etimer_expired(&et))              /* IF Timer Expired */
      {
        leds_check();                       /* Do Tasks */
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

int leds_init(int *counter)
{

  return 0;
}

int leds_check()
{
  printf("Check Leds\n");

  return 0;
}

