#include "button.cpp"
#include "led.cpp"

const int animationDelay = 75;

int up = 0;
int buttonPin = 7;
Button btn(7);
bool isBtnPressed = false;
int ledCount = 5;
Led leds[5];
int ledPins[5] = {8, 9, 10, 11, 12};
int currentLed = 0;

void setup()
{
  pinMode(buttonPin, INPUT);

  for (int i = 0; i < ledCount; i++) {
    leds[i] = Led(ledPins[i], i*400 +200);
  }


}

void loop()
{
  if (btn.isPressed() != isBtnPressed) {
    if (btn.isPressed()) {
      leds[currentLed].on();

      currentLed++;
      if (currentLed >= ledCount) {
        currentLed = 0;

        loopLeds(false);
        loopLeds(true);
        loopLeds(false);
        loopLeds(true);
        loopLeds(false);
      }
      delay(200);
      isBtnPressed = true;
      
    }else{
      delay(200);
      isBtnPressed = false;
    }
  }


}

void loopLeds(bool up) {
  if (up) {
    for (int i = 0; i < ledCount; i++) {
      leds[i].on();
      delay(animationDelay);
    }

    for (int i = 0; i < ledCount - 1; i++) {
      leds[i].off();
      delay(animationDelay);
    }
  } else {
    for (int i = ledCount; i >= 0; i--) {
      leds[i].on();
      delay(animationDelay);
    }
    for (int i = ledCount; i >= 0; i--) {
      leds[i].off();
      delay(animationDelay);
    }
  }
}
