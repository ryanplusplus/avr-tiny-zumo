/*!
 * @file
 * @brief
 */

#include "lsm303d.h"
#include "tiny_utils.h"

enum {
  startup_delay_msec = 100,
  poll_period_msec = 10,
};

enum {
  address = 0x1D,

  auto_increment = (1 << 7),

  register_ctrl1 = 0x20,
  register_out_x_l_a = 0x28
};

static bool read_acceleration(lsm303d_t* self)
{
  return tiny_i2c_read(
    self->i2c,
    address,
    false,
    self->read_buffer.raw,
    sizeof(self->read_buffer));
}

static bool set_up_acceleration_read(lsm303d_t* self)
{
  static const uint8_t buffer[] = {
    register_out_x_l_a | auto_increment
  };

  return tiny_i2c_write(
    self->i2c,
    address,
    true,
    buffer,
    sizeof(buffer));
}

static bool initialize_accelerometer(lsm303d_t* self)
{
  static const uint8_t buffer[] = {
    register_ctrl1,
    0x77 // 200 Hz, all axes enabled
  };

  return tiny_i2c_write(
    self->i2c,
    address,
    false,
    buffer,
    sizeof(buffer));
}

static void poll(tiny_timer_group_t* timer_group, void* context)
{
  reinterpret(self, context, lsm303d_t*);
  (void)timer_group;

  if(!self->initialized) {
    if(initialize_accelerometer(self)) {
      self->initialized = true;
    }
    else {
      return;
    }
  }

  if(!set_up_acceleration_read(self)) {
    self->initialized = false;
    return;
  }

  if(!read_acceleration(self)) {
    self->initialized = false;
    return;
  }

  tiny_single_subscriber_event_publish(
    &self->acceleration_update,
    &self->read_buffer.acceleration);
}

static void startup_delay_complete(tiny_timer_group_t* timer_group, void* context)
{
  reinterpret(self, context, lsm303d_t*);
  tiny_timer_start_periodic(timer_group, &self->timer, poll_period_msec, poll, self);
}

void lsm303d_init(lsm303d_t* self, tiny_timer_group_t* timer_group, i_tiny_i2c_t* i2c)
{
  self->i2c = i2c;

  tiny_single_subscriber_event_init(&self->acceleration_update);

  tiny_timer_start(
    timer_group,
    &self->timer,
    startup_delay_msec,
    startup_delay_complete,
    self);
}

i_tiny_event_t* lsm303d_on_update(lsm303d_t* self)
{
  return &self->acceleration_update.interface;
}
