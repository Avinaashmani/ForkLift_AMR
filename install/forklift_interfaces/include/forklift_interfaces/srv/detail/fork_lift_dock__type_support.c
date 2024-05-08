// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from forklift_interfaces:srv/ForkLiftDock.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "forklift_interfaces/srv/detail/fork_lift_dock__rosidl_typesupport_introspection_c.h"
#include "forklift_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "forklift_interfaces/srv/detail/fork_lift_dock__functions.h"
#include "forklift_interfaces/srv/detail/fork_lift_dock__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  forklift_interfaces__srv__ForkLiftDock_Request__init(message_memory);
}

void ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_fini_function(void * message_memory)
{
  forklift_interfaces__srv__ForkLiftDock_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_message_member_array[2] = {
  {
    "dock_request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(forklift_interfaces__srv__ForkLiftDock_Request, dock_request),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "undock_request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(forklift_interfaces__srv__ForkLiftDock_Request, undock_request),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_message_members = {
  "forklift_interfaces__srv",  // message namespace
  "ForkLiftDock_Request",  // message name
  2,  // number of fields
  sizeof(forklift_interfaces__srv__ForkLiftDock_Request),
  ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_message_member_array,  // message members
  ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_message_type_support_handle = {
  0,
  &ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_forklift_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, forklift_interfaces, srv, ForkLiftDock_Request)() {
  if (!ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_message_type_support_handle.typesupport_identifier) {
    ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ForkLiftDock_Request__rosidl_typesupport_introspection_c__ForkLiftDock_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "forklift_interfaces/srv/detail/fork_lift_dock__rosidl_typesupport_introspection_c.h"
// already included above
// #include "forklift_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "forklift_interfaces/srv/detail/fork_lift_dock__functions.h"
// already included above
// #include "forklift_interfaces/srv/detail/fork_lift_dock__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  forklift_interfaces__srv__ForkLiftDock_Response__init(message_memory);
}

void ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_fini_function(void * message_memory)
{
  forklift_interfaces__srv__ForkLiftDock_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_message_member_array[2] = {
  {
    "dock_response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(forklift_interfaces__srv__ForkLiftDock_Response, dock_response),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "undock_response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(forklift_interfaces__srv__ForkLiftDock_Response, undock_response),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_message_members = {
  "forklift_interfaces__srv",  // message namespace
  "ForkLiftDock_Response",  // message name
  2,  // number of fields
  sizeof(forklift_interfaces__srv__ForkLiftDock_Response),
  ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_message_member_array,  // message members
  ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_message_type_support_handle = {
  0,
  &ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_forklift_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, forklift_interfaces, srv, ForkLiftDock_Response)() {
  if (!ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_message_type_support_handle.typesupport_identifier) {
    ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ForkLiftDock_Response__rosidl_typesupport_introspection_c__ForkLiftDock_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "forklift_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "forklift_interfaces/srv/detail/fork_lift_dock__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers forklift_interfaces__srv__detail__fork_lift_dock__rosidl_typesupport_introspection_c__ForkLiftDock_service_members = {
  "forklift_interfaces__srv",  // service namespace
  "ForkLiftDock",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // forklift_interfaces__srv__detail__fork_lift_dock__rosidl_typesupport_introspection_c__ForkLiftDock_Request_message_type_support_handle,
  NULL  // response message
  // forklift_interfaces__srv__detail__fork_lift_dock__rosidl_typesupport_introspection_c__ForkLiftDock_Response_message_type_support_handle
};

static rosidl_service_type_support_t forklift_interfaces__srv__detail__fork_lift_dock__rosidl_typesupport_introspection_c__ForkLiftDock_service_type_support_handle = {
  0,
  &forklift_interfaces__srv__detail__fork_lift_dock__rosidl_typesupport_introspection_c__ForkLiftDock_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, forklift_interfaces, srv, ForkLiftDock_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, forklift_interfaces, srv, ForkLiftDock_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_forklift_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, forklift_interfaces, srv, ForkLiftDock)() {
  if (!forklift_interfaces__srv__detail__fork_lift_dock__rosidl_typesupport_introspection_c__ForkLiftDock_service_type_support_handle.typesupport_identifier) {
    forklift_interfaces__srv__detail__fork_lift_dock__rosidl_typesupport_introspection_c__ForkLiftDock_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)forklift_interfaces__srv__detail__fork_lift_dock__rosidl_typesupport_introspection_c__ForkLiftDock_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, forklift_interfaces, srv, ForkLiftDock_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, forklift_interfaces, srv, ForkLiftDock_Response)()->data;
  }

  return &forklift_interfaces__srv__detail__fork_lift_dock__rosidl_typesupport_introspection_c__ForkLiftDock_service_type_support_handle;
}
