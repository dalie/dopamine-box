#include <Arduino.h>

class Button {
  private: int pin;

  public: 
  Button(){}
  Button(int pin) {
      this->pin = pin;
      pinMode(pin, INPUT);
    }
    bool isPressed() {
      int highLow = digitalRead(this->pin);

      bool isPressed = false;
      if(highLow == HIGH){
        isPressed = true;
      }
      
      return isPressed;
    }
};
