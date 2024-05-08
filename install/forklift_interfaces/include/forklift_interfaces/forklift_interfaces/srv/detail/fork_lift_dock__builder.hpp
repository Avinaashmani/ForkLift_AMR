// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from forklift_interfaces:srv/ForkLiftDock.idl
// generated code does not contain a copyright notice

#ifndef FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__BUILDER_HPP_
#define FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "forklift_interfaces/srv/detail/fork_lift_dock__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace forklift_interfaces
{

namespace srv
{

namespace builder
{

class Init_ForkLiftDock_Request_undock_request
{
public:
  explicit Init_ForkLiftDock_Request_undock_request(::forklift_interfaces::srv::ForkLiftDock_Request & msg)
  : msg_(msg)
  {}
  ::forklift_interfaces::srv::ForkLiftDock_Request undock_request(::forklift_interfaces::srv::ForkLiftDock_Request::_undock_request_type arg)
  {
    msg_.undock_request = std::move(arg);
    return std::move(msg_);
  }

private:
  ::forklift_interfaces::srv::ForkLiftDock_Request msg_;
};

class Init_ForkLiftDock_Request_dock_request
{
public:
  Init_ForkLiftDock_Request_dock_request()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ForkLiftDock_Request_undock_request dock_request(::forklift_interfaces::srv::ForkLiftDock_Request::_dock_request_type arg)
  {
    msg_.dock_request = std::move(arg);
    return Init_ForkLiftDock_Request_undock_request(msg_);
  }

private:
  ::forklift_interfaces::srv::ForkLiftDock_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::forklift_interfaces::srv::ForkLiftDock_Request>()
{
  return forklift_interfaces::srv::builder::Init_ForkLiftDock_Request_dock_request();
}

}  // namespace forklift_interfaces


namespace forklift_interfaces
{

namespace srv
{

namespace builder
{

class Init_ForkLiftDock_Response_undock_response
{
public:
  explicit Init_ForkLiftDock_Response_undock_response(::forklift_interfaces::srv::ForkLiftDock_Response & msg)
  : msg_(msg)
  {}
  ::forklift_interfaces::srv::ForkLiftDock_Response undock_response(::forklift_interfaces::srv::ForkLiftDock_Response::_undock_response_type arg)
  {
    msg_.undock_response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::forklift_interfaces::srv::ForkLiftDock_Response msg_;
};

class Init_ForkLiftDock_Response_dock_response
{
public:
  Init_ForkLiftDock_Response_dock_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ForkLiftDock_Response_undock_response dock_response(::forklift_interfaces::srv::ForkLiftDock_Response::_dock_response_type arg)
  {
    msg_.dock_response = std::move(arg);
    return Init_ForkLiftDock_Response_undock_response(msg_);
  }

private:
  ::forklift_interfaces::srv::ForkLiftDock_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::forklift_interfaces::srv::ForkLiftDock_Response>()
{
  return forklift_interfaces::srv::builder::Init_ForkLiftDock_Response_dock_response();
}

}  // namespace forklift_interfaces

#endif  // FORKLIFT_INTERFACES__SRV__DETAIL__FORK_LIFT_DOCK__BUILDER_HPP_
