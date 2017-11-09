#include <Wire.h>
#include <L3G.h>
#include <LSM303.h>
#include "quadMotors.h"
#include "pid.h"

LSM303 compass;
L3G gyro;
QuadMotors motors(4,3,7,6,12,11,2,10);
okapi::Pid yrotPID(0.3, 0, 0);

void setup() {
  Serial.begin(115200);
  Wire.begin();

  motors.preInitialize();
  
  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }
  if (!compass.init())
  {
    Serial.println("Failed to initialize compass!");
    while (1);
  }
  gyro.enableDefault();
  compass.enableDefault(); 

  motors.initialize();
  yrotPID.setTarget(255);
}

void loop() {
  gyro.read();
  compass.read();
  
  motors.write(yrotPID.step(51*(compass.a.y/3277.0)), 0, 0, 0);

  delay(20);
}

