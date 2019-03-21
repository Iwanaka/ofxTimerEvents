//
//  ofxTimerEvents.cpp
//  ofxTimerEvents
//
//  Created by Hiromitsu Iwanaka on 2018/05/18.
//

#include "ofxTimerEvents.h"

using namespace ofxTE;
//--------------------------------------------------------------
ofxTimerEvents::ofxTimerEvents() :
	flagTimes(0),
	_flagTimes(0)
{}

//--------------------------------------------------------------
ofxTimerEvents::~ofxTimerEvents(){
    
}

//--------------------------------------------------------------
void ofxTimerEvents::setEvents(int argnum, ...){
    
    clear();
    
    va_list args;
    va_start(args, argnum);
    
    for (int i = 0; i < argnum; i++) {
    
        double _time = va_arg(args, double);
        
        if (_time >= 0.0) flagTimes.push_back(_time);
        
    }
    
    va_end(args);
    
    _flagTimes = flagTimes;
    
}

//--------------------------------------------------------------
void ofxTimerEvents::addEvents(int argnum, ...) {
    
    va_list args;
    va_start(args, argnum);
    
    for (int i = 0; i < argnum; i++) {
        
        double _time = va_arg(args, double);
        
        if(_time >= 0.0) flagTimes.push_back(_time);
    
    }
    
    va_end(args);
    
    _flagTimes = flagTimes;
    
}

//--------------------------------------------------------------
void ofxTimerEvents::reload(){
    
    _flagTimes = flagTimes;
    
}

//--------------------------------------------------------------
void ofxTimerEvents::clear() {
    
    flagTimes.clear();
    reload();
    
}

//--------------------------------------------------------------
int ofxTimerEvents::getEventSize() {

	return flagTimes.size();

}

//--------------------------------------------------------------
bool ofxTimerEvents::getNextEvent() {
    
    for (int i = 0; i < _flagTimes.size(); i++) {  
        if (getCurrentTime() >= _flagTimes[i]) {
            _flagTimes.erase(_flagTimes.begin() + i);
            return true;
        }
    }
    
    return false;
}




