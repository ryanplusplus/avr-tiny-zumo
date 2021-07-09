/*!
 * @file
 * @brief
 */

#include <avr/io.h>
#include <util/delay.h>
#include "line_sensors_plugin.h"
#include "data_model_key_value_pairs.h"

enum {
  poll_period_msec = 100,
  threshold_usec = 200
};

static struct {
  tiny_timer_t timer;
} self;

static void poll(tiny_timer_group_t* timer_group, void* context)
{
  reinterpret(data_model, context, i_tiny_key_value_store_t*);
  (void)timer_group;

  // Turn on the emitters
  DDRD |= _BV(4) | _BV(5);
  PORTD |= _BV(4) | _BV(5);
  DDRC |= _BV(0) | _BV(2) | _BV(3);
  PORTC |= _BV(0) | _BV(2) | _BV(3);
  DDRB |= _BV(3);
  PORTB |= _BV(3);

  // Charge the capacitor
  _delay_us(50);

  // Turn off the emitters
  DDRD &= ~(_BV(4) | _BV(5));
  DDRC &= ~(_BV(0) | _BV(2) | _BV(3));
  DDRB &= ~_BV(3);

  _delay_us(threshold_usec);

  // Read sensors
  bool outer_left = PIND & _BV(4);
  bool middle_left = PINC & _BV(3);
  bool inner_left = PINB & _BV(3);
  bool inner_right = PINC & _BV(0);
  bool middle_right = PINC & _BV(2);
  bool outer_right = PIND & _BV(5);

  tiny_key_value_store_write(data_model, key_outer_left_line_detected, &outer_left);
  tiny_key_value_store_write(data_model, key_middle_left_line_detected, &middle_left);
  tiny_key_value_store_write(data_model, key_inner_left_line_detected, &inner_left);
  tiny_key_value_store_write(data_model, key_inner_right_line_detected, &inner_right);
  tiny_key_value_store_write(data_model, key_middle_right_line_detected, &middle_right);
  tiny_key_value_store_write(data_model, key_outer_right_line_detected, &outer_right);
}

void line_sensors_plugin_init(
  i_tiny_key_value_store_t* data_model,
  tiny_timer_group_t* timer_group)
{
  tiny_timer_start_periodic(
    timer_group,
    &self.timer,
    poll_period_msec,
    poll,
    data_model);
}
