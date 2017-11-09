#pragma once

class QuadMotors {
public:
  QuadMotors(const int isignal1, const int ipwm1,
             const int isignal2, const int ipwm2,
             const int isignal3, const int ipwm3,
             const int isignal4, const int ipwm4):
    signal1(isignal1), pwm1(ipwm1),
    signal2(isignal2), pwm2(ipwm2),
    signal3(isignal3), pwm3(ipwm3),
    signal4(isignal4), pwm4(ipwm4) {}

  void preInitialize() const;
  void initialize() const;

  void hover(const int power) const;
private:
  const int signal1, pwm1;
  const int signal2, pwm2;
  const int signal3, pwm3;
  const int signal4, pwm4;
};

