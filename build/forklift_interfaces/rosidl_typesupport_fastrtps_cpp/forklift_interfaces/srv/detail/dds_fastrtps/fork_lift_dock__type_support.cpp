// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from forklift_interfaces:srv/ForkLiftDock.idl
// generated code does not contain a copyright notice
#include "forklift_interfaces/srv/detail/fork_lift_dock__rosidl_typesupport_fastrtps_cpp.hpp"
#include "forklift_interfaces/srv/detail/fork_lift_dock__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace forklift_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_forklift_interfaces
cdr_serialize(
  const forklift_interfaces::srv::ForkLiftDock_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: dock_request
  cdr << (ros_message.dock_request ? true : false);
  // Member: undock_request
  cdr << (ros_message.undock_request ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_forklift_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  forklift_interfaces::srv::ForkLiftDock_Request & ros_message)
{
  // Member: dock_request
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.dock_request = tmp ? true : false;
  }

  // Member: undock_request
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.undock_request = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_forklift_interfaces
get_serialized_size(
  const forklift_interfaces::srv::ForkLiftDock_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: dock_request
  {
    size_t item_size = sizeof(ros_message.dock_request);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: undock_request
  {
    size_t item_size = sizeof(ros_message.undock_request);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_forklift_interfaces
max_serialized_size_ForkLiftDock_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: dock_request
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: undock_request
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _ForkLiftDock_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const forklift_interfaces::srv::ForkLiftDock_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ForkLiftDock_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<forklift_interfaces::srv::ForkLiftDock_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ForkLiftDock_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const forklift_interfaces::srv::ForkLiftDock_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ForkLiftDock_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ForkLiftDock_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _ForkLiftDock_Request__callbacks = {
  "forklift_interfaces::srv",
  "ForkLiftDock_Request",
  _ForkLiftDock_Request__cdr_serialize,
  _ForkLiftDock_Request__cdr_deserialize,
  _ForkLiftDock_Request__get_serialized_size,
  _ForkLiftDock_Request__max_serialized_size
};

static rosidl_message_type_support_t _ForkLiftDock_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ForkLiftDock_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace forklift_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_forklift_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<forklift_interfaces::srv::ForkLiftDock_Request>()
{
  return &forklift_interfaces::srv::typesupport_fastrtps_cpp::_ForkLiftDock_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, forklift_interfaces, srv, ForkLiftDock_Request)() {
  return &forklift_interfaces::srv::typesupport_fastrtps_cpp::_ForkLiftDock_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace forklift_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_forklift_interfaces
cdr_serialize(
  const forklift_interfaces::srv::ForkLiftDock_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: dock_response
  cdr << (ros_message.dock_response ? true : false);
  // Member: undock_response
  cdr << (ros_message.undock_response ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_forklift_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  forklift_interfaces::srv::ForkLiftDock_Response & ros_message)
{
  // Member: dock_response
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.dock_response = tmp ? true : false;
  }

  // Member: undock_response
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.undock_response = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_forklift_interfaces
get_serialized_size(
  const forklift_interfaces::srv::ForkLiftDock_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: dock_response
  {
    size_t item_size = sizeof(ros_message.dock_response);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: undock_response
  {
    size_t item_size = sizeof(ros_message.undock_response);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_forklift_interfaces
max_serialized_size_ForkLiftDock_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: dock_response
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: undock_response
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _ForkLiftDock_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const forklift_interfaces::srv::ForkLiftDock_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ForkLiftDock_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<forklift_interfaces::srv::ForkLiftDock_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ForkLiftDock_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const forklift_interfaces::srv::ForkLiftDock_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ForkLiftDock_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ForkLiftDock_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _ForkLiftDock_Response__callbacks = {
  "forklift_interfaces::srv",
  "ForkLiftDock_Response",
  _ForkLiftDock_Response__cdr_serialize,
  _ForkLiftDock_Response__cdr_deserialize,
  _ForkLiftDock_Response__get_serialized_size,
  _ForkLiftDock_Response__max_serialized_size
};

static rosidl_message_type_support_t _ForkLiftDock_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ForkLiftDock_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace forklift_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_forklift_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<forklift_interfaces::srv::ForkLiftDock_Response>()
{
  return &forklift_interfaces::srv::typesupport_fastrtps_cpp::_ForkLiftDock_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, forklift_interfaces, srv, ForkLiftDock_Response)() {
  return &forklift_interfaces::srv::typesupport_fastrtps_cpp::_ForkLiftDock_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace forklift_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _ForkLiftDock__callbacks = {
  "forklift_interfaces::srv",
  "ForkLiftDock",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, forklift_interfaces, srv, ForkLiftDock_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, forklift_interfaces, srv, ForkLiftDock_Response)(),
};

static rosidl_service_type_support_t _ForkLiftDock__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ForkLiftDock__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace forklift_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_forklift_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<forklift_interfaces::srv::ForkLiftDock>()
{
  return &forklift_interfaces::srv::typesupport_fastrtps_cpp::_ForkLiftDock__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, forklift_interfaces, srv, ForkLiftDock)() {
  return &forklift_interfaces::srv::typesupport_fastrtps_cpp::_ForkLiftDock__handle;
}

#ifdef __cplusplus
}
#endif
