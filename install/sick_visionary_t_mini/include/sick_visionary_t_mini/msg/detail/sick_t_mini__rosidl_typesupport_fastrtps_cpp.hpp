// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from sick_visionary_t_mini:msg/SickTMini.idl
// generated code does not contain a copyright notice

#ifndef SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "sick_visionary_t_mini/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "sick_visionary_t_mini/msg/detail/sick_t_mini__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace sick_visionary_t_mini
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_visionary_t_mini
cdr_serialize(
  const sick_visionary_t_mini::msg::SickTMini & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_visionary_t_mini
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  sick_visionary_t_mini::msg::SickTMini & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_visionary_t_mini
get_serialized_size(
  const sick_visionary_t_mini::msg::SickTMini & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_visionary_t_mini
max_serialized_size_SickTMini(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace sick_visionary_t_mini

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_visionary_t_mini
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sick_visionary_t_mini, msg, SickTMini)();

#ifdef __cplusplus
}
#endif

#endif  // SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
