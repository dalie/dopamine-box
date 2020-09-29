#include <Arduino.h>
#include "led-array.cpp"
#include "button.cpp"

Button button(7);

const int animationDelay = 75;

int up = 0;
int buttonPin = 7;

int ledCount = 5;
int ledPins[5] = {8, 9, 10, 11, 12};
LedArray ledArray(ledPins, 5);
int currentLed = 0;

void onClick()
{
  ledArray.on(currentLed);

  currentLed++;
  if (currentLed >= ledCount)
  {
    currentLed = 0;

    delay(500);

    for (int i = 0; i < 5; i++)
    {
      ledArray.off();
      delay(500);
      ledArray.on();
      delay(500);
    }

    ledArray.off();
  }
}

void setup()
{
  Serial.begin(115200);

  ledArray.setup();
  button.setup();
  button.onClick(onClick);
}

void loop()
{
  button.loop();
}
