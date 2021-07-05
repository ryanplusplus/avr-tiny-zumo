/*!
 * @file
 * @brief
 */

#ifndef application_h
#define application_h

#include "i_tiny_key_value_store.h"
#include "tiny_timer.h"

static inline void application_init(
  i_tiny_key_value_store_t *data_model,
  tiny_timer_group_t *timer_group)
{
  (void)data_model;
  (void)timer_group;
}

#endif
