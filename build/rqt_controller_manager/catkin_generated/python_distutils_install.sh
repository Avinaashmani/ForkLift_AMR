#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/avinaash/ForkLift_AMR/src/ros_control/rqt_controller_manager"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/avinaash/ForkLift_AMR/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/avinaash/ForkLift_AMR/install/lib/python3/dist-packages:/home/avinaash/ForkLift_AMR/build/rqt_controller_manager/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/avinaash/ForkLift_AMR/build/rqt_controller_manager" \
    "/usr/bin/python3" \
    "/home/avinaash/ForkLift_AMR/src/ros_control/rqt_controller_manager/setup.py" \
    egg_info --egg-base /home/avinaash/ForkLift_AMR/build/rqt_controller_manager \
    build --build-base "/home/avinaash/ForkLift_AMR/build/rqt_controller_manager" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/avinaash/ForkLift_AMR/install" --install-scripts="/home/avinaash/ForkLift_AMR/install/bin"
