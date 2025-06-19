#include "mwippe.h"
#include <Arduino.h>

mwippe::mwippe(unsigned int Pin, float rainunit)
{
    pinMode(Pin, INPUT);
    this->Daytimerain = 0;
    this->pinout={Pin, NULL};
    this->rainunit = rainunit;
};



mwippe::mwippe(unsigned int Pin1, unsigned int Pin2, float rainunit)
{
    pinMode(Pin1, INPUT);
    pinMode(Pin2, INPUT);
    this->Daytimerain = 0;
    this->pinout={Pin1, Pin2};
    this->rainunit = rainunit;
};


float mwippe::getRainunit()
{
    return this->rainunit;
};

float mwippe::getDayrain()
{
    return this->Daytimerain*this->rainunit;
};

void mwippe::setDayrain(float raintoday)
{
    this->Daytimerain = raintoday/this->rainunit;
}

void mwippe::setRainunit(float rainunit)
{
    this->rainunit = rainunit;
};

void mwippe::resetRaintoday()
{
    this->Daytimerain = 0;
};


void mwippe::readpinstate()
{
    this->pinstate.Pin1 = digitalRead(this->pinout.Pin1);

    if(this->pinout.Pin2 != NULL)
    {
        this->pinstate.Pin2 = digitalRead(this->pinout.Pin2);
    }
}

void mwippe::addWater()
{
    this->Daytimerain += 1;
};


bool mwippe::checkonesensor()
{
    
    if(this->pinstate.Pin1!=digitalRead(this->pinout.Pin1))
    {
        this->addWater();
        this->readpinstate();
        return true;
    }
    return false;

};
bool mwippe::checktwosensor()
{
    //Serial.println(this->pinstate.Pin1);
    //Serial.println(this->pinstate.Pin2);

    if((this->pinstate.Pin1!=digitalRead(this->pinout.Pin1)) and (this->pinstate.Pin2!=digitalRead(this->pinout.Pin2)))
    {
        this->addWater();
        this->readpinstate();
        return true;
    }
    return false;
};


bool mwippe::runcheckerwipp()
{
    if(this->pinout.Pin2 == NULL)
    {
        return this->checkonesensor();
    }
    else
    {
        return this->checktwosensor();
    }
    return 0;

};
