/*!
 * @file
 * @brief
 */

#ifndef line_reading_h
#define line_reading_h

#include <stdbool.h>

typedef struct
{
  bool left_outer;
  bool left_middle;
  bool left_inner;
  bool right_inner;
  bool right_middle;
  bool right_outer;
} line_reading_t;

#endif
