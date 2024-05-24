#!/usr/bin/env python3

import serial
import re

def read_imu():
    try:
        imu_port = serial.Serial('/dev/ttyACM0', 57600, timeout=1)
    except serial.SerialException as e:
        print(f"Error opening serial port: {e}")
        return
    
    while True:
        line = imu_port.readline().decode("utf-8").strip()
        if line:
            match = re.match(r"#YPR=(-?\d+\.\d+),(-?\d+\.\d+),(-?\d+\.\d+)", line)
            if match:
                yaw, pitch, roll = map(float, match.groups())
                print(f"Yaw: {yaw}, Pitch: {pitch}, Roll: {roll}")
            else:
                print(f"Received invalid data: {line}")

def main():
    read_imu()

if __name__ == '__main__':
    main()
