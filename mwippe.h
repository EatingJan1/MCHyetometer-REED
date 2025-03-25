#ifndef MWIPPE_H
#define MWIPPE_H

//using namespace std;

class mwippe
{
public:
    mwippe(unsigned int Pin, float rainunit);
    mwippe(unsigned int Pin1, unsigned int Pin2, float rainunit);
    void runcheckerwipp();
    float getDayrain();
    void setDayrain(float raintoday);
    float getRainunit();
    void setRainunit(float rainunit);
    void resetRaintoday();
    void readpinstate();


private:
    unsigned int Daytimerain;
    float rainunit;
    
    struct
    {
        unsigned int Pin1;
        unsigned int Pin2;
        
    }pinout;
    
    bool S1;
    bool S2;

    struct
    {
        bool Pin1;
        bool Pin2;
    }pinstate;

    void checkonesensor();
    void checktwosensor();
    void addWater();
    
};



#endif // TASK_H
