// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from forklift_interfaces:srv/ForkLiftDock.idl
// generated code does not contain a copyright notice

#ifndef FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__TRAITS_HPP_
#define FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__TRAITS_HPP_

#include "forklift_interfaces/srv/detail/fork_lift_dock__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const forklift_interfaces::srv::ForkLiftDock_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: dock_request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dock_request: ";
    value_to_yaml(msg.dock_request, out);
    out << "\n";
  }

  // member: undock_request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "undock_request: ";
    value_to_yaml(msg.undock_request, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const forklift_interfaces::srv::ForkLiftDock_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<forklift_interfaces::srv::ForkLiftDock_Request>()
{
  return "forklift_interfaces::srv::ForkLiftDock_Request";
}

template<>
inline const char * name<forklift_interfaces::srv::ForkLiftDock_Request>()
{
  return "forklift_interfaces/srv/ForkLiftDock_Request";
}

template<>
struct has_fixed_size<forklift_interfaces::srv::ForkLiftDock_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<forklift_interfaces::srv::ForkLiftDock_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<forklift_interfaces::srv::ForkLiftDock_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const forklift_interfaces::srv::ForkLiftDock_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: dock_response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dock_response: ";
    value_to_yaml(msg.dock_response, out);
    out << "\n";
  }

  // member: undock_response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "undock_response: ";
    value_to_yaml(msg.undock_response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const forklift_interfaces::srv::ForkLiftDock_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<forklift_interfaces::srv::ForkLiftDock_Response>()
{
  return "forklift_interfaces::srv::ForkLiftDock_Response";
}

template<>
inline const char * name<forklift_interfaces::srv::ForkLiftDock_Response>()
{
  return "forklift_interfaces/srv/ForkLiftDock_Response";
}

template<>
struct has_fixed_size<forklift_interfaces::srv::ForkLiftDock_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<forklift_interfaces::srv::ForkLiftDock_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<forklift_interfaces::srv::ForkLiftDock_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<forklift_interfaces::srv::ForkLiftDock>()
{
  return "forklift_interfaces::srv::ForkLiftDock";
}

template<>
inline const char * name<forklift_interfaces::srv::ForkLiftDock>()
{
  return "forklift_interfaces/srv/ForkLiftDock";
}

template<>
struct has_fixed_size<forklift_interfaces::srv::ForkLiftDock>
  : std::integral_constant<
    bool,
    has_fixed_size<forklift_interfaces::srv::ForkLiftDock_Request>::value &&
    has_fixed_size<forklift_interfaces::srv::ForkLiftDock_Response>::value
  >
{
};

template<>
struct has_bounded_size<forklift_interfaces::srv::ForkLiftDock>
  : std::integral_constant<
    bool,
    has_bounded_size<forklift_interfaces::srv::ForkLiftDock_Request>::value &&
    has_bounded_size<forklift_interfaces::srv::ForkLiftDock_Response>::value
  >
{
};

template<>
struct is_service<forklift_interfaces::srv::ForkLiftDock>
  : std::true_type
{
};

template<>
struct is_service_request<forklift_interfaces::srv::ForkLiftDock_Request>
  : std::true_type
{
};

template<>
struct is_service_response<forklift_interfaces::srv::ForkLiftDock_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__TRAITS_HPP_
