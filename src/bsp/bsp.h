/*!
 * @file
 * @brief
 */

#ifndef bsp_h
#define bsp_h

#include "i_tiny_key_value_store.h"
#include "tiny_timer.h"
#include "accelerometer_plugin.h"
#include "line_sensors_plugin.h"
#include "motors_plugin.h"

static inline void bsp_init(
  i_tiny_key_value_store_t* data_model,
  tiny_timer_group_t* timer_group)
{
  accelerometer_plugin_init(data_model, timer_group);
  line_sensors_plugin_init(data_model, timer_group);
  motors_plugin_init(data_model, timer_group);
}

#endif
