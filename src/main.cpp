#include <Arduino.h>
#include <ctime>
#include <cstdlib>
#include "button.cpp"
#include "speaker.cpp"

Button button(7);

const int animationDelay = 75;

int up = 0;
int buttonPin = 7;

int ledCount = 5;
int ledPins[5] = {8, 9, 10, 11, 12};
LedArray ledArray(ledPins, 5);
Speaker speaker(2, 80, ledArray);
int currentLed = 0;

int currentSong = 0;

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

    if (currentSong == 0)
    {
      speaker.playMario();
    }
    else if (currentSong == 1)
    {
      speaker.playLittleStar();
    }
    else if (currentSong == 2)
    {
      speaker.playPassePartout();
    }

    currentSong++;
    if (currentSong > 2)
    {
      currentSong = 0;
    }

    ledArray.off();
  }
}

void setup()
{
  Serial.begin(115200);

  srand(unsigned(time(0)));
  currentSong = rand() / ((RAND_MAX + 1u) / 3);

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
