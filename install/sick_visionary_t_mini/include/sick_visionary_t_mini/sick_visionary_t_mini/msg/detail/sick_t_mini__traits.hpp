// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_visionary_t_mini:msg/SickTMini.idl
// generated code does not contain a copyright notice

#ifndef SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__TRAITS_HPP_
#define SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_visionary_t_mini/msg/detail/sick_t_mini__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header_dolly'
// Member 'header_pallet_detection'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'left_corners'
// Member 'right_corners'
// Member 'point'
// Member 'left_pocket'
// Member 'right_pocket'
// Member 'center_point'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace sick_visionary_t_mini
{

namespace msg
{

inline void to_flow_style_yaml(
  const SickTMini & msg,
  std::ostream & out)
{
  out << "{";
  // member: header_dolly
  {
    out << "header_dolly: ";
    to_flow_style_yaml(msg.header_dolly, out);
    out << ", ";
  }

  // member: status_of_camera
  {
    out << "status_of_camera: ";
    rosidl_generator_traits::value_to_yaml(msg.status_of_camera, out);
    out << ", ";
  }

  // member: left_corners
  {
    out << "left_corners: ";
    to_flow_style_yaml(msg.left_corners, out);
    out << ", ";
  }

  // member: right_corners
  {
    out << "right_corners: ";
    to_flow_style_yaml(msg.right_corners, out);
    out << ", ";
  }

  // member: point
  {
    out << "point: ";
    to_flow_style_yaml(msg.point, out);
    out << ", ";
  }

  // member: dolly_found
  {
    out << "dolly_found: ";
    rosidl_generator_traits::value_to_yaml(msg.dolly_found, out);
    out << ", ";
  }

  // member: corners_distance
  {
    out << "corners_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.corners_distance, out);
    out << ", ";
  }

  // member: header_pallet_detection
  {
    out << "header_pallet_detection: ";
    to_flow_style_yaml(msg.header_pallet_detection, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: left_pocket
  {
    out << "left_pocket: ";
    to_flow_style_yaml(msg.left_pocket, out);
    out << ", ";
  }

  // member: right_pocket
  {
    out << "right_pocket: ";
    to_flow_style_yaml(msg.right_pocket, out);
    out << ", ";
  }

  // member: center_point
  {
    out << "center_point: ";
    to_flow_style_yaml(msg.center_point, out);
    out << ", ";
  }

  // member: pallet_found
  {
    out << "pallet_found: ";
    rosidl_generator_traits::value_to_yaml(msg.pallet_found, out);
    out << ", ";
  }

  // member: pallet_angle
  {
    out << "pallet_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.pallet_angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SickTMini & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header_dolly
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header_dolly:\n";
    to_block_style_yaml(msg.header_dolly, out, indentation + 2);
  }

  // member: status_of_camera
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_of_camera: ";
    rosidl_generator_traits::value_to_yaml(msg.status_of_camera, out);
    out << "\n";
  }

  // member: left_corners
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_corners:\n";
    to_block_style_yaml(msg.left_corners, out, indentation + 2);
  }

  // member: right_corners
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_corners:\n";
    to_block_style_yaml(msg.right_corners, out, indentation + 2);
  }

  // member: point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "point:\n";
    to_block_style_yaml(msg.point, out, indentation + 2);
  }

  // member: dolly_found
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dolly_found: ";
    rosidl_generator_traits::value_to_yaml(msg.dolly_found, out);
    out << "\n";
  }

  // member: corners_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "corners_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.corners_distance, out);
    out << "\n";
  }

  // member: header_pallet_detection
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header_pallet_detection:\n";
    to_block_style_yaml(msg.header_pallet_detection, out, indentation + 2);
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: left_pocket
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_pocket:\n";
    to_block_style_yaml(msg.left_pocket, out, indentation + 2);
  }

  // member: right_pocket
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_pocket:\n";
    to_block_style_yaml(msg.right_pocket, out, indentation + 2);
  }

  // member: center_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_point:\n";
    to_block_style_yaml(msg.center_point, out, indentation + 2);
  }

  // member: pallet_found
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pallet_found: ";
    rosidl_generator_traits::value_to_yaml(msg.pallet_found, out);
    out << "\n";
  }

  // member: pallet_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pallet_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.pallet_angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SickTMini & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace sick_visionary_t_mini

namespace rosidl_generator_traits
{

[[deprecated("use sick_visionary_t_mini::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sick_visionary_t_mini::msg::SickTMini & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_visionary_t_mini::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_visionary_t_mini::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_visionary_t_mini::msg::SickTMini & msg)
{
  return sick_visionary_t_mini::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_visionary_t_mini::msg::SickTMini>()
{
  return "sick_visionary_t_mini::msg::SickTMini";
}

template<>
inline const char * name<sick_visionary_t_mini::msg::SickTMini>()
{
  return "sick_visionary_t_mini/msg/SickTMini";
}

template<>
struct has_fixed_size<sick_visionary_t_mini::msg::SickTMini>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sick_visionary_t_mini::msg::SickTMini>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sick_visionary_t_mini::msg::SickTMini>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__TRAITS_HPP_
