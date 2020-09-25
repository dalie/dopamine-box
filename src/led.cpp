#include <Arduino.h>

class Led {
  private:
    int pin;
    int frequency;
  public:
    Led() {}
    Led(int pin, int frequency) {
      this->pin = pin;
      this->frequency = frequency;
      
      pinMode(pin, OUTPUT);
      this->off();
    }
    void on() {
      tone(2, this->frequency, 75);
      digitalWrite(this->pin, HIGH);
    }

    void off() {
      digitalWrite(this->pin, LOW);
    }
};
