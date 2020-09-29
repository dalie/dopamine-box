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

    this->off();
  }

  void setup()
  {
    pinMode(pin, OUTPUT);
  }

  void on()
  {
    digitalWrite(this->pin, HIGH);
    tone(2, this->frequency, 75);
  }

  void off()
  {
    digitalWrite(this->pin, LOW);
  }
};
