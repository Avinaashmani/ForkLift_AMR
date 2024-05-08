// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from forklift_interfaces:srv/ForkLiftDock.idl
// generated code does not contain a copyright notice
#include "forklift_interfaces/srv/detail/fork_lift_dock__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "forklift_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "forklift_interfaces/srv/detail/fork_lift_dock__struct.h"
#include "forklift_interfaces/srv/detail/fork_lift_dock__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ForkLiftDock_Request__ros_msg_type = forklift_interfaces__srv__ForkLiftDock_Request;

static bool _ForkLiftDock_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ForkLiftDock_Request__ros_msg_type * ros_message = static_cast<const _ForkLiftDock_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: dock_request
  {
    cdr << (ros_message->dock_request ? true : false);
  }

  // Field name: undock_request
  {
    cdr << (ros_message->undock_request ? true : false);
  }

  return true;
}

static bool _ForkLiftDock_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ForkLiftDock_Request__ros_msg_type * ros_message = static_cast<_ForkLiftDock_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: dock_request
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->dock_request = tmp ? true : false;
  }

  // Field name: undock_request
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->undock_request = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_forklift_interfaces
size_t get_serialized_size_forklift_interfaces__srv__ForkLiftDock_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ForkLiftDock_Request__ros_msg_type * ros_message = static_cast<const _ForkLiftDock_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name dock_request
  {
    size_t item_size = sizeof(ros_message->dock_request);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name undock_request
  {
    size_t item_size = sizeof(ros_message->undock_request);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ForkLiftDock_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_forklift_interfaces__srv__ForkLiftDock_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_forklift_interfaces
size_t max_serialized_size_forklift_interfaces__srv__ForkLiftDock_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: dock_request
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: undock_request
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = forklift_interfaces__srv__ForkLiftDock_Request;
    is_plain =
      (
      offsetof(DataType, undock_request) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ForkLiftDock_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_forklift_interfaces__srv__ForkLiftDock_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ForkLiftDock_Request = {
  "forklift_interfaces::srv",
  "ForkLiftDock_Request",
  _ForkLiftDock_Request__cdr_serialize,
  _ForkLiftDock_Request__cdr_deserialize,
  _ForkLiftDock_Request__get_serialized_size,
  _ForkLiftDock_Request__max_serialized_size
};

static rosidl_message_type_support_t _ForkLiftDock_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ForkLiftDock_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, forklift_interfaces, srv, ForkLiftDock_Request)() {
  return &_ForkLiftDock_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "forklift_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "forklift_interfaces/srv/detail/fork_lift_dock__struct.h"
// already included above
// #include "forklift_interfaces/srv/detail/fork_lift_dock__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ForkLiftDock_Response__ros_msg_type = forklift_interfaces__srv__ForkLiftDock_Response;

static bool _ForkLiftDock_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ForkLiftDock_Response__ros_msg_type * ros_message = static_cast<const _ForkLiftDock_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: dock_response
  {
    cdr << (ros_message->dock_response ? true : false);
  }

  // Field name: undock_response
  {
    cdr << (ros_message->undock_response ? true : false);
  }

  return true;
}

static bool _ForkLiftDock_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ForkLiftDock_Response__ros_msg_type * ros_message = static_cast<_ForkLiftDock_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: dock_response
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->dock_response = tmp ? true : false;
  }

  // Field name: undock_response
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->undock_response = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_forklift_interfaces
size_t get_serialized_size_forklift_interfaces__srv__ForkLiftDock_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ForkLiftDock_Response__ros_msg_type * ros_message = static_cast<const _ForkLiftDock_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name dock_response
  {
    size_t item_size = sizeof(ros_message->dock_response);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name undock_response
  {
    size_t item_size = sizeof(ros_message->undock_response);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ForkLiftDock_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_forklift_interfaces__srv__ForkLiftDock_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_forklift_interfaces
size_t max_serialized_size_forklift_interfaces__srv__ForkLiftDock_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: dock_response
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: undock_response
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = forklift_interfaces__srv__ForkLiftDock_Response;
    is_plain =
      (
      offsetof(DataType, undock_response) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ForkLiftDock_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_forklift_interfaces__srv__ForkLiftDock_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ForkLiftDock_Response = {
  "forklift_interfaces::srv",
  "ForkLiftDock_Response",
  _ForkLiftDock_Response__cdr_serialize,
  _ForkLiftDock_Response__cdr_deserialize,
  _ForkLiftDock_Response__get_serialized_size,
  _ForkLiftDock_Response__max_serialized_size
};

static rosidl_message_type_support_t _ForkLiftDock_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ForkLiftDock_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, forklift_interfaces, srv, ForkLiftDock_Response)() {
  return &_ForkLiftDock_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "forklift_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "forklift_interfaces/srv/fork_lift_dock.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ForkLiftDock__callbacks = {
  "forklift_interfaces::srv",
  "ForkLiftDock",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, forklift_interfaces, srv, ForkLiftDock_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, forklift_interfaces, srv, ForkLiftDock_Response)(),
};

static rosidl_service_type_support_t ForkLiftDock__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ForkLiftDock__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, forklift_interfaces, srv, ForkLiftDock)() {
  return &ForkLiftDock__handle;
}

#if defined(__cplusplus)
}
#endif
