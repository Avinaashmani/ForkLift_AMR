// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from forklift_interfaces:srv/ForkLiftDock.idl
// generated code does not contain a copyright notice

#ifndef FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__STRUCT_HPP_
#define FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__forklift_interfaces__srv__ForkLiftDock_Request __attribute__((deprecated))
#else
# define DEPRECATED__forklift_interfaces__srv__ForkLiftDock_Request __declspec(deprecated)
#endif

namespace forklift_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ForkLiftDock_Request_
{
  using Type = ForkLiftDock_Request_<ContainerAllocator>;

  explicit ForkLiftDock_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dock_request = false;
      this->undock_request = false;
    }
  }

  explicit ForkLiftDock_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dock_request = false;
      this->undock_request = false;
    }
  }

  // field types and members
  using _dock_request_type =
    bool;
  _dock_request_type dock_request;
  using _undock_request_type =
    bool;
  _undock_request_type undock_request;

  // setters for named parameter idiom
  Type & set__dock_request(
    const bool & _arg)
  {
    this->dock_request = _arg;
    return *this;
  }
  Type & set__undock_request(
    const bool & _arg)
  {
    this->undock_request = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__forklift_interfaces__srv__ForkLiftDock_Request
    std::shared_ptr<forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__forklift_interfaces__srv__ForkLiftDock_Request
    std::shared_ptr<forklift_interfaces::srv::ForkLiftDock_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForkLiftDock_Request_ & other) const
  {
    if (this->dock_request != other.dock_request) {
      return false;
    }
    if (this->undock_request != other.undock_request) {
      return false;
    }
    return true;
  }
  bool operator!=(const ForkLiftDock_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForkLiftDock_Request_

// alias to use template instance with default allocator
using ForkLiftDock_Request =
  forklift_interfaces::srv::ForkLiftDock_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace forklift_interfaces


#ifndef _WIN32
# define DEPRECATED__forklift_interfaces__srv__ForkLiftDock_Response __attribute__((deprecated))
#else
# define DEPRECATED__forklift_interfaces__srv__ForkLiftDock_Response __declspec(deprecated)
#endif

namespace forklift_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ForkLiftDock_Response_
{
  using Type = ForkLiftDock_Response_<ContainerAllocator>;

  explicit ForkLiftDock_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dock_response = false;
      this->undock_response = false;
    }
  }

  explicit ForkLiftDock_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dock_response = false;
      this->undock_response = false;
    }
  }

  // field types and members
  using _dock_response_type =
    bool;
  _dock_response_type dock_response;
  using _undock_response_type =
    bool;
  _undock_response_type undock_response;

  // setters for named parameter idiom
  Type & set__dock_response(
    const bool & _arg)
  {
    this->dock_response = _arg;
    return *this;
  }
  Type & set__undock_response(
    const bool & _arg)
  {
    this->undock_response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__forklift_interfaces__srv__ForkLiftDock_Response
    std::shared_ptr<forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__forklift_interfaces__srv__ForkLiftDock_Response
    std::shared_ptr<forklift_interfaces::srv::ForkLiftDock_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForkLiftDock_Response_ & other) const
  {
    if (this->dock_response != other.dock_response) {
      return false;
    }
    if (this->undock_response != other.undock_response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ForkLiftDock_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForkLiftDock_Response_

// alias to use template instance with default allocator
using ForkLiftDock_Response =
  forklift_interfaces::srv::ForkLiftDock_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace forklift_interfaces

namespace forklift_interfaces
{

namespace srv
{

struct ForkLiftDock
{
  using Request = forklift_interfaces::srv::ForkLiftDock_Request;
  using Response = forklift_interfaces::srv::ForkLiftDock_Response;
};

}  // namespace srv

}  // namespace forklift_interfaces

#endif  // FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__STRUCT_HPP_
