/*!
 * @file
 * @brief
 */

#ifndef demo_plugin_h
#define demo_plugin_h

#include "i_tiny_key_value_store.h"
#include "tiny_timer.h"

void demo_plugin_init(
  i_tiny_key_value_store_t* data_model,
  tiny_timer_group_t* timer_group);

#endif
