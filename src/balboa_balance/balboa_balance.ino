#include <Balboa32U4.h>
#include <Wire.h>
#include <LSM6.h>
#include "balboa_balance.h"

LSM6 imu;
Balboa32U4Motors motors;
Balboa32U4Encoders encoders;

void setup() {
  ledYellow(0);
  ledRed(1);
  balanceSetup();
  ledRed(0);
}

void loop() {

  balanceUpdate();
  //if (isBalancing()) {ledYellow(1);}

  // Set ledRed to true when the last update was too slow
  ledRed(balanceUpdateDelayed());

  // Display the feedback on the yellow and green led depending on the variable fallingAngleOffset
  // The yellow light will illuminate when fallingAngleOffset is larger then 0.
  // The green light will illumiante when fallingAngleOffset is not larger then 0.
  int32_t fallingAngleOffset = angleRate * ANGLE_RATE_RATIO - angle;
  if (fallingAngleOffset > 0) {
    ledYellow(1);
    ledGreen(0);
  }
  else {
    ledYellow(0);
    ledGreen(1);
  }

}
