/*!
 * @file
 * @brief
 */

#ifndef data_model_key_value_pairs_h
#define data_model_key_value_pairs_h

#include "tiny_ram_key_value_store_macros.h"
#include "motor_power.h"
#include "acceleration.h"
#include "line_reading.h"
#include "buzzer_frequency.h"

// clang-format off
#define data_model_key_value_pairs(pair) \
  pair(key_left_motor,                  motor_power_t) \
  pair(key_right_motor,                 motor_power_t) \
  pair(key_line_reading,                line_reading_t) \
  pair(key_acceleration,                acceleration_t) \
  pair(key_buzzer_frequency,            buzzer_frequency_t) \

// clang-format on

enumerate_ram_key_value_pairs(data_model_key_value_pairs);

#endif
