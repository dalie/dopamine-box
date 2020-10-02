#include <Arduino.h>
#include <string>
#include <map>
#include "led-array.cpp"

using namespace std;

class Speaker
{
private:
    LedArray &_leds;
    std::map<int, float> _notes;
    float _noteDuration;

    int _pin;

    float getFrequency(float n, float frequencyStart)
    {
        return frequencyStart * pow(2, n / 12);
    }

public:
    Speaker(int pin, double bpm, LedArray &leds) : _leds(leds)
    {

        this->_leds = leds;
        this->_pin = pin;
        this->_noteDuration = round((1000 * 60.0) / bpm);
    }

    void setup()
    {
        float startFequency = 65.41;
        int keyCount = 61;

        for (int i = 0; i < keyCount; i++)
        {
            this->_notes.insert({i, this->getFrequency(i, startFequency)});
        }
    }

    void loop()
    {
    }

    void play(int key, float noteDuration, int led = -1)
    {
        if (led > -1)
        {
            this->_leds.on(led);
        }
        int duration = round(noteDuration * this->_noteDuration);
        tone(this->_pin, round(this->_notes[key]), duration);
        delay(duration);
        if (led > -1)
        {
            this->_leds.off(led);
        }
        this->noteDelay(1.0 / 8);
    }

    void noteDelay(float noteDuration)
    {
        delay(round(noteDuration * this->_noteDuration));
    }

    void playMario()
    {
        this->play(24, 1.0 / 4, 3);
        this->play(24, 1.0 / 4, 3);
        this->noteDelay(1.0 / 4);

        this->play(24, 1.0 / 8, 3);
        this->noteDelay(1.0 / 4);

        this->play(19, 1.0 / 8, 2);
        this->play(24, 1.0 / 8, 3);
        this->noteDelay(1.0 / 4);

        this->play(28, 1.0 / 4, 4);
        this->noteDelay(1.0 / 4);

        this->play(19, 1.0 / 4, 0);
    }

    void playLittleStar()
    {

        this->play(24, 1.0 / 4, 0);
        this->play(24, 1.0 / 4, 0);
        this->play(31, 1.0 / 4, 4);
        this->play(31, 1.0 / 4, 4);
        this->play(33, 1.0 / 4, 4);
        this->play(33, 1.0 / 4, 4);
        this->play(31, 1.0 / 2, 4);
        this->noteDelay(1.0 / 8);
        this->play(29, 1.0 / 4, 3);
        this->play(29, 1.0 / 4, 3);
        this->play(28, 1.0 / 4, 2);
        this->play(28, 1.0 / 4, 2);
        this->play(26, 1.0 / 4, 2);
        this->play(26, 1.0 / 4, 1);
        this->play(24, 1.0 / 2, 0);
    }

    void playPassePartout()
    {

        this->play(19, 1.0 / 2, 2);
        this->play(23, 1.0 / 4, 4);
        this->play(21, 1.0 / 4, 3);
        this->play(19, 1.0 / 2, 2);
        this->play(19, 1.0 / 4, 2);
        this->play(19, 1.0 / 4, 2);
        this->play(18, 1.0 / 2, 1);
        this->play(19, 1.0 / 2, 2);
        this->play(16, 1.0 / 2, 0);
    }
};