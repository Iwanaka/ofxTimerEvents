//
//  TimeFlagSetting.cpp
//  ofxTimeController
//
//  Created by Hiromitsu Iwanaka on 2018/05/18.
//

#include "ofxTimeSettingFlag.h"

//--------------------------------------------------------------
ofxTimeSettingFlag::ofxTimeSettingFlag() :
flagTimes(0),
_flagTimes(0)
{
}

//--------------------------------------------------------------
ofxTimeSettingFlag::~ofxTimeSettingFlag(){
    
}

//--------------------------------------------------------------
void ofxTimeSettingFlag::setFlagTimes(int argnum, ...){
    
    flagClear();
    
    va_list args;
    va_start(args, argnum);
    
    for (int i = 0; i < argnum; i++) {
    
        double _time = va_arg(args, double);
        
        if (_time > 0.0001) flagTimes.push_back(_time);
        
    }
    
    va_end(args);
    
    _flagTimes = flagTimes;
    
}

//--------------------------------------------------------------
void ofxTimeSettingFlag::addFlagTimes(int argnum, ...) {
    
    va_list args;
    va_start(args, argnum);
    
    for (int i = 0; i < argnum; i++) {
        
        double _time = va_arg(args, double);
        
        if(_time > 0.0001) flagTimes.push_back(_time);
    
    }
    
    va_end(args);
    
    _flagTimes = flagTimes;
    
}

//--------------------------------------------------------------
int ofxTimeSettingFlag::getFlagSize() {
    
    return flagTimes.size();
    
}

//--------------------------------------------------------------
void ofxTimeSettingFlag::flagReload(){
    
    _flagTimes = flagTimes;
    
}

//--------------------------------------------------------------
void ofxTimeSettingFlag::flagClear() {
    
    flagTimes.clear();
    flagReload();
    
}

//--------------------------------------------------------------
bool ofxTimeSettingFlag::getNextFlag() {
    
    for (int i = 0; i < _flagTimes.size(); i++) {
        
        if (getCurrentTime() >= _flagTimes[i]) {
            
            _flagTimes.erase(_flagTimes.begin() + i);
            
            return true;
        
        }
    }
    
    return false;
}




