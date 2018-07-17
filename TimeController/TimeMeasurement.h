#pragma once
#include "ofMain.h"

class TimeMeasurement : public ofThread
{
public:
	
    TimeMeasurement();
    ~TimeMeasurement();
    
    void start();
    void pause();
    void reset();
    
    void threadedFunction();
    
    float getCurrentTime();
    void setDecimalPoint(int decimalPoint);
	

protected:

    float currentTime;
    float beforeTime;
    float tempTime;
    
    bool isStart;
    
};


