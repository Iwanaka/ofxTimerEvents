//
//  TimeFlagSetting.cpp
//  ofxTimeController
//
//  Created by Hiromitsu Iwanaka on 2018/05/18.
//

#include "TimeSettingFlag.h"

//--------------------------------------------------------------
TimeSettingFlag::TimeSettingFlag() :
flagTimes(0),
_flagTimes(0)
{
}

//--------------------------------------------------------------
TimeSettingFlag::~TimeSettingFlag(){
    
}

//--------------------------------------------------------------
void TimeSettingFlag::setFlagTimes(int argnum, ...){
    
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
void TimeSettingFlag::addFlagTimes(int argnum, ...) {
    
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
int TimeSettingFlag::getFlagSize() {
    
    return flagTimes.size();
    
}

//--------------------------------------------------------------
void TimeSettingFlag::flagReload(){
    
    _flagTimes = flagTimes;
    
}

//--------------------------------------------------------------
void TimeSettingFlag::flagClear() {
    
    flagTimes.clear();
    flagReload();
    
}

//--------------------------------------------------------------
bool TimeSettingFlag::getNextFlag() {
    
    for (int i = 0; i < _flagTimes.size(); i++) {
        
        if (getCurrentTime() >= _flagTimes[i]) {
            
            _flagTimes.erase(_flagTimes.begin() + i);
            
            return true;
        
        }
    }
    
    return false;
}




