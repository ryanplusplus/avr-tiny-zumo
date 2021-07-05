/*!
 * @file
 * @brief
 */

#include "accelerometer_plugin.h"
#include "data_model_key_value_pairs.h"
#include "lsm303d.h"
#include "twi.h"
#include "tiny_utils.h"

static struct {
  lsm303d_t lsm303;
  tiny_event_subscription_t subscription;
} self;

static void acceleration_updated(void* context, const void* args)
{
  reinterpret(data_model, context, i_tiny_key_value_store_t*);
  tiny_key_value_store_write(data_model, key_acceleration, args);
}

void accelerometer_plugin_init(
  i_tiny_key_value_store_t* data_model,
  tiny_timer_group_t* timer_group)
{
  lsm303d_init(&self.lsm303, timer_group, twi_init());
  tiny_event_subscription_init(&self.subscription, data_model, acceleration_updated);
  tiny_event_subscribe(lsm303d_on_update(&self.lsm303), &self.subscription);
}
