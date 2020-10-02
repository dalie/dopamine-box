#include <Arduino.h>
#include <vector>
#include "button.cpp"
#include "speaker.cpp"

int buttonCount = 5;
int buttonPins[5] = {3, 5, 7, 9, 11};
Button buttons[5];
const int animationDelay = 75;

int ledCount = 5;
int ledPins[5] = {4, 6, 8, 10, 12};
LedArray ledArray(ledPins, 5);

Speaker speaker(2, 80, ledArray);

int currentSong = 0;

void onClick(int ledIndex)
{
  Serial.println("button clicked");
  ledArray.on(ledIndex);
  speaker.play(40 + ledIndex, 1.0 / 4);

  int currentLedOn = 0;

  for (int i = 0; i < buttonCount; i++)
  {
    if (buttons[i].isLedOn())
    {
      currentLedOn++;
    }
  }

  if (currentLedOn >= ledCount)
  {

    delay(500);
    ledArray.off();
    for (int i = 0; i < buttonCount; i++)
    {
      buttons[i].setLed(false);
    }

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
  randomSeed(analogRead(0));
  currentSong = random(0, 2);

  ledArray.setup();

  speaker.setup();

  buttons[0].setup(buttonPins[0], 0);
  buttons[0].onClick(onClick);
  buttons[1].setup(buttonPins[1], 1);
  buttons[1].onClick(onClick);
  buttons[2].setup(buttonPins[2], 2);
  buttons[2].onClick(onClick);
  buttons[3].setup(buttonPins[3], 3);
  buttons[3].onClick(onClick);
  buttons[4].setup(buttonPins[4], 4);
  buttons[4].onClick(onClick);

  /* for (int i = 0; i < buttonCount; i++)
  {

    Button b = buttons[i];

    b.setup();
    b.onClick(onClick);
    Serial.print("Setup:");
    Serial.println(b.getLedIndex());
  } */
}

void loop()
{
  speaker.loop();

  for (int i = 0; i < buttonCount; i++)
  {
    buttons[i].loop();
  }
}
