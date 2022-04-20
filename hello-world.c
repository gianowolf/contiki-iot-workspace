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

/* Values */
#define TIME_BLUE  3
#define TIME_RED   5
#define TIME_GREEN 7

/* Utils */
#include <stdio.h> /* For printf() */

/* Types */
typedef unsigned char uint8;

/* Functions */
int f_leds_init();
int f_leds_check();

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
    f_leds_init(&counter_leds);

    static struct etimer et;
    printf("RUNNING LEDs Process...\n"); 
    
    etimer_set(&et, CLOCK_SECOND);        /* SET TIMER 1.00 s */

    while(1)
    {
      PROCESS_WAIT_EVENT();                 /* WAIT EVENT */  
      if (etimer_expired(&et))              /* IF Timer Expired */
      {
        f_leds_check();                       /* Do Tasks */
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
    printf(" Contadores: %d [B], %d [R] , %d [G]",--counter[0],--counter[1],--counter[2]);    
  }
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/

int f_leds_init(int *counter)
{
  counter[0] = TIME_BLUE;
  counter[1] = TIME_RED;
  counter[2] = TIME_GREEN;

  return 0;
}

int f_leds_check()
{
  printf("Check Leds\n");

  return 0;
}

