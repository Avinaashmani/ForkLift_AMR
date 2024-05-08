// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from forklift_interfaces:srv/ForkLiftDock.idl
// generated code does not contain a copyright notice

#ifndef FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__STRUCT_H_
#define FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/ForkLiftDock in the package forklift_interfaces.
typedef struct forklift_interfaces__srv__ForkLiftDock_Request
{
  bool dock_request;
  bool undock_request;
} forklift_interfaces__srv__ForkLiftDock_Request;

// Struct for a sequence of forklift_interfaces__srv__ForkLiftDock_Request.
typedef struct forklift_interfaces__srv__ForkLiftDock_Request__Sequence
{
  forklift_interfaces__srv__ForkLiftDock_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} forklift_interfaces__srv__ForkLiftDock_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/ForkLiftDock in the package forklift_interfaces.
typedef struct forklift_interfaces__srv__ForkLiftDock_Response
{
  bool dock_response;
  bool undock_response;
} forklift_interfaces__srv__ForkLiftDock_Response;

// Struct for a sequence of forklift_interfaces__srv__ForkLiftDock_Response.
typedef struct forklift_interfaces__srv__ForkLiftDock_Response__Sequence
{
  forklift_interfaces__srv__ForkLiftDock_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} forklift_interfaces__srv__ForkLiftDock_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__STRUCT_H_
