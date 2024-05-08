// generated from
// rosidl_typesupport_fastrtps_c/resource/rosidl_typesupport_fastrtps_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef SICK_VISIONARY_T_MINI__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_
#define SICK_VISIONARY_T_MINI__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_

#if __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_sick_visionary_t_mini __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_sick_visionary_t_mini __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_sick_visionary_t_mini __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_sick_visionary_t_mini __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_FASTRTPS_C_BUILDING_DLL_sick_visionary_t_mini
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sick_visionary_t_mini ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_sick_visionary_t_mini
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sick_visionary_t_mini ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_sick_visionary_t_mini
  #endif
#else
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_sick_visionary_t_mini __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_sick_visionary_t_mini
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sick_visionary_t_mini __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sick_visionary_t_mini
  #endif
#endif

#if __cplusplus
}
#endif

#endif  // SICK_VISIONARY_T_MINI__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_
