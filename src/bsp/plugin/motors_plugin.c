/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include <avr/io.h>
#include "motors_plugin.h"
#include "data_model_key_value_pairs.h"

static struct {
  tiny_event_subscription_t on_change_subscription;
  i_tiny_key_value_store_t* data_model;
} self;

static void data_changed(void* context, const void* _args)
{
  reinterpret(args, _args, const tiny_key_value_store_on_change_args_t*);
  reinterpret(power, args->value, const motor_power_t*);
  (void)context;

  switch(args->key) {
    case key_left_motor_power:
      if(*power < 0) {
        PORTB |= _BV(0);
        OCR1B = -*power;
      }
      else {
        PORTB &= ~_BV(0);
        OCR1B = *power;
      }
      break;

    case key_right_motor_power:
      if(*power < 0) {
        PORTD |= _BV(7);
        OCR1A = -*power;
      }
      else {
        PORTD &= ~_BV(7);
        OCR1A = *power;
      }
      break;
  }
}

void motors_plugin_init(i_tiny_key_value_store_t* data_model)
{
  // Set PD7 (right direction) as an output
  DDRD |= _BV(7);

  // Set PB0 (left direction), PB1/OC1A (right power), PB2/OC1B (left power) as outputs
  DDRB |= _BV(0) | _BV(1) | _BV(2);

  // OC1A high initially, low at compare match
  // OC1B high initially, low at compare match
  // Phase and frequency correct PWM mode (TOP set bo ICR1)
  // Clk/1 (no prescalar)
  TCCR1A |= _BV(COM1A1) | _BV(COM1B1);
  TCCR1B |= _BV(WGM13) | _BV(CS10);

  // Set max duty cycle to 100
  ICR1 = 100;

  tiny_event_subscription_init(&self.on_change_subscription, NULL, data_changed);
  tiny_event_subscribe(tiny_key_value_store_on_change(data_model), &self.on_change_subscription);
}
