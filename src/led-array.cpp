#include <Arduino.h>
#include "led.cpp"

class LedArray
{
private:
    int frequency;
    Led leds[];

public:
    LedArray() {}
    LedArray(int pins[])
    {

        int n = sizeof(pins) / sizeof(*pins);
        Led leds[n];

        for (int i = 0; i < n; i++)
        {
            leds[i] = Led(pins[i], i * 40 + 40);
        }
    }
    void on()
    {
    }

    void off()
    {
    }
};