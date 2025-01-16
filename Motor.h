// Direction definitions for turning
#define RIGHT 1
#define LEFT 0

class Motor {
  private:
    // Default motor pin definitions
    int directionPinL = 12;
    int pwmPinL = 3;
    int brakePinL = 9;
    int directionPinR = 13;
    int pwmPinR = 11;
    int brakePinR = 8;

  public:
    Motor();
    void brake(uint8_t state);
    void drive();
    void turn(int direction);
};