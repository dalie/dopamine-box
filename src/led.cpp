#include <Arduino.h>

class Led
{
private:
  int pin;
  int frequency;

public:
  Led() {}
  Led(int pin, int frequency)
  {
    this->pin = pin;
    this->frequency = frequency;

    pinMode(pin, OUTPUT);
    this->off();
  }
  void on()
  {
    digitalWrite(this->pin, HIGH);
    //tone(2, this->frequency, 75);
  }

  void off()
  {
    digitalWrite(this->pin, LOW);
  }
};
