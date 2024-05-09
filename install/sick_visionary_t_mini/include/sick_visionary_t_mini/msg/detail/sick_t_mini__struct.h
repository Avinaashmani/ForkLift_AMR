// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_visionary_t_mini:msg/SickTMini.idl
// generated code does not contain a copyright notice

#ifndef SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__STRUCT_H_
#define SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header_dolly'
// Member 'header_pallet_detection'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'status_of_camera'
// Member 'message'
#include "rosidl_runtime_c/string.h"
// Member 'left_corners'
// Member 'right_corners'
// Member 'point'
// Member 'left_pocket'
// Member 'right_pocket'
// Member 'center_point'
#include "geometry_msgs/msg/detail/vector3__struct.h"

// Struct defined in msg/SickTMini in the package sick_visionary_t_mini.
typedef struct sick_visionary_t_mini__msg__SickTMini
{
  std_msgs__msg__Header header_dolly;
  rosidl_runtime_c__String status_of_camera;
  geometry_msgs__msg__Vector3 left_corners;
  geometry_msgs__msg__Vector3 right_corners;
  geometry_msgs__msg__Vector3 point;
  bool dolly_found;
  double corners_distance;
  std_msgs__msg__Header header_pallet_detection;
  rosidl_runtime_c__String message;
  geometry_msgs__msg__Vector3 left_pocket;
  geometry_msgs__msg__Vector3 right_pocket;
  geometry_msgs__msg__Vector3 center_point;
  bool pallet_found;
  double pallet_angle;
} sick_visionary_t_mini__msg__SickTMini;

// Struct for a sequence of sick_visionary_t_mini__msg__SickTMini.
typedef struct sick_visionary_t_mini__msg__SickTMini__Sequence
{
  sick_visionary_t_mini__msg__SickTMini * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_visionary_t_mini__msg__SickTMini__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__STRUCT_H_
