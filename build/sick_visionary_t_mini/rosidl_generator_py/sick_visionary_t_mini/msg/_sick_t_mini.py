# generated from rosidl_generator_py/resource/_idl.py.em
# with input from sick_visionary_t_mini:msg/SickTMini.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SickTMini(type):
    """Metaclass of message 'SickTMini'."""

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
            module = import_type_support('sick_visionary_t_mini')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sick_visionary_t_mini.msg.SickTMini')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sick_t_mini
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sick_t_mini
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sick_t_mini
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sick_t_mini
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sick_t_mini

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SickTMini(metaclass=Metaclass_SickTMini):
    """Message class 'SickTMini'."""

    __slots__ = [
        '_header_dolly',
        '_status_of_camera',
        '_left_corners',
        '_right_corners',
        '_point',
        '_dolly_found',
        '_corners_distance',
        '_header_pallet_detection',
        '_message',
        '_left_pocket',
        '_right_pocket',
        '_center_point',
        '_pallet_found',
        '_pallet_angle',
    ]

    _fields_and_field_types = {
        'header_dolly': 'std_msgs/Header',
        'status_of_camera': 'string',
        'left_corners': 'geometry_msgs/Vector3',
        'right_corners': 'geometry_msgs/Vector3',
        'point': 'geometry_msgs/Vector3',
        'dolly_found': 'boolean',
        'corners_distance': 'double',
        'header_pallet_detection': 'std_msgs/Header',
        'message': 'string',
        'left_pocket': 'geometry_msgs/Vector3',
        'right_pocket': 'geometry_msgs/Vector3',
        'center_point': 'geometry_msgs/Vector3',
        'pallet_found': 'boolean',
        'pallet_angle': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header_dolly = kwargs.get('header_dolly', Header())
        self.status_of_camera = kwargs.get('status_of_camera', str())
        from geometry_msgs.msg import Vector3
        self.left_corners = kwargs.get('left_corners', Vector3())
        from geometry_msgs.msg import Vector3
        self.right_corners = kwargs.get('right_corners', Vector3())
        from geometry_msgs.msg import Vector3
        self.point = kwargs.get('point', Vector3())
        self.dolly_found = kwargs.get('dolly_found', bool())
        self.corners_distance = kwargs.get('corners_distance', float())
        from std_msgs.msg import Header
        self.header_pallet_detection = kwargs.get('header_pallet_detection', Header())
        self.message = kwargs.get('message', str())
        from geometry_msgs.msg import Vector3
        self.left_pocket = kwargs.get('left_pocket', Vector3())
        from geometry_msgs.msg import Vector3
        self.right_pocket = kwargs.get('right_pocket', Vector3())
        from geometry_msgs.msg import Vector3
        self.center_point = kwargs.get('center_point', Vector3())
        self.pallet_found = kwargs.get('pallet_found', bool())
        self.pallet_angle = kwargs.get('pallet_angle', float())

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
        if self.header_dolly != other.header_dolly:
            return False
        if self.status_of_camera != other.status_of_camera:
            return False
        if self.left_corners != other.left_corners:
            return False
        if self.right_corners != other.right_corners:
            return False
        if self.point != other.point:
            return False
        if self.dolly_found != other.dolly_found:
            return False
        if self.corners_distance != other.corners_distance:
            return False
        if self.header_pallet_detection != other.header_pallet_detection:
            return False
        if self.message != other.message:
            return False
        if self.left_pocket != other.left_pocket:
            return False
        if self.right_pocket != other.right_pocket:
            return False
        if self.center_point != other.center_point:
            return False
        if self.pallet_found != other.pallet_found:
            return False
        if self.pallet_angle != other.pallet_angle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header_dolly(self):
        """Message field 'header_dolly'."""
        return self._header_dolly

    @header_dolly.setter
    def header_dolly(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header_dolly' field must be a sub message of type 'Header'"
        self._header_dolly = value

    @builtins.property
    def status_of_camera(self):
        """Message field 'status_of_camera'."""
        return self._status_of_camera

    @status_of_camera.setter
    def status_of_camera(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'status_of_camera' field must be of type 'str'"
        self._status_of_camera = value

    @builtins.property
    def left_corners(self):
        """Message field 'left_corners'."""
        return self._left_corners

    @left_corners.setter
    def left_corners(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'left_corners' field must be a sub message of type 'Vector3'"
        self._left_corners = value

    @builtins.property
    def right_corners(self):
        """Message field 'right_corners'."""
        return self._right_corners

    @right_corners.setter
    def right_corners(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'right_corners' field must be a sub message of type 'Vector3'"
        self._right_corners = value

    @builtins.property
    def point(self):
        """Message field 'point'."""
        return self._point

    @point.setter
    def point(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'point' field must be a sub message of type 'Vector3'"
        self._point = value

    @builtins.property
    def dolly_found(self):
        """Message field 'dolly_found'."""
        return self._dolly_found

    @dolly_found.setter
    def dolly_found(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'dolly_found' field must be of type 'bool'"
        self._dolly_found = value

    @builtins.property
    def corners_distance(self):
        """Message field 'corners_distance'."""
        return self._corners_distance

    @corners_distance.setter
    def corners_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'corners_distance' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'corners_distance' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._corners_distance = value

    @builtins.property
    def header_pallet_detection(self):
        """Message field 'header_pallet_detection'."""
        return self._header_pallet_detection

    @header_pallet_detection.setter
    def header_pallet_detection(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header_pallet_detection' field must be a sub message of type 'Header'"
        self._header_pallet_detection = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def left_pocket(self):
        """Message field 'left_pocket'."""
        return self._left_pocket

    @left_pocket.setter
    def left_pocket(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'left_pocket' field must be a sub message of type 'Vector3'"
        self._left_pocket = value

    @builtins.property
    def right_pocket(self):
        """Message field 'right_pocket'."""
        return self._right_pocket

    @right_pocket.setter
    def right_pocket(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'right_pocket' field must be a sub message of type 'Vector3'"
        self._right_pocket = value

    @builtins.property
    def center_point(self):
        """Message field 'center_point'."""
        return self._center_point

    @center_point.setter
    def center_point(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'center_point' field must be a sub message of type 'Vector3'"
        self._center_point = value

    @builtins.property
    def pallet_found(self):
        """Message field 'pallet_found'."""
        return self._pallet_found

    @pallet_found.setter
    def pallet_found(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'pallet_found' field must be of type 'bool'"
        self._pallet_found = value

    @builtins.property
    def pallet_angle(self):
        """Message field 'pallet_angle'."""
        return self._pallet_angle

    @pallet_angle.setter
    def pallet_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pallet_angle' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pallet_angle' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pallet_angle = value
