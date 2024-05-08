// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_visionary_t_mini:msg/SickTMini.idl
// generated code does not contain a copyright notice

#ifndef SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__STRUCT_HPP_
#define SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header_dolly'
// Member 'header_pallet_detection'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'left_corners'
// Member 'right_corners'
// Member 'point'
// Member 'left_pocket'
// Member 'right_pocket'
// Member 'center_point'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sick_visionary_t_mini__msg__SickTMini __attribute__((deprecated))
#else
# define DEPRECATED__sick_visionary_t_mini__msg__SickTMini __declspec(deprecated)
#endif

namespace sick_visionary_t_mini
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SickTMini_
{
  using Type = SickTMini_<ContainerAllocator>;

  explicit SickTMini_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header_dolly(_init),
    left_corners(_init),
    right_corners(_init),
    point(_init),
    header_pallet_detection(_init),
    left_pocket(_init),
    right_pocket(_init),
    center_point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status_of_camera = "";
      this->dolly_found = false;
      this->corners_distance = 0.0;
      this->message = "";
      this->pallet_found = false;
      this->pallet_angle = 0.0;
    }
  }

  explicit SickTMini_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header_dolly(_alloc, _init),
    status_of_camera(_alloc),
    left_corners(_alloc, _init),
    right_corners(_alloc, _init),
    point(_alloc, _init),
    header_pallet_detection(_alloc, _init),
    message(_alloc),
    left_pocket(_alloc, _init),
    right_pocket(_alloc, _init),
    center_point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status_of_camera = "";
      this->dolly_found = false;
      this->corners_distance = 0.0;
      this->message = "";
      this->pallet_found = false;
      this->pallet_angle = 0.0;
    }
  }

  // field types and members
  using _header_dolly_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_dolly_type header_dolly;
  using _status_of_camera_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_of_camera_type status_of_camera;
  using _left_corners_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _left_corners_type left_corners;
  using _right_corners_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _right_corners_type right_corners;
  using _point_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _point_type point;
  using _dolly_found_type =
    bool;
  _dolly_found_type dolly_found;
  using _corners_distance_type =
    double;
  _corners_distance_type corners_distance;
  using _header_pallet_detection_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_pallet_detection_type header_pallet_detection;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _left_pocket_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _left_pocket_type left_pocket;
  using _right_pocket_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _right_pocket_type right_pocket;
  using _center_point_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _center_point_type center_point;
  using _pallet_found_type =
    bool;
  _pallet_found_type pallet_found;
  using _pallet_angle_type =
    double;
  _pallet_angle_type pallet_angle;

  // setters for named parameter idiom
  Type & set__header_dolly(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header_dolly = _arg;
    return *this;
  }
  Type & set__status_of_camera(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status_of_camera = _arg;
    return *this;
  }
  Type & set__left_corners(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->left_corners = _arg;
    return *this;
  }
  Type & set__right_corners(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->right_corners = _arg;
    return *this;
  }
  Type & set__point(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->point = _arg;
    return *this;
  }
  Type & set__dolly_found(
    const bool & _arg)
  {
    this->dolly_found = _arg;
    return *this;
  }
  Type & set__corners_distance(
    const double & _arg)
  {
    this->corners_distance = _arg;
    return *this;
  }
  Type & set__header_pallet_detection(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header_pallet_detection = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__left_pocket(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->left_pocket = _arg;
    return *this;
  }
  Type & set__right_pocket(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->right_pocket = _arg;
    return *this;
  }
  Type & set__center_point(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->center_point = _arg;
    return *this;
  }
  Type & set__pallet_found(
    const bool & _arg)
  {
    this->pallet_found = _arg;
    return *this;
  }
  Type & set__pallet_angle(
    const double & _arg)
  {
    this->pallet_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_visionary_t_mini__msg__SickTMini
    std::shared_ptr<sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_visionary_t_mini__msg__SickTMini
    std::shared_ptr<sick_visionary_t_mini::msg::SickTMini_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SickTMini_ & other) const
  {
    if (this->header_dolly != other.header_dolly) {
      return false;
    }
    if (this->status_of_camera != other.status_of_camera) {
      return false;
    }
    if (this->left_corners != other.left_corners) {
      return false;
    }
    if (this->right_corners != other.right_corners) {
      return false;
    }
    if (this->point != other.point) {
      return false;
    }
    if (this->dolly_found != other.dolly_found) {
      return false;
    }
    if (this->corners_distance != other.corners_distance) {
      return false;
    }
    if (this->header_pallet_detection != other.header_pallet_detection) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->left_pocket != other.left_pocket) {
      return false;
    }
    if (this->right_pocket != other.right_pocket) {
      return false;
    }
    if (this->center_point != other.center_point) {
      return false;
    }
    if (this->pallet_found != other.pallet_found) {
      return false;
    }
    if (this->pallet_angle != other.pallet_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const SickTMini_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SickTMini_

// alias to use template instance with default allocator
using SickTMini =
  sick_visionary_t_mini::msg::SickTMini_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_visionary_t_mini

#endif  // SICK_VISIONARY_T_MINI__MSG__DETAIL__SICK_T_MINI__STRUCT_HPP_
