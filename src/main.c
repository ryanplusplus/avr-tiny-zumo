/*!
 * @file
 * @brief
 */

#include <avr/interrupt.h>
#include "system_tick.h"
#include "heartbeat.h"
#include "tiny_timer.h"
#include "watchdog.h"
#include "clock.h"
#include "data_model.h"
#include "application.h"
#include "bsp.h"

static tiny_timer_group_t timer_group;
static data_model_t data_model;

int main(void)
{
  cli();
  {
    clock_init();
    tiny_timer_group_init(&timer_group, system_tick_init());
    watchdog_init(&timer_group);
    heartbeat_init(&timer_group);
  }
  sei();

  data_model_init(&data_model);
  bsp_init(data_model_key_value_store(&data_model), &timer_group);
  application_init(data_model_key_value_store(&data_model), &timer_group);

  while(1) {
    tiny_timer_group_run(&timer_group);
  }
}
