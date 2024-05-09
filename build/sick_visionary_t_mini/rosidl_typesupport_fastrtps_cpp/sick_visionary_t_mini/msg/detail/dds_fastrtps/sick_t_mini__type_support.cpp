// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from sick_visionary_t_mini:msg/SickTMini.idl
// generated code does not contain a copyright notice
#include "sick_visionary_t_mini/msg/detail/sick_t_mini__rosidl_typesupport_fastrtps_cpp.hpp"
#include "sick_visionary_t_mini/msg/detail/sick_t_mini__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Vector3 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Vector3 &);
size_t get_serialized_size(
  const geometry_msgs::msg::Vector3 &,
  size_t current_alignment);
size_t
max_serialized_size_Vector3(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Vector3 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Vector3 &);
size_t get_serialized_size(
  const geometry_msgs::msg::Vector3 &,
  size_t current_alignment);
size_t
max_serialized_size_Vector3(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Vector3 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Vector3 &);
size_t get_serialized_size(
  const geometry_msgs::msg::Vector3 &,
  size_t current_alignment);
size_t
max_serialized_size_Vector3(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs

namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Vector3 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Vector3 &);
size_t get_serialized_size(
  const geometry_msgs::msg::Vector3 &,
  size_t current_alignment);
size_t
max_serialized_size_Vector3(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Vector3 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Vector3 &);
size_t get_serialized_size(
  const geometry_msgs::msg::Vector3 &,
  size_t current_alignment);
size_t
max_serialized_size_Vector3(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Vector3 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Vector3 &);
size_t get_serialized_size(
  const geometry_msgs::msg::Vector3 &,
  size_t current_alignment);
size_t
max_serialized_size_Vector3(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs


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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header_dolly
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header_dolly,
    cdr);
  // Member: status_of_camera
  cdr << ros_message.status_of_camera;
  // Member: left_corners
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.left_corners,
    cdr);
  // Member: right_corners
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.right_corners,
    cdr);
  // Member: point
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.point,
    cdr);
  // Member: dolly_found
  cdr << (ros_message.dolly_found ? true : false);
  // Member: corners_distance
  cdr << ros_message.corners_distance;
  // Member: header_pallet_detection
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header_pallet_detection,
    cdr);
  // Member: message
  cdr << ros_message.message;
  // Member: left_pocket
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.left_pocket,
    cdr);
  // Member: right_pocket
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.right_pocket,
    cdr);
  // Member: center_point
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.center_point,
    cdr);
  // Member: pallet_found
  cdr << (ros_message.pallet_found ? true : false);
  // Member: pallet_angle
  cdr << ros_message.pallet_angle;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_visionary_t_mini
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  sick_visionary_t_mini::msg::SickTMini & ros_message)
{
  // Member: header_dolly
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header_dolly);

  // Member: status_of_camera
  cdr >> ros_message.status_of_camera;

  // Member: left_corners
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.left_corners);

  // Member: right_corners
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.right_corners);

  // Member: point
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.point);

  // Member: dolly_found
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.dolly_found = tmp ? true : false;
  }

  // Member: corners_distance
  cdr >> ros_message.corners_distance;

  // Member: header_pallet_detection
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header_pallet_detection);

  // Member: message
  cdr >> ros_message.message;

  // Member: left_pocket
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.left_pocket);

  // Member: right_pocket
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.right_pocket);

  // Member: center_point
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.center_point);

  // Member: pallet_found
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.pallet_found = tmp ? true : false;
  }

  // Member: pallet_angle
  cdr >> ros_message.pallet_angle;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_visionary_t_mini
get_serialized_size(
  const sick_visionary_t_mini::msg::SickTMini & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header_dolly

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header_dolly, current_alignment);
  // Member: status_of_camera
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.status_of_camera.size() + 1);
  // Member: left_corners

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.left_corners, current_alignment);
  // Member: right_corners

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.right_corners, current_alignment);
  // Member: point

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.point, current_alignment);
  // Member: dolly_found
  {
    size_t item_size = sizeof(ros_message.dolly_found);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: corners_distance
  {
    size_t item_size = sizeof(ros_message.corners_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: header_pallet_detection

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header_pallet_detection, current_alignment);
  // Member: message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.message.size() + 1);
  // Member: left_pocket

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.left_pocket, current_alignment);
  // Member: right_pocket

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.right_pocket, current_alignment);
  // Member: center_point

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.center_point, current_alignment);
  // Member: pallet_found
  {
    size_t item_size = sizeof(ros_message.pallet_found);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pallet_angle
  {
    size_t item_size = sizeof(ros_message.pallet_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_visionary_t_mini
max_serialized_size_SickTMini(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header_dolly
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: status_of_camera
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: left_corners
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Vector3(
        full_bounded, current_alignment);
    }
  }

  // Member: right_corners
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Vector3(
        full_bounded, current_alignment);
    }
  }

  // Member: point
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Vector3(
        full_bounded, current_alignment);
    }
  }

  // Member: dolly_found
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: corners_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: header_pallet_detection
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: message
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: left_pocket
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Vector3(
        full_bounded, current_alignment);
    }
  }

  // Member: right_pocket
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Vector3(
        full_bounded, current_alignment);
    }
  }

  // Member: center_point
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Vector3(
        full_bounded, current_alignment);
    }
  }

  // Member: pallet_found
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: pallet_angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _SickTMini__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const sick_visionary_t_mini::msg::SickTMini *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SickTMini__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<sick_visionary_t_mini::msg::SickTMini *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SickTMini__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const sick_visionary_t_mini::msg::SickTMini *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SickTMini__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_SickTMini(full_bounded, 0);
}

static message_type_support_callbacks_t _SickTMini__callbacks = {
  "sick_visionary_t_mini::msg",
  "SickTMini",
  _SickTMini__cdr_serialize,
  _SickTMini__cdr_deserialize,
  _SickTMini__get_serialized_size,
  _SickTMini__max_serialized_size
};

static rosidl_message_type_support_t _SickTMini__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SickTMini__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace sick_visionary_t_mini

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_sick_visionary_t_mini
const rosidl_message_type_support_t *
get_message_type_support_handle<sick_visionary_t_mini::msg::SickTMini>()
{
  return &sick_visionary_t_mini::msg::typesupport_fastrtps_cpp::_SickTMini__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sick_visionary_t_mini, msg, SickTMini)() {
  return &sick_visionary_t_mini::msg::typesupport_fastrtps_cpp::_SickTMini__handle;
}

#ifdef __cplusplus
}
#endif
