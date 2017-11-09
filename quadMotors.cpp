#include "quadMotors.h"
#include <Arduino.h>

void QuadMotors::preInitialize() const {
    pinMode(signal1, OUTPUT);
    pinMode(pwm1, OUTPUT);
    pinMode(signal2, OUTPUT);
    pinMode(pwm2, OUTPUT);
    pinMode(signal3, OUTPUT);
    pinMode(pwm3, OUTPUT);
    pinMode(signal4, OUTPUT);
    pinMode(pwm4, OUTPUT);
}

void QuadMotors::initialize() const {
    digitalWrite(signal1, HIGH);
    digitalWrite(signal2, HIGH);
    digitalWrite(signal3, HIGH);
    digitalWrite(signal4, HIGH);
}

void QuadMotors::hover(const int power) const {
    analogWrite(pwm1, power);
    analogWrite(pwm2, power);
    analogWrite(pwm3, power);
    analogWrite(pwm4, power);
}
