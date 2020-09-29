#include <Arduino.h>
#include <vector>
#include "led.cpp"
using namespace std;

class LedArray
{
private:
    int _frequency;
    int _ledCount = 0;
    vector<Led> _leds;

public:
    LedArray() {}
    LedArray(int pins[], int ledCount)
    {

        this->_ledCount = ledCount;
        for (int i = 0; i < this->_ledCount; i++)
        {
            this->_leds.push_back(Led(pins[i], i * 40 + 40));
        }
    }

    void setup()
    {
        for (int i = 0; i < this->_ledCount; i++)
        {
            this->_leds[i].setup();
        }
    }

    void on()
    {
        for (int i = 0; i < this->_ledCount; i++)
        {
            this->_leds[i].on();
        }
    }

    void on(int pin)
    {
        this->_leds[pin].on();
    }

    void off()
    {
        for (int i = 0; i < this->_ledCount; i++)
        {
            this->_leds[i].off();
        }
    }

    void off(int pin)
    {
        this->_leds[pin].off();
    }
};