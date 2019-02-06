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
isTimerRunning(false)
{
    
}

//--------------------------------------------------------------
ofxTimeMeasurement::~ofxTimeMeasurement(){
    
    while (isThreadRunning())
    {
        stopThread();
    }
    
}


//--------------------------------------------------------------
void ofxTimeMeasurement::start() {
    
    if(isTimerRunning) return;
    
    while (!isThreadRunning())
    {
        
        startThread();
        tempTime = ofGetElapsedTimef();
        
    }
    
	isTimerRunning = true;
    
}

//--------------------------------------------------------------
void ofxTimeMeasurement::pause() {
    
    if(!isTimerRunning) return;
    
    while (isThreadRunning())
    {
        
        stopThread();
        
    }
    
        
    float time = ofGetElapsedTimef() - tempTime;
    currentTime = beforeTime + time;
    beforeTime = currentTime;
    
	isTimerRunning = false;
}


//--------------------------------------------------------------
void ofxTimeMeasurement::reset() {
    
    while (isThreadRunning())
    {
        
        stopThread();
        
    }
    
    currentTime = 0.0;
    beforeTime = 0.0;

	isTimerRunning = false;
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


