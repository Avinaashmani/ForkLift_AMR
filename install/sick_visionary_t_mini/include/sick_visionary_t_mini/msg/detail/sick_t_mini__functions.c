// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_visionary_t_mini:msg/SickTMini.idl
// generated code does not contain a copyright notice
#include "sick_visionary_t_mini/msg/detail/sick_t_mini__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header_dolly`
// Member `header_pallet_detection`
#include "std_msgs/msg/detail/header__functions.h"
// Member `status_of_camera`
// Member `message`
#include "rosidl_runtime_c/string_functions.h"
// Member `left_corners`
// Member `right_corners`
// Member `point`
// Member `left_pocket`
// Member `right_pocket`
// Member `center_point`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
sick_visionary_t_mini__msg__SickTMini__init(sick_visionary_t_mini__msg__SickTMini * msg)
{
  if (!msg) {
    return false;
  }
  // header_dolly
  if (!std_msgs__msg__Header__init(&msg->header_dolly)) {
    sick_visionary_t_mini__msg__SickTMini__fini(msg);
    return false;
  }
  // status_of_camera
  if (!rosidl_runtime_c__String__init(&msg->status_of_camera)) {
    sick_visionary_t_mini__msg__SickTMini__fini(msg);
    return false;
  }
  // left_corners
  if (!geometry_msgs__msg__Vector3__init(&msg->left_corners)) {
    sick_visionary_t_mini__msg__SickTMini__fini(msg);
    return false;
  }
  // right_corners
  if (!geometry_msgs__msg__Vector3__init(&msg->right_corners)) {
    sick_visionary_t_mini__msg__SickTMini__fini(msg);
    return false;
  }
  // point
  if (!geometry_msgs__msg__Vector3__init(&msg->point)) {
    sick_visionary_t_mini__msg__SickTMini__fini(msg);
    return false;
  }
  // dolly_found
  // corners_distance
  // header_pallet_detection
  if (!std_msgs__msg__Header__init(&msg->header_pallet_detection)) {
    sick_visionary_t_mini__msg__SickTMini__fini(msg);
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    sick_visionary_t_mini__msg__SickTMini__fini(msg);
    return false;
  }
  // left_pocket
  if (!geometry_msgs__msg__Vector3__init(&msg->left_pocket)) {
    sick_visionary_t_mini__msg__SickTMini__fini(msg);
    return false;
  }
  // right_pocket
  if (!geometry_msgs__msg__Vector3__init(&msg->right_pocket)) {
    sick_visionary_t_mini__msg__SickTMini__fini(msg);
    return false;
  }
  // center_point
  if (!geometry_msgs__msg__Vector3__init(&msg->center_point)) {
    sick_visionary_t_mini__msg__SickTMini__fini(msg);
    return false;
  }
  // pallet_found
  // pallet_angle
  return true;
}

void
sick_visionary_t_mini__msg__SickTMini__fini(sick_visionary_t_mini__msg__SickTMini * msg)
{
  if (!msg) {
    return;
  }
  // header_dolly
  std_msgs__msg__Header__fini(&msg->header_dolly);
  // status_of_camera
  rosidl_runtime_c__String__fini(&msg->status_of_camera);
  // left_corners
  geometry_msgs__msg__Vector3__fini(&msg->left_corners);
  // right_corners
  geometry_msgs__msg__Vector3__fini(&msg->right_corners);
  // point
  geometry_msgs__msg__Vector3__fini(&msg->point);
  // dolly_found
  // corners_distance
  // header_pallet_detection
  std_msgs__msg__Header__fini(&msg->header_pallet_detection);
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // left_pocket
  geometry_msgs__msg__Vector3__fini(&msg->left_pocket);
  // right_pocket
  geometry_msgs__msg__Vector3__fini(&msg->right_pocket);
  // center_point
  geometry_msgs__msg__Vector3__fini(&msg->center_point);
  // pallet_found
  // pallet_angle
}

bool
sick_visionary_t_mini__msg__SickTMini__are_equal(const sick_visionary_t_mini__msg__SickTMini * lhs, const sick_visionary_t_mini__msg__SickTMini * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header_dolly
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header_dolly), &(rhs->header_dolly)))
  {
    return false;
  }
  // status_of_camera
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status_of_camera), &(rhs->status_of_camera)))
  {
    return false;
  }
  // left_corners
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->left_corners), &(rhs->left_corners)))
  {
    return false;
  }
  // right_corners
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->right_corners), &(rhs->right_corners)))
  {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->point), &(rhs->point)))
  {
    return false;
  }
  // dolly_found
  if (lhs->dolly_found != rhs->dolly_found) {
    return false;
  }
  // corners_distance
  if (lhs->corners_distance != rhs->corners_distance) {
    return false;
  }
  // header_pallet_detection
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header_pallet_detection), &(rhs->header_pallet_detection)))
  {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // left_pocket
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->left_pocket), &(rhs->left_pocket)))
  {
    return false;
  }
  // right_pocket
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->right_pocket), &(rhs->right_pocket)))
  {
    return false;
  }
  // center_point
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->center_point), &(rhs->center_point)))
  {
    return false;
  }
  // pallet_found
  if (lhs->pallet_found != rhs->pallet_found) {
    return false;
  }
  // pallet_angle
  if (lhs->pallet_angle != rhs->pallet_angle) {
    return false;
  }
  return true;
}

