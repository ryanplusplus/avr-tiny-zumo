/*!
 * @file
 * @brief
 */

#include <avr/io.h>
#include "buzzer_plugin.h"
#include "data_model_key_value_pairs.h"

static struct {
  tiny_event_subscription_t on_change_subscription;
} self;

static void data_changed(void* context, const void* _args)
{
  reinterpret(args, _args, const tiny_key_value_store_on_change_args_t*);
  reinterpret(frequency, args->value, const buzzer_frequency_t*);
  (void)context;

  if(args->key == key_buzzer_frequency) {
    if(*frequency == 0) {
      // Set PD3 as an input
      DDRD &= ~_BV(3);
    }
    else {
      uint32_t period = F_CPU / *frequency;

      if(period > 255) {
        period = 255;
      }

      OCR2A = period;
      OCR2B = OCR2A / 2;

      // Set PD3 as an output
      DDRD |= _BV(3);
    }
  }
}

void buzzer_plugin_init(i_tiny_key_value_store_t* data_model)
{
  // OC2B high initially, low at compare match
  // Fast PWM mode (TOP set by OCRA)
  // Clk/256 (no prescalar)
  TCCR2A |= _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B |= _BV(WGM22) | _BV(CS22) | _BV(CS21);

  tiny_event_subscription_init(&self.on_change_subscription, NULL, data_changed);
  tiny_event_subscribe(tiny_key_value_store_on_change(data_model), &self.on_change_subscription);
}
