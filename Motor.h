// Direction definitions for turning
#include <stdint.h>
#define RIGHT 1
#define LEFT 0

class Motor {
  private:
    // Default motor pin definitions
    int directionPinR = 12;
    int pwmPinR = 3;
    int brakePinR = 9;
    int directionPinL = 13;
    int pwmPinL = 11;
    int brakePinL = 8;

  public:
    Motor();
    void brake(uint8_t state);
    void drive();
    void turn(int direction);
};