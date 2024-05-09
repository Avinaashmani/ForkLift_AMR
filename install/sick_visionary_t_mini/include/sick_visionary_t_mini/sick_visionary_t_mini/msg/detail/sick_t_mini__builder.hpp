// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_visionary_t_mini:msg/SickTMini.idl
// generated code does not contain a copyright notice

#ifndef SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__BUILDER_HPP_
#define SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_visionary_t_mini/msg/detail/sick_t_mini__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_visionary_t_mini
{

namespace msg
{

namespace builder
{

class Init_SickTMini_pallet_angle
{
public:
  explicit Init_SickTMini_pallet_angle(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  ::sick_visionary_t_mini::msg::SickTMini pallet_angle(::sick_visionary_t_mini::msg::SickTMini::_pallet_angle_type arg)
  {
    msg_.pallet_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_pallet_found
{
public:
  explicit Init_SickTMini_pallet_found(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_pallet_angle pallet_found(::sick_visionary_t_mini::msg::SickTMini::_pallet_found_type arg)
  {
    msg_.pallet_found = std::move(arg);
    return Init_SickTMini_pallet_angle(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_center_point
{
public:
  explicit Init_SickTMini_center_point(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_pallet_found center_point(::sick_visionary_t_mini::msg::SickTMini::_center_point_type arg)
  {
    msg_.center_point = std::move(arg);
    return Init_SickTMini_pallet_found(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_right_pocket
{
public:
  explicit Init_SickTMini_right_pocket(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_center_point right_pocket(::sick_visionary_t_mini::msg::SickTMini::_right_pocket_type arg)
  {
    msg_.right_pocket = std::move(arg);
    return Init_SickTMini_center_point(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_left_pocket
{
public:
  explicit Init_SickTMini_left_pocket(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_right_pocket left_pocket(::sick_visionary_t_mini::msg::SickTMini::_left_pocket_type arg)
  {
    msg_.left_pocket = std::move(arg);
    return Init_SickTMini_right_pocket(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_message
{
public:
  explicit Init_SickTMini_message(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_left_pocket message(::sick_visionary_t_mini::msg::SickTMini::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_SickTMini_left_pocket(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_header_pallet_detection
{
public:
  explicit Init_SickTMini_header_pallet_detection(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_message header_pallet_detection(::sick_visionary_t_mini::msg::SickTMini::_header_pallet_detection_type arg)
  {
    msg_.header_pallet_detection = std::move(arg);
    return Init_SickTMini_message(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_corners_distance
{
public:
  explicit Init_SickTMini_corners_distance(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_header_pallet_detection corners_distance(::sick_visionary_t_mini::msg::SickTMini::_corners_distance_type arg)
  {
    msg_.corners_distance = std::move(arg);
    return Init_SickTMini_header_pallet_detection(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_dolly_found
{
public:
  explicit Init_SickTMini_dolly_found(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_corners_distance dolly_found(::sick_visionary_t_mini::msg::SickTMini::_dolly_found_type arg)
  {
    msg_.dolly_found = std::move(arg);
    return Init_SickTMini_corners_distance(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_point
{
public:
  explicit Init_SickTMini_point(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_dolly_found point(::sick_visionary_t_mini::msg::SickTMini::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_SickTMini_dolly_found(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_right_corners
{
public:
  explicit Init_SickTMini_right_corners(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_point right_corners(::sick_visionary_t_mini::msg::SickTMini::_right_corners_type arg)
  {
    msg_.right_corners = std::move(arg);
    return Init_SickTMini_point(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_left_corners
{
public:
  explicit Init_SickTMini_left_corners(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_right_corners left_corners(::sick_visionary_t_mini::msg::SickTMini::_left_corners_type arg)
  {
    msg_.left_corners = std::move(arg);
    return Init_SickTMini_right_corners(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_status_of_camera
{
public:
  explicit Init_SickTMini_status_of_camera(::sick_visionary_t_mini::msg::SickTMini & msg)
  : msg_(msg)
  {}
  Init_SickTMini_left_corners status_of_camera(::sick_visionary_t_mini::msg::SickTMini::_status_of_camera_type arg)
  {
    msg_.status_of_camera = std::move(arg);
    return Init_SickTMini_left_corners(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

class Init_SickTMini_header_dolly
{
public:
  Init_SickTMini_header_dolly()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SickTMini_status_of_camera header_dolly(::sick_visionary_t_mini::msg::SickTMini::_header_dolly_type arg)
  {
    msg_.header_dolly = std::move(arg);
    return Init_SickTMini_status_of_camera(msg_);
  }

private:
  ::sick_visionary_t_mini::msg::SickTMini msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_visionary_t_mini::msg::SickTMini>()
{
  return sick_visionary_t_mini::msg::builder::Init_SickTMini_header_dolly();
}

}  // namespace sick_visionary_t_mini

#endif  // SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__BUILDER_HPP_
