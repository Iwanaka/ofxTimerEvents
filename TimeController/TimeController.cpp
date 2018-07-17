#include "TimeController.h"

//--------------------------------------------------------------
TimeController::TimeController()
{
}

//--------------------------------------------------------------
TimeController::~TimeController()
{
}

//--------------------------------------------------------------
void TimeController::addTimeData(string index) {

	shared_ptr<timeFlag> temp = shared_ptr<timeFlag>(new timeFlag);
	temp->index = index;

	times.push_back(temp);

}

//--------------------------------------------------------------
void TimeController::addTimeSettingFlag(string index, int argnum, ...) {

	shared_ptr<timeFlag> temp = shared_ptr<timeFlag>(new timeFlag);
	
    temp->index = index;
	
	va_list args;
	va_start(args, argnum);
	
	for (int i = 0; i < argnum; i++) {
        
		double _time = va_arg(args, double);
        
		temp->time.addFlagTimes(1, _time);
	
    }
	va_end(args);

	times.push_back(temp);
}

//--------------------------------------------------------------
void TimeController::start(string index) {
    
	for (int i = 0; i < times.size(); i++) {
		
		if (times[i]->index == index) times[i]->time.start();
		
	}
    
}

//--------------------------------------------------------------
void TimeController::pause(string index) {
	
    for (int i = 0; i < times.size(); i++) {
		
		if (times[i]->index == index) times[i]->time.pause();
		
	}
    
}

//--------------------------------------------------------------
void TimeController::reset(string index) {
	
    for (int i = 0; i < times.size(); i++) {
	
		if (times[i]->index == index) times[i]->time.reset();
		
	}
    
}

//--------------------------------------------------------------
void TimeController::flagReload(string index) {
    
    for (int i = 0; i < times.size(); i++) {
        
        if (times[i]->index == index) times[i]->time.flagReload();
        
    }
    
}

//--------------------------------------------------------------
void TimeController::startAll() {
	
    for (int i = 0; i < times.size(); i++) {
	
        times[i]->time.start();
	}
    
}

//--------------------------------------------------------------
void TimeController::pauseAll() {
	
    for (int i = 0; i < times.size(); i++) {
	
        times[i]->time.pause();
	}
    
}

//--------------------------------------------------------------
void TimeController::resetAll() {
	
    for (int i = 0; i < times.size(); i++) {
	
        times[i]->time.reset();
	}
    
}

//--------------------------------------------------------------
void TimeController::flagReloadAll() {
    
    for (int i = 0; i < times.size(); i++) {
        
        times[i]->time.flagReload();
    }
    
}

//--------------------------------------------------------------
bool TimeController::getNextFlag(string index) {
	
    for (int i = 0; i < times.size(); i++) {
	
        if (times[i]->index == index) {

			if (times[i]->time.getNextFlag()) return true;
			
		}
        
	}
    
	return false;

}

//--------------------------------------------------------------
float TimeController::getCurrentTime(string index){
    
    for(int i = 0; i < times.size(); i++){
        
        if(times[i]->index == index){
            
            return times[i]->time.getCurrentTime();
            
        }
        
    }
    
}

//--------------------------------------------------------------
int TimeController::getFlagSize(string index) {
	
    for (int i = 0; i < times.size(); i++) {
	
        if (times[i]->index == index) {
		
            return times[i]->time.getFlagSize();
		
        }
        
	}
    
	return 0;
}

//--------------------------------------------------------------
int TimeController::getTotalTimeSize() {
    
    return times.size();
    
}

//--------------------------------------------------------------
float TimeController::getTotalTime() {
	
	float temp = 0.0;
    
	for (int i = 0; i < times.size(); i++) {
	
        temp += times[i]->time.getCurrentTime();

    }
    
	return temp;

}


