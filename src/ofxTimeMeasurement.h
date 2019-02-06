#pragma once
#include "ofMain.h"

class ofxTimeMeasurement : public ofThread
{
public:
	
    ofxTimeMeasurement();
    ~ofxTimeMeasurement();
    
    void start();
    void pause();
    void reset();
    
    void threadedFunction();
    
    float getCurrentTime();
	

protected:

    float currentTime;
    float beforeTime;
    float tempTime;
    
    bool isTimerRunning;
    
};


