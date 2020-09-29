#include <Arduino.h>
#include "button.cpp"
#include "speaker.cpp"

Button button(7);
Speaker speaker(2, 80);
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
  speaker.play(40 + currentLed, 1.0 / 4);
  currentLed++;
  if (currentLed >= ledCount)
  {
    currentLed = 0;
    delay(500);
    ledArray.off();
    speaker.playMario(ledArray);

    ledArray.off();
  }
}

void setup()
{
  Serial.begin(115200);

  ledArray.setup();
  button.setup();
  speaker.setup();
  button.onClick(onClick);
}

void loop()
{
  button.loop();
  speaker.loop();
}
