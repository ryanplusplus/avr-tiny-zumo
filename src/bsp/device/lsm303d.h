/*!
 * @file
 * @brief
 */

#ifndef lsm303d_h
#define lsm303d_h

#include <stdbool.h>
#include "hal/i_tiny_i2c.h"
#include "acceleration.h"
#include "tiny_timer.h"
#include "tiny_single_subscriber_event.h"

typedef acceleration_t lsm303d_on_acceleration_update_t;

typedef struct {
  union {
    uint8_t raw[0];
    acceleration_t acceleration;
  };
} lsm303d_read_buffer_t;

typedef struct {
  i_tiny_i2c_t* i2c;
  tiny_timer_group_t* timer_group;
  tiny_timer_t timer;

  bool initialized;

  lsm303d_read_buffer_t read_buffer;

  tiny_single_subscriber_event_t acceleration_update;
} lsm303d_t;

void lsm303d_init(lsm303d_t* self, tiny_timer_group_t* timer_group, i_tiny_i2c_t* i2c);

i_tiny_event_t* lsm303d_on_acceleration_update(lsm303d_t* self);

#endif
