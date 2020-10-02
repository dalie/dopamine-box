#include <Arduino.h>

typedef void (*clickCallback)(int ledIndex);

class Button
{
private:
    bool _isLedOn = false;
    int _ledIndex;
    int _pin;
    unsigned int _clickDelay = 75;
    unsigned long _clickStart = 0;
    clickCallback _callback = NULL;

public:
    Button() {}

    void setup(int pin, int ledIndex)
    {
        this->_ledIndex = ledIndex;
        this->_pin = pin;
        pinMode(this->_pin, INPUT_PULLUP);
    }

    void loop()
    {
        if (this->_callback)
        {
            int highLow = digitalRead(this->_pin);

            if (this->_clickStart == 0 && highLow == LOW)
            {
                this->_clickStart = millis();
            }
            else if (this->_clickStart != 0 && highLow == HIGH && millis() - this->_clickStart > this->_clickDelay)
            {
                this->_isLedOn = !this->_isLedOn;

                this->_callback(this->_ledIndex);

                this->_clickStart = 0;
            }
            else if (this->_clickStart != 0 && highLow == HIGH)
            {
                this->_clickStart = 0;
            }
        }
    }

    int getLedIndex()
    {
        return this->_ledIndex;
    }

    bool isLedOn()
    {
        return this->_isLedOn;
    }

    void setLed(bool isLedOn)
    {
        this->_isLedOn = isLedOn;
    }

    void onClick(clickCallback callback)
    {
        this->_callback = callback;
    }
};