//
//  ofxTimerEventsCore.cpp
//  ofxTimerEvents
//
//  Created by Hiromitsu Iwanaka on 2018/05/18.
//

#include "ofxTimerEventsCore.h"

using namespace ofxTE;

//--------------------------------------------------------------
ofxTimerEventsCore::ofxTimerEventsCore():
	currentTime(0.0),
	beforeTime(0.0),
	tempTime(0.0),
	isRunning(false)
{}

//--------------------------------------------------------------
ofxTimerEventsCore::~ofxTimerEventsCore(){

	pause();
	waitForThread();

}


//--------------------------------------------------------------
void ofxTimerEventsCore::start() {
    
    if(isRunning || isThreadRunning()) return;
    
    while (!isThreadRunning())
    {
        
        startThread();
        tempTime = ofGetElapsedTimef();
        
    }
    
	isRunning = true;
    
}

//--------------------------------------------------------------
void ofxTimerEventsCore::pause() {

	if (!isRunning || !isThreadRunning()) return;

	while (isThreadRunning())
	{

		stopThread();

	}
	
	float time = ofGetElapsedTimef() - tempTime;
	currentTime = beforeTime + time;
	beforeTime = currentTime;

	isRunning = false;
}


//--------------------------------------------------------------
void ofxTimerEventsCore::reset() {
    
	pause();
    currentTime = 0.0f;
    beforeTime = 0.0f;

}

//--------------------------------------------------------------
void ofxTimerEventsCore::threadedFunction() {
    
    while (isThreadRunning()) {
        
        if (lock()) {
            
            float time = ofGetElapsedTimef() - tempTime;
            
            currentTime = beforeTime + time;    
			sleep(10);

            unlock();
            
        }
    }
    
}

//--------------------------------------------------------------
float ofxTimerEventsCore::getCurrentTime() {
    
    return currentTime;
    
}


