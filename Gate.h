#include <Servo.h>

class Gate {
  private:
    Servo servoL;
    Servo servoR;
  public:
    Gate();
    void open();
};