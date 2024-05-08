// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_visionary_t_mini:msg/SickTMini.idl
// generated code does not contain a copyright notice

#ifndef SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__TRAITS_HPP_
#define SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__TRAITS_HPP_

#include "sick_visionary_t_mini/msg/detail/sick_t_mini__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

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

namespace rosidl_generator_traits
{

inline void to_yaml(
  const sick_visionary_t_mini::msg::SickTMini & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header_dolly
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header_dolly:\n";
    to_yaml(msg.header_dolly, out, indentation + 2);
  }

  // member: status_of_camera
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_of_camera: ";
    value_to_yaml(msg.status_of_camera, out);
    out << "\n";
  }

  // member: left_corners
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_corners:\n";
    to_yaml(msg.left_corners, out, indentation + 2);
  }

  // member: right_corners
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_corners:\n";
    to_yaml(msg.right_corners, out, indentation + 2);
  }

  // member: point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "point:\n";
    to_yaml(msg.point, out, indentation + 2);
  }

  // member: dolly_found
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dolly_found: ";
    value_to_yaml(msg.dolly_found, out);
    out << "\n";
  }

  // member: corners_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "corners_distance: ";
    value_to_yaml(msg.corners_distance, out);
    out << "\n";
  }

  // member: header_pallet_detection
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header_pallet_detection:\n";
    to_yaml(msg.header_pallet_detection, out, indentation + 2);
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: left_pocket
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_pocket:\n";
    to_yaml(msg.left_pocket, out, indentation + 2);
  }

  // member: right_pocket
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_pocket:\n";
    to_yaml(msg.right_pocket, out, indentation + 2);
  }

  // member: center_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_point:\n";
    to_yaml(msg.center_point, out, indentation + 2);
  }

  // member: pallet_found
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pallet_found: ";
    value_to_yaml(msg.pallet_found, out);
    out << "\n";
  }

  // member: pallet_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pallet_angle: ";
    value_to_yaml(msg.pallet_angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const sick_visionary_t_mini::msg::SickTMini & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
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
