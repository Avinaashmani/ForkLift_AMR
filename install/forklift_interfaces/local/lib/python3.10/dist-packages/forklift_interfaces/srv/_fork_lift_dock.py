# generated from rosidl_generator_py/resource/_idl.py.em
# with input from forklift_interfaces:srv/ForkLiftDock.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ForkLiftDock_Request(type):
    """Metaclass of message 'ForkLiftDock_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('forklift_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'forklift_interfaces.srv.ForkLiftDock_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__fork_lift_dock__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__fork_lift_dock__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__fork_lift_dock__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__fork_lift_dock__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__fork_lift_dock__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ForkLiftDock_Request(metaclass=Metaclass_ForkLiftDock_Request):
    """Message class 'ForkLiftDock_Request'."""

    __slots__ = [
        '_dock_request',
        '_undock_request',
    ]

    _fields_and_field_types = {
        'dock_request': 'boolean',
        'undock_request': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.dock_request = kwargs.get('dock_request', bool())
        self.undock_request = kwargs.get('undock_request', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.dock_request != other.dock_request:
            return False
        if self.undock_request != other.undock_request:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def dock_request(self):
        """Message field 'dock_request'."""
        return self._dock_request

    @dock_request.setter
    def dock_request(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'dock_request' field must be of type 'bool'"
        self._dock_request = value

    @builtins.property
    def undock_request(self):
        """Message field 'undock_request'."""
        return self._undock_request

    @undock_request.setter
    def undock_request(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'undock_request' field must be of type 'bool'"
        self._undock_request = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ForkLiftDock_Response(type):
    """Metaclass of message 'ForkLiftDock_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('forklift_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'forklift_interfaces.srv.ForkLiftDock_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__fork_lift_dock__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__fork_lift_dock__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__fork_lift_dock__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__fork_lift_dock__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__fork_lift_dock__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ForkLiftDock_Response(metaclass=Metaclass_ForkLiftDock_Response):
    """Message class 'ForkLiftDock_Response'."""

    __slots__ = [
        '_dock_response',
        '_undock_response',
    ]

    _fields_and_field_types = {
        'dock_response': 'boolean',
        'undock_response': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.dock_response = kwargs.get('dock_response', bool())
        self.undock_response = kwargs.get('undock_response', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.dock_response != other.dock_response:
            return False
        if self.undock_response != other.undock_response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def dock_response(self):
        """Message field 'dock_response'."""
        return self._dock_response

    @dock_response.setter
    def dock_response(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'dock_response' field must be of type 'bool'"
        self._dock_response = value

    @builtins.property
    def undock_response(self):
        """Message field 'undock_response'."""
        return self._undock_response

    @undock_response.setter
    def undock_response(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'undock_response' field must be of type 'bool'"
        self._undock_response = value


class Metaclass_ForkLiftDock(type):
    """Metaclass of service 'ForkLiftDock'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('forklift_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'forklift_interfaces.srv.ForkLiftDock')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__fork_lift_dock

            from forklift_interfaces.srv import _fork_lift_dock
            if _fork_lift_dock.Metaclass_ForkLiftDock_Request._TYPE_SUPPORT is None:
                _fork_lift_dock.Metaclass_ForkLiftDock_Request.__import_type_support__()
            if _fork_lift_dock.Metaclass_ForkLiftDock_Response._TYPE_SUPPORT is None:
                _fork_lift_dock.Metaclass_ForkLiftDock_Response.__import_type_support__()


class ForkLiftDock(metaclass=Metaclass_ForkLiftDock):
    from forklift_interfaces.srv._fork_lift_dock import ForkLiftDock_Request as Request
    from forklift_interfaces.srv._fork_lift_dock import ForkLiftDock_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
