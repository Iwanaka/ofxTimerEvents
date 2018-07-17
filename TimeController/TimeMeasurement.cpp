//
//  TimeMeasurement.cpp
//  ofxTimeController
//
//  Created by Hiromitsu Iwanaka on 2018/05/18.
//

#include "TimeMeasurement.h"

//--------------------------------------------------------------
TimeMeasurement::TimeMeasurement():
currentTime(0.0),
beforeTime(0.0),
tempTime(0.0),
isStart(false)
{
    
}

//--------------------------------------------------------------
TimeMeasurement::~TimeMeasurement(){
    
    while (thread.isRunning())
    {
        stopThread();
    }
    
}


//--------------------------------------------------------------
void TimeMeasurement::start() {
    
    if(isStart) return;
    
    while (!thread.isRunning())
    {
        
        startThread();
        tempTime = ofGetElapsedTimef();
        
    }
    
    isStart = true;
    
}

//--------------------------------------------------------------
void TimeMeasurement::pause() {
    
    if(!isStart) return;
    
    while (thread.isRunning())
    {
        
        stopThread();
        
    }
    
        
    float time = ofGetElapsedTimef() - tempTime;
    currentTime = beforeTime + time;
    beforeTime = currentTime;
    
    isStart = false;
}


//--------------------------------------------------------------
void TimeMeasurement::reset() {
    
    while (thread.isRunning())
    {
        
        stopThread();
        
    }
    
    currentTime = 0.0;
    beforeTime = 0.0;

    isStart = false;
}

//--------------------------------------------------------------
void TimeMeasurement::threadedFunction() {
    
    while (isThreadRunning()) {
        
        if (lock()) {
            
            float time = ofGetElapsedTimef() - tempTime;
            
            currentTime = beforeTime + time;
            
            unlock();
            
        }
    }
    
}

//--------------------------------------------------------------
float TimeMeasurement::getCurrentTime() {
    
    return currentTime;
    
}

//--------------------------------------------------------------
void TimeMeasurement::setDecimalPoint(int decimalPoint) {
    
    this->decimalPoint = decimalPoint;
    
}


