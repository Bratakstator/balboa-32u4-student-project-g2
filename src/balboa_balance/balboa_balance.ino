#include <Balboa32U4.h>
#include <Wire.h>
#include <LSM6.h>
#include "balboa_balance.h"

LSM6 imu;
Balboa32U4Motors motors;
Balboa32U4Encoders encoders;

void setup()
{
  Serial.begin(9600);
  // Uncomment these lines if your motors are reversed.
  // motors.flipLeftMotor(true);
  // motors.flipRightMotor(true);

  ledYellow(0);
  ledRed(1);
  balanceSetup();
  ledRed(0);
}

void loop()
{
  unsigned int batteryVoltage = readBatteryMillivolts();
  Serial.println(batteryVoltage);

  balanceUpdate();

  // Illuminate the red LED if the last full update was too slow.
  ledRed(balanceUpdateDelayed());
}