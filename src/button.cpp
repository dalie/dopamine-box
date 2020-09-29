#include <Arduino.h>

typedef void (*clickCallback)(void);

class Button
{
private:
    int _pin;
    unsigned int _clickDelay = 75;
    unsigned long _clickStart = 0;
    clickCallback _callback = NULL;

public:
    Button()
    {
    }
    Button(int pin)
    {
        this->_pin = pin;
    }

    void setup()
    {
        pinMode(this->_pin, INPUT);
    }

    void loop()
    {
        if (this->_callback)
        {
            int highLow = digitalRead(this->_pin);

            if (this->_clickStart == 0 && highLow == HIGH)
            {
                this->_clickStart = millis();
            }
            else if (this->_clickStart != 0 && highLow == LOW && millis() - this->_clickStart > this->_clickDelay)
            {
                this->_callback();
                this->_clickStart = 0;
            }
            else if (this->_clickStart != 0 && highLow == LOW)
            {
                this->_clickStart = 0;
            }
        }
    }

    void onClick(clickCallback callback)
    {
        this->_callback = callback;
    }
};