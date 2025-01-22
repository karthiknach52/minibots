#include <Servo.h>

class Gate {
  private:
    Servo servo;
  public:
    Gate();
    void close();
    void open();
};