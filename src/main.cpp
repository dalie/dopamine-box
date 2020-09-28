#include <Arduino.h>
#include "led.cpp"
#include "button.cpp"

Button button(7);

const int animationDelay = 75;

int up = 0;
int buttonPin = 7;

bool isBtnPressed = false;
int ledCount = 5;
Led leds[5];
int ledPins[5] = {8, 9, 10, 11, 12};
int currentLed = 0;

void loopLeds(bool up)
{
  if (up)
  {
    for (int i = 0; i < ledCount; i++)
    {
      leds[i].on();
      delay(animationDelay);
    }

    for (int i = 0; i < ledCount - 1; i++)
    {
      leds[i].off();
      delay(animationDelay);
    }
  }
  else
  {
    for (int i = ledCount; i >= 0; i--)
    {
      leds[i].on();
      delay(animationDelay);
    }
    for (int i = ledCount; i >= 0; i--)
    {
      leds[i].off();
      delay(animationDelay);
    }
  }
}

void onClick()
{
  leds[currentLed].on();

  currentLed++;
  if (currentLed >= ledCount)
  {
    currentLed = 0;

    for (int i = 0; i < ledCount - 1; i++)
    {
      leds[i].off();
    }

    loopLeds(false);
    loopLeds(true);
    loopLeds(false);
    loopLeds(true);
    loopLeds(false);
  }
}

void setup()
{
  Serial.begin(115200);

  for (int i = 0; i < ledCount; i++)
  {
    leds[i] = Led(ledPins[i], i * 400 + 200);
  }

  button.setup();
  button.onClick(onClick);
}

void loop()
{
  button.loop();
}
