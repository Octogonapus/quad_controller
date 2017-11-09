#include <Wire.h>
#include <String.h>
#include <L3G.h>
#include <LSM303.h>
#include "quadMotors.h"

LSM303 compass;
L3G gyro;

QuadMotors motors(4,3,7,6,12,11,2,10);

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
}

void loop() {
  gyro.read();
  compass.read();
  
  motors.write(51*(compass.a.y/3277.0),0,0,0);

//  outstring.setCharAt(11+((int)gyro.g.x)/3277, 'x');
//  outstring.setCharAt(11+((int)compass.a.x)/3277, 'X');
//  outstring.setCharAt(32+((int)gyro.g.y)/3277, 'y');
//  outstring.setCharAt(32+((int)compass.a.y)/3277, 'Y');
//  outstring.setCharAt(53+((int)gyro.g.z)/3277, 'z');
//  outstring.setCharAt(53+((int)compass.a.z)/3277, 'Z');

  delay(20);
}

