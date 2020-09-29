#include <Arduino.h>
#include <string>
#include <map>
#include "led-array.cpp"
using namespace std;

class Speaker
{
private:
    std::map<int, float> _notes;
    float _noteDuration;

    int _pin;

    float getFrequency(float n, float frequencyStart)
    {
        return frequencyStart * pow(2, n / 12);
    }

public:
    Speaker() {}
    Speaker(int pin, double bpm)
    {

        this->_pin = pin;
        this->_noteDuration = round((1000 * 60.0) / bpm);
    }

    void setup()
    {
        Serial.print("Note duration: ");
        Serial.println(this->_noteDuration);
        float startFequency = 16.35;
        int keyCount = 88;

        for (int i = 0; i < keyCount; i++)
        {
            this->_notes.insert({i, this->getFrequency(i, startFequency)});
        }
    }

    void loop()
    {
    }

    void play(int key, float noteDuration)
    {
        int duration = round(noteDuration * this->_noteDuration);
        tone(this->_pin, round(this->_notes[key]), duration);
        Serial.print("Note:");
        Serial.println(round(this->_notes[key]));
        Serial.print("Note duration:");
        Serial.println(duration);
        delay(duration);
    }

    void noteDelay(float noteDuration)
    {
        int duration = round(noteDuration * this->_noteDuration);
        Serial.print("Delay:");
        Serial.println(duration);
        delay(duration);
    }

    void playMario(LedArray &leds)
    {

        leds.on(3);
        this->play(41, 1.0 / 4);
        leds.off(3);

        this->noteDelay(1.0 / 8);

        leds.on(3);
        this->play(41, 1.0 / 4);
        leds.off(3);

        this->noteDelay(1.0 / 4);

        leds.on(3);
        this->play(41, 1.0 / 8);
        leds.off(3);

        this->noteDelay(1.0 / 4);

        leds.on(2);
        this->play(39, 1.0 / 8);
        leds.off(2);

        leds.on(3);
        this->play(41, 1.0 / 8);
        leds.off(3);

        this->noteDelay(1.0 / 4);

        leds.on(4);
        this->play(43, 1.0 / 4);
        leds.off(4);

        this->noteDelay(1.0 / 4);

        leds.on(0);
        this->play(36, 1.0 / 4);
        leds.off(0);
    }
};