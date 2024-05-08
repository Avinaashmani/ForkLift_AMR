// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from forklift_interfaces:srv/ForkLiftDock.idl
// generated code does not contain a copyright notice
#include "forklift_interfaces/srv/detail/fork_lift_dock__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
forklift_interfaces__srv__ForkLiftDock_Request__init(forklift_interfaces__srv__ForkLiftDock_Request * msg)
{
  if (!msg) {
    return false;
  }
  // dock_request
  // undock_request
  return true;
}

void
forklift_interfaces__srv__ForkLiftDock_Request__fini(forklift_interfaces__srv__ForkLiftDock_Request * msg)
{
  if (!msg) {
    return;
  }
  // dock_request
  // undock_request
}

bool
forklift_interfaces__srv__ForkLiftDock_Request__are_equal(const forklift_interfaces__srv__ForkLiftDock_Request * lhs, const forklift_interfaces__srv__ForkLiftDock_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // dock_request
  if (lhs->dock_request != rhs->dock_request) {
    return false;
  }
  // undock_request
  if (lhs->undock_request != rhs->undock_request) {
    return false;
  }
  return true;
}

bool
forklift_interfaces__srv__ForkLiftDock_Request__copy(
  const forklift_interfaces__srv__ForkLiftDock_Request * input,
  forklift_interfaces__srv__ForkLiftDock_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // dock_request
  output->dock_request = input->dock_request;
  // undock_request
  output->undock_request = input->undock_request;
  return true;
}