bool
sick_visionary_t_mini__msg__SickTMini__copy(
  const sick_visionary_t_mini__msg__SickTMini * input,
  sick_visionary_t_mini__msg__SickTMini * output)
{
  if (!input || !output) {
    return false;
  }
  // header_dolly
  if (!std_msgs__msg__Header__copy(
      &(input->header_dolly), &(output->header_dolly)))
  {
    return false;
  }
  // status_of_camera
  if (!rosidl_runtime_c__String__copy(
      &(input->status_of_camera), &(output->status_of_camera)))
  {
    return false;
  }
  // left_corners
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->left_corners), &(output->left_corners)))
  {
    return false;
  }
  // right_corners
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->right_corners), &(output->right_corners)))
  {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->point), &(output->point)))
  {
    return false;
  }
  // dolly_found
  output->dolly_found = input->dolly_found;
  // corners_distance
  output->corners_distance = input->corners_distance;
  // header_pallet_detection
  if (!std_msgs__msg__Header__copy(
      &(input->header_pallet_detection), &(output->header_pallet_detection)))
  {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // left_pocket
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->left_pocket), &(output->left_pocket)))
  {
    return false;
  }
  // right_pocket
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->right_pocket), &(output->right_pocket)))
  {
    return false;
  }
  // center_point
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->center_point), &(output->center_point)))
  {
    return false;
  }
  // pallet_found
  output->pallet_found = input->pallet_found;
  // pallet_angle
  output->pallet_angle = input->pallet_angle;
  return true;
}

sick_visionary_t_mini__msg__SickTMini *
sick_visionary_t_mini__msg__SickTMini__create()
{
  sick_visionary_t_mini__msg__SickTMini * msg = (sick_visionary_t_mini__msg__SickTMini *)malloc(sizeof(sick_visionary_t_mini__msg__SickTMini));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_visionary_t_mini__msg__SickTMini));
  bool success = sick_visionary_t_mini__msg__SickTMini__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
sick_visionary_t_mini__msg__SickTMini__destroy(sick_visionary_t_mini__msg__SickTMini * msg)
{
  if (msg) {
    sick_visionary_t_mini__msg__SickTMini__fini(msg);
  }
  free(msg);
}


bool
sick_visionary_t_mini__msg__SickTMini__Sequence__init(sick_visionary_t_mini__msg__SickTMini__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  sick_visionary_t_mini__msg__SickTMini * data = NULL;
  if (size) {
    data = (sick_visionary_t_mini__msg__SickTMini *)calloc(size, sizeof(sick_visionary_t_mini__msg__SickTMini));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_visionary_t_mini__msg__SickTMini__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_visionary_t_mini__msg__SickTMini__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sick_visionary_t_mini__msg__SickTMini__Sequence__fini(sick_visionary_t_mini__msg__SickTMini__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sick_visionary_t_mini__msg__SickTMini__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sick_visionary_t_mini__msg__SickTMini__Sequence *
sick_visionary_t_mini__msg__SickTMini__Sequence__create(size_t size)
{
  sick_visionary_t_mini__msg__SickTMini__Sequence * array = (sick_visionary_t_mini__msg__SickTMini__Sequence *)malloc(sizeof(sick_visionary_t_mini__msg__SickTMini__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = sick_visionary_t_mini__msg__SickTMini__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
sick_visionary_t_mini__msg__SickTMini__Sequence__destroy(sick_visionary_t_mini__msg__SickTMini__Sequence * array)
{
  if (array) {
    sick_visionary_t_mini__msg__SickTMini__Sequence__fini(array);
  }
  free(array);
}

bool
sick_visionary_t_mini__msg__SickTMini__Sequence__are_equal(const sick_visionary_t_mini__msg__SickTMini__Sequence * lhs, const sick_visionary_t_mini__msg__SickTMini__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_visionary_t_mini__msg__SickTMini__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_visionary_t_mini__msg__SickTMini__Sequence__copy(
  const sick_visionary_t_mini__msg__SickTMini__Sequence * input,
  sick_visionary_t_mini__msg__SickTMini__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_visionary_t_mini__msg__SickTMini);
    sick_visionary_t_mini__msg__SickTMini * data =
      (sick_visionary_t_mini__msg__SickTMini *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_visionary_t_mini__msg__SickTMini__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          sick_visionary_t_mini__msg__SickTMini__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_visionary_t_mini__msg__SickTMini__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
