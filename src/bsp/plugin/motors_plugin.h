/*!
 * @file
 * @brief
 */

#ifndef motors_plugin_h
#define motors_plugin_h

#include "i_tiny_key_value_store.h"
#include "tiny_timer.h"

void motors_plugin_init(
  i_tiny_key_value_store_t* data_model,
  tiny_timer_group_t* timer_group);

#endif