forklift_interfaces__srv__ForkLiftDock_Request *
forklift_interfaces__srv__ForkLiftDock_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  forklift_interfaces__srv__ForkLiftDock_Request * msg = (forklift_interfaces__srv__ForkLiftDock_Request *)allocator.allocate(sizeof(forklift_interfaces__srv__ForkLiftDock_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(forklift_interfaces__srv__ForkLiftDock_Request));
  bool success = forklift_interfaces__srv__ForkLiftDock_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
forklift_interfaces__srv__ForkLiftDock_Request__destroy(forklift_interfaces__srv__ForkLiftDock_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    forklift_interfaces__srv__ForkLiftDock_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
forklift_interfaces__srv__ForkLiftDock_Request__Sequence__init(forklift_interfaces__srv__ForkLiftDock_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  forklift_interfaces__srv__ForkLiftDock_Request * data = NULL;

  if (size) {
    data = (forklift_interfaces__srv__ForkLiftDock_Request *)allocator.zero_allocate(size, sizeof(forklift_interfaces__srv__ForkLiftDock_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = forklift_interfaces__srv__ForkLiftDock_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        forklift_interfaces__srv__ForkLiftDock_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
forklift_interfaces__srv__ForkLiftDock_Request__Sequence__fini(forklift_interfaces__srv__ForkLiftDock_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      forklift_interfaces__srv__ForkLiftDock_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

forklift_interfaces__srv__ForkLiftDock_Request__Sequence *
forklift_interfaces__srv__ForkLiftDock_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  forklift_interfaces__srv__ForkLiftDock_Request__Sequence * array = (forklift_interfaces__srv__ForkLiftDock_Request__Sequence *)allocator.allocate(sizeof(forklift_interfaces__srv__ForkLiftDock_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = forklift_interfaces__srv__ForkLiftDock_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
forklift_interfaces__srv__ForkLiftDock_Request__Sequence__destroy(forklift_interfaces__srv__ForkLiftDock_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    forklift_interfaces__srv__ForkLiftDock_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
forklift_interfaces__srv__ForkLiftDock_Request__Sequence__are_equal(const forklift_interfaces__srv__ForkLiftDock_Request__Sequence * lhs, const forklift_interfaces__srv__ForkLiftDock_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!forklift_interfaces__srv__ForkLiftDock_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
forklift_interfaces__srv__ForkLiftDock_Request__Sequence__copy(
  const forklift_interfaces__srv__ForkLiftDock_Request__Sequence * input,
  forklift_interfaces__srv__ForkLiftDock_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(forklift_interfaces__srv__ForkLiftDock_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    forklift_interfaces__srv__ForkLiftDock_Request * data =
      (forklift_interfaces__srv__ForkLiftDock_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!forklift_interfaces__srv__ForkLiftDock_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          forklift_interfaces__srv__ForkLiftDock_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!forklift_interfaces__srv__ForkLiftDock_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
forklift_interfaces__srv__ForkLiftDock_Response__init(forklift_interfaces__srv__ForkLiftDock_Response * msg)
{
  if (!msg) {
    return false;
  }
  // dock_response
  // undock_response
  return true;
}

void
forklift_interfaces__srv__ForkLiftDock_Response__fini(forklift_interfaces__srv__ForkLiftDock_Response * msg)
{
  if (!msg) {
    return;
  }
  // dock_response
  // undock_response
}

bool
forklift_interfaces__srv__ForkLiftDock_Response__are_equal(const forklift_interfaces__srv__ForkLiftDock_Response * lhs, const forklift_interfaces__srv__ForkLiftDock_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // dock_response
  if (lhs->dock_response != rhs->dock_response) {
    return false;
  }
  // undock_response
  if (lhs->undock_response != rhs->undock_response) {
    return false;
  }
  return true;
}

bool
forklift_interfaces__srv__ForkLiftDock_Response__copy(
  const forklift_interfaces__srv__ForkLiftDock_Response * input,
  forklift_interfaces__srv__ForkLiftDock_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // dock_response
  output->dock_response = input->dock_response;
  // undock_response
  output->undock_response = input->undock_response;
  return true;
}

forklift_interfaces__srv__ForkLiftDock_Response *
forklift_interfaces__srv__ForkLiftDock_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  forklift_interfaces__srv__ForkLiftDock_Response * msg = (forklift_interfaces__srv__ForkLiftDock_Response *)allocator.allocate(sizeof(forklift_interfaces__srv__ForkLiftDock_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(forklift_interfaces__srv__ForkLiftDock_Response));
  bool success = forklift_interfaces__srv__ForkLiftDock_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
forklift_interfaces__srv__ForkLiftDock_Response__destroy(forklift_interfaces__srv__ForkLiftDock_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    forklift_interfaces__srv__ForkLiftDock_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
forklift_interfaces__srv__ForkLiftDock_Response__Sequence__init(forklift_interfaces__srv__ForkLiftDock_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  forklift_interfaces__srv__ForkLiftDock_Response * data = NULL;

  if (size) {
    data = (forklift_interfaces__srv__ForkLiftDock_Response *)allocator.zero_allocate(size, sizeof(forklift_interfaces__srv__ForkLiftDock_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = forklift_interfaces__srv__ForkLiftDock_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        forklift_interfaces__srv__ForkLiftDock_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
forklift_interfaces__srv__ForkLiftDock_Response__Sequence__fini(forklift_interfaces__srv__ForkLiftDock_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      forklift_interfaces__srv__ForkLiftDock_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

forklift_interfaces__srv__ForkLiftDock_Response__Sequence *
forklift_interfaces__srv__ForkLiftDock_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  forklift_interfaces__srv__ForkLiftDock_Response__Sequence * array = (forklift_interfaces__srv__ForkLiftDock_Response__Sequence *)allocator.allocate(sizeof(forklift_interfaces__srv__ForkLiftDock_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = forklift_interfaces__srv__ForkLiftDock_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
forklift_interfaces__srv__ForkLiftDock_Response__Sequence__destroy(forklift_interfaces__srv__ForkLiftDock_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    forklift_interfaces__srv__ForkLiftDock_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
forklift_interfaces__srv__ForkLiftDock_Response__Sequence__are_equal(const forklift_interfaces__srv__ForkLiftDock_Response__Sequence * lhs, const forklift_interfaces__srv__ForkLiftDock_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!forklift_interfaces__srv__ForkLiftDock_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
forklift_interfaces__srv__ForkLiftDock_Response__Sequence__copy(
  const forklift_interfaces__srv__ForkLiftDock_Response__Sequence * input,
  forklift_interfaces__srv__ForkLiftDock_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(forklift_interfaces__srv__ForkLiftDock_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    forklift_interfaces__srv__ForkLiftDock_Response * data =
      (forklift_interfaces__srv__ForkLiftDock_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!forklift_interfaces__srv__ForkLiftDock_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          forklift_interfaces__srv__ForkLiftDock_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!forklift_interfaces__srv__ForkLiftDock_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
