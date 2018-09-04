//
//  ofxTimeMeasurement.cpp
//  ofxTimeController
//
//  Created by Hiromitsu Iwanaka on 2018/05/18.
//

#include "ofxTimeMeasurement.h"

//--------------------------------------------------------------
ofxTimeMeasurement::ofxTimeMeasurement():
currentTime(0.0),
beforeTime(0.0),
tempTime(0.0),
isStart(false)
{
    
}

//--------------------------------------------------------------
ofxTimeMeasurement::~ofxTimeMeasurement(){
    
    while (thread.isRunning())
    {
        stopThread();
    }
    
}


//--------------------------------------------------------------
void ofxTimeMeasurement::start() {
    
    if(isStart) return;
    
    while (!thread.isRunning())
    {
        
        startThread();
        tempTime = ofGetElapsedTimef();
        
    }
    
    isStart = true;
    
}

//--------------------------------------------------------------
void ofxTimeMeasurement::pause() {
    
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
void ofxTimeMeasurement::reset() {
    
    while (thread.isRunning())
    {
        
        stopThread();
        
    }
    
    currentTime = 0.0;
    beforeTime = 0.0;

    isStart = false;
}

//--------------------------------------------------------------
void ofxTimeMeasurement::threadedFunction() {
    
    while (isThreadRunning()) {
        
        if (lock()) {
            
            float time = ofGetElapsedTimef() - tempTime;
            
            currentTime = beforeTime + time;
            
            unlock();
            
        }
    }
    
}

//--------------------------------------------------------------
float ofxTimeMeasurement::getCurrentTime() {
    
    return currentTime;
    
}

//--------------------------------------------------------------
void ofxTimeMeasurement::setDecimalPoint(int decimalPoint) {
    
    this->decimalPoint = decimalPoint;
    
}


