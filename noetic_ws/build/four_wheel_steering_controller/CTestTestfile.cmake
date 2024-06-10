# CMake generated Testfile for 
# Source directory: /home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller
# Build directory: /home/avinaash/noetic_ws/build/four_wheel_steering_controller
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_four_wheel_steering_controller_rostest_test_four_wheel_steering_controller_twist_cmd.test "/home/avinaash/noetic_ws/build/four_wheel_steering_controller/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/avinaash/noetic_ws/build/four_wheel_steering_controller/test_results/four_wheel_steering_controller/rostest-test_four_wheel_steering_controller_twist_cmd.xml" "--return-code" "/usr/bin/python3 /opt/ros/noetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller --package=four_wheel_steering_controller --results-filename test_four_wheel_steering_controller_twist_cmd.xml --results-base-dir \"/home/avinaash/noetic_ws/build/four_wheel_steering_controller/test_results\" /home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller/test/four_wheel_steering_controller_twist_cmd.test ")
set_tests_properties(_ctest_four_wheel_steering_controller_rostest_test_four_wheel_steering_controller_twist_cmd.test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;52;catkin_run_tests_target;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;80;add_rostest;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;100;_add_rostest_google_test;/home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller/CMakeLists.txt;80;add_rostest_gtest;/home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller/CMakeLists.txt;0;")
add_test(_ctest_four_wheel_steering_controller_rostest_test_four_wheel_steering_controller_4ws_cmd.test "/home/avinaash/noetic_ws/build/four_wheel_steering_controller/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/avinaash/noetic_ws/build/four_wheel_steering_controller/test_results/four_wheel_steering_controller/rostest-test_four_wheel_steering_controller_4ws_cmd.xml" "--return-code" "/usr/bin/python3 /opt/ros/noetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller --package=four_wheel_steering_controller --results-filename test_four_wheel_steering_controller_4ws_cmd.xml --results-base-dir \"/home/avinaash/noetic_ws/build/four_wheel_steering_controller/test_results\" /home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller/test/four_wheel_steering_controller_4ws_cmd.test ")
set_tests_properties(_ctest_four_wheel_steering_controller_rostest_test_four_wheel_steering_controller_4ws_cmd.test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;52;catkin_run_tests_target;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;80;add_rostest;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;100;_add_rostest_google_test;/home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller/CMakeLists.txt;86;add_rostest_gtest;/home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller/CMakeLists.txt;0;")
add_test(_ctest_four_wheel_steering_controller_rostest_test_four_wheel_steering_wrong_config.test "/home/avinaash/noetic_ws/build/four_wheel_steering_controller/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/avinaash/noetic_ws/build/four_wheel_steering_controller/test_results/four_wheel_steering_controller/rostest-test_four_wheel_steering_wrong_config.xml" "--return-code" "/usr/bin/python3 /opt/ros/noetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller --package=four_wheel_steering_controller --results-filename test_four_wheel_steering_wrong_config.xml --results-base-dir \"/home/avinaash/noetic_ws/build/four_wheel_steering_controller/test_results\" /home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller/test/four_wheel_steering_wrong_config.test ")
set_tests_properties(_ctest_four_wheel_steering_controller_rostest_test_four_wheel_steering_wrong_config.test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;52;catkin_run_tests_target;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;80;add_rostest;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;100;_add_rostest_google_test;/home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller/CMakeLists.txt;92;add_rostest_gtest;/home/avinaash/noetic_ws/src/ros_controllers/four_wheel_steering_controller/CMakeLists.txt;0;")
subdirs("gtest")
