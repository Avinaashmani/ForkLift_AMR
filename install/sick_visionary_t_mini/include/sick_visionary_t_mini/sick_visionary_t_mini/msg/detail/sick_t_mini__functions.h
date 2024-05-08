// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from sick_visionary_t_mini:msg/SickTMini.idl
// generated code does not contain a copyright notice

#ifndef SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__FUNCTIONS_H_
#define SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "sick_visionary_t_mini/msg/rosidl_generator_c__visibility_control.h"

#include "sick_visionary_t_mini/msg/detail/sick_t_mini__struct.h"

/// Initialize msg/SickTMini message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sick_visionary_t_mini__msg__SickTMini
 * )) before or use
 * sick_visionary_t_mini__msg__SickTMini__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
bool
sick_visionary_t_mini__msg__SickTMini__init(sick_visionary_t_mini__msg__SickTMini * msg);

/// Finalize msg/SickTMini message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
void
sick_visionary_t_mini__msg__SickTMini__fini(sick_visionary_t_mini__msg__SickTMini * msg);

/// Create msg/SickTMini message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sick_visionary_t_mini__msg__SickTMini__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
sick_visionary_t_mini__msg__SickTMini *
sick_visionary_t_mini__msg__SickTMini__create();

/// Destroy msg/SickTMini message.
/**
 * It calls
 * sick_visionary_t_mini__msg__SickTMini__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
void
sick_visionary_t_mini__msg__SickTMini__destroy(sick_visionary_t_mini__msg__SickTMini * msg);

/// Check for msg/SickTMini message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
bool
sick_visionary_t_mini__msg__SickTMini__are_equal(const sick_visionary_t_mini__msg__SickTMini * lhs, const sick_visionary_t_mini__msg__SickTMini * rhs);

/// Copy a msg/SickTMini message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
bool
sick_visionary_t_mini__msg__SickTMini__copy(
  const sick_visionary_t_mini__msg__SickTMini * input,
  sick_visionary_t_mini__msg__SickTMini * output);

/// Initialize array of msg/SickTMini messages.
/**
 * It allocates the memory for the number of elements and calls
 * sick_visionary_t_mini__msg__SickTMini__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
bool
sick_visionary_t_mini__msg__SickTMini__Sequence__init(sick_visionary_t_mini__msg__SickTMini__Sequence * array, size_t size);

/// Finalize array of msg/SickTMini messages.
/**
 * It calls
 * sick_visionary_t_mini__msg__SickTMini__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
void
sick_visionary_t_mini__msg__SickTMini__Sequence__fini(sick_visionary_t_mini__msg__SickTMini__Sequence * array);

/// Create array of msg/SickTMini messages.
/**
 * It allocates the memory for the array and calls
 * sick_visionary_t_mini__msg__SickTMini__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
sick_visionary_t_mini__msg__SickTMini__Sequence *
sick_visionary_t_mini__msg__SickTMini__Sequence__create(size_t size);

/// Destroy array of msg/SickTMini messages.
/**
 * It calls
 * sick_visionary_t_mini__msg__SickTMini__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
void
sick_visionary_t_mini__msg__SickTMini__Sequence__destroy(sick_visionary_t_mini__msg__SickTMini__Sequence * array);

/// Check for msg/SickTMini message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
bool
sick_visionary_t_mini__msg__SickTMini__Sequence__are_equal(const sick_visionary_t_mini__msg__SickTMini__Sequence * lhs, const sick_visionary_t_mini__msg__SickTMini__Sequence * rhs);

/// Copy an array of msg/SickTMini messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_visionary_t_mini
bool
sick_visionary_t_mini__msg__SickTMini__Sequence__copy(
  const sick_visionary_t_mini__msg__SickTMini__Sequence * input,
  sick_visionary_t_mini__msg__SickTMini__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__FUNCTIONS_H_
