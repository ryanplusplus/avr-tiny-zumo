/*!
 * @file
 * @brief
 */

#ifndef accelerometer_plugin_h
#define accelerometer_plugin_h

#include "i_tiny_key_value_store.h"
#include "tiny_event_subscription.h"
#include "lsm303d.h"

void accelerometer_plugin_init(
  i_tiny_key_value_store_t* data_model,
  tiny_timer_group_t* timer_group);

#endif
