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

void QuadMotors::write(const int m1, const int m2, const int m3, const int m4) const {
    analogWrite(pwm1, m1);
    analogWrite(pwm2, m2);
    analogWrite(pwm3, m3);
    analogWrite(pwm4, m4);
}
