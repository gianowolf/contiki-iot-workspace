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

/* Constants */
#define N_LEDS 3

/* Enumerations */
enum times{ t_blue = 3, t_red = 5, t_green = 7};
enum state{ enabled = 1, disabled = 0};

/* Functions */
uint8 f_leds_init(uint8* counter);
uint8 f_leds_check(uint8* counter);

/* Shareds */

/*---------------------------------------------------------------------------*/

PROCESS(process_leds, "LEDs Process");
PROCESS(process_timer, "Timer Process");

AUTOSTART_PROCESSES(&process_leds, &process_timer);

/*---------------------------------------------------------------------------*/

uint8 counter_leds[3] = {t_blue, t_red, t_green};
uint8 status_leds = disabled;


PROCESS_THREAD(process_leds, ev, data)
{
  PROCESS_BEGIN();
  {
  static struct etimer et;
  printf("RUNNING LEDs Process...\n"); 
  etimer_set(&et, CLOCK_SECOND);        /* SET TIMER 1.00 s */

    while(1)
    {
      PROCESS_WAIT_EVENT();                /* WAIT EVENT */  

      if (etimer_expired(&et))             /* IF Timer Expired */
      {
        f_leds_check();
        printf(" Contadores: %d [B], %d [R] , %d [G]\n",counter_leds[0],counter_leds[1],counter_leds[2]);
        etimer_reset(&et);                 /* Reset Timer */
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

uint8 f_leds_check(uint8* counters)
{
  if(--counter_leds[0] == 0)
  {
    leds_toggle(LEDS_BLUE);
    counter_leds[0] = t_blue;
  }

  if(--counter_leds[1] == 0)
  {
    leds_toggle(LEDS_RED);
    counter_leds[1] = t_red;
  }

  if(--counter_leds[2] == 0)
  {
    leds_toggle(LEDS_GREEN);
    counter_leds[2] = t_green;
  }
    



  return 0;
}

