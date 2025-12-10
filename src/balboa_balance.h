#pragma once

#include <stdint.h>
#include <LSM6.h>
#include <Balboa32U4.h>

// this is the gear ratio, adjust as needed.
const int16_t GEAR_RATIO = 111;

// Used to limit the maximum motor speed.
// Might want to reduce based on gear ratio
const int16_t MOTOR_SPEED_LIMIT = 300;

// Relates the angle to its rate of change for a robot that is falling from a nearly-vertical position
// or rising up to it. The relationship between the two is close to linear. The exact relation depends on the size of the wheels.
// 80mm wheels should be about 140, meaning if a robot falls by 90 degrees, we can convert that to millidegrees and estimate:
// 90 000 / 140 = 642 deg/s
const int16_t ANGLE_RATE_RATIO = 140;

// These relate to the PID, will probably be removed as we are using a PID of sorts.
const int16_t ANGLE_RESPONSE = 11;
const int16_t DISTANCE_RESPONSE = 73;
const int16_t DISTANCE_DIFF_RESPONSE = -50;

// SPEED_RESPONSE is used to supress the large back-and-forth oscillations caised nu DISTANCE_RESPONSE.
// Adjust until oscillation die off after a few cycles
const int16_t SPEED_RESPONSE = 3300;

// The code bases itself on a 100Hz update rate.
const uint8_t UPDATE_TIME_MS = 10;

// How many measurements to calibrate the gyro.
const uint8_t CALIBRATION_ITERATIONS = 100;

// Used to determine when the robot should start and stop trying to balance.
// These are measured in millidegrees. if we f.eks. use 45 000 as start and 70 000 as stop,
// it would mean that the robot will start balancing at 45 degrees and give up at 70.
const int32_t START_BALANCING_ANGLE = 45000;
const int32_t STOP_BALANCING_ANGLE = 70000;

// extern means it will look for these variables in another file.
// These variables will allow us to use them in the .ino file.
extern int32_t angle; // millidegrees
extern int32_t angleRate; // deg/s
extern int16_t motorSpeed; // average motor speed setting

// These must be defined in the sketch / .ino file.
extern LSM6 imu;
extern Balboa32U4Motors motors;
extern Balboa32U4Encoders encoders;

// This is the PID we use when balancing
int32_t pid_controll();

// Call this in setup() to initialize and calibrate the IMU
void balanceSetup();

// Call this in loop() to run the full balancing algorithm
void balanceUpdate();

// Call this function to set a driving speed in ticks/ms.
// This will adjust the robot's encoder measurements every update cycle.
// Differing values results in turning.
void balanceDrive(int16_t leftSpeed, int16_t rightSpeed);

// Returns true if the robot is trying to balance.
bool isBalancing();

// Returns true if the last update cycle was delayed to more than UPDATE_TIME_MS+1 ms.
// indicates delays like long computations or interrupts.
bool balanceUpdateDelayed();

// Used to take control of the motors but keep updates going so the robot doesn't lose track of position and angle.
balanceUpdateSensors();

// Used to reset encoders
void balanceResetEncoders();