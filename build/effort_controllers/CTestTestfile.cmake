# CMake generated Testfile for 
# Source directory: /home/avinaash/ForkLift_AMR/src/ros_controllers/effort_controllers
# Build directory: /home/avinaash/ForkLift_AMR/build/effort_controllers
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_effort_controllers_rostest_test_effort_position_controller.test "/home/avinaash/ForkLift_AMR/build/effort_controllers/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/avinaash/ForkLift_AMR/build/effort_controllers/test_results/effort_controllers/rostest-test_effort_position_controller.xml" "--return-code" "/usr/bin/python3 /opt/ros/noetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/avinaash/ForkLift_AMR/src/ros_controllers/effort_controllers --package=effort_controllers --results-filename test_effort_position_controller.xml --results-base-dir \"/home/avinaash/ForkLift_AMR/build/effort_controllers/test_results\" /home/avinaash/ForkLift_AMR/src/ros_controllers/effort_controllers/test/effort_position_controller.test ")
set_tests_properties(_ctest_effort_controllers_rostest_test_effort_position_controller.test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;52;catkin_run_tests_target;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;80;add_rostest;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;100;_add_rostest_google_test;/home/avinaash/ForkLift_AMR/src/ros_controllers/effort_controllers/CMakeLists.txt;82;add_rostest_gtest;/home/avinaash/ForkLift_AMR/src/ros_controllers/effort_controllers/CMakeLists.txt;0;")
subdirs("gtest")
