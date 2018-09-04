#include "ofxTimeController.h"

//--------------------------------------------------------------
ofxTimeController::ofxTimeController()
{
}

//--------------------------------------------------------------
ofxTimeController::~ofxTimeController()
{
}

//--------------------------------------------------------------
void ofxTimeController::addTimeData(string index) {

	shared_ptr<timeFlag> temp = shared_ptr<timeFlag>(new timeFlag);
	temp->index = index;

	times.push_back(temp);

}

//--------------------------------------------------------------
void ofxTimeController::addTimeSettingFlag(string index, int argnum, ...) {

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
void ofxTimeController::start(string index) {
    
	for (int i = 0; i < times.size(); i++) {
		
		if (times[i]->index == index) times[i]->time.start();
		
	}
    
}

//--------------------------------------------------------------
void ofxTimeController::pause(string index) {
	
    for (int i = 0; i < times.size(); i++) {
		
		if (times[i]->index == index) times[i]->time.pause();
		
	}
    
}

//--------------------------------------------------------------
void ofxTimeController::reset(string index) {
	
    for (int i = 0; i < times.size(); i++) {
	
		if (times[i]->index == index) times[i]->time.reset();
		
	}
    
}

//--------------------------------------------------------------
void ofxTimeController::flagReload(string index) {
    
    for (int i = 0; i < times.size(); i++) {
        
        if (times[i]->index == index) times[i]->time.flagReload();
        
    }
    
}

//--------------------------------------------------------------
void ofxTimeController::startAll() {
	
    for (int i = 0; i < times.size(); i++) {
	
        times[i]->time.start();
	}
    
}

//--------------------------------------------------------------
void ofxTimeController::pauseAll() {
	
    for (int i = 0; i < times.size(); i++) {
	
        times[i]->time.pause();
	}
    
}

//--------------------------------------------------------------
void ofxTimeController::resetAll() {
	
    for (int i = 0; i < times.size(); i++) {
	
        times[i]->time.reset();
	}
    
}

//--------------------------------------------------------------
void ofxTimeController::flagReloadAll() {
    
    for (int i = 0; i < times.size(); i++) {
        
        times[i]->time.flagReload();
    }
    
}

//--------------------------------------------------------------
bool ofxTimeController::getNextFlag(string index) {
	
    for (int i = 0; i < times.size(); i++) {
	
        if (times[i]->index == index) {

			if (times[i]->time.getNextFlag()) return true;
			
		}
        
	}
    
	return false;

}

//--------------------------------------------------------------
float ofxTimeController::getCurrentTime(string index){
    
    for(int i = 0; i < times.size(); i++){
        
        if(times[i]->index == index){
            
            return times[i]->time.getCurrentTime();
            
        }
        
    }
    
}

//--------------------------------------------------------------
int ofxTimeController::getFlagSize(string index) {
	
    for (int i = 0; i < times.size(); i++) {
	
        if (times[i]->index == index) {
		
            return times[i]->time.getFlagSize();
		
        }
        
	}
    
	return 0;
}

//--------------------------------------------------------------
int ofxTimeController::getTotalTimeSize() {
    
    return times.size();
    
}

//--------------------------------------------------------------
float ofxTimeController::getTotalTime() {
	
	float temp = 0.0;
    
	for (int i = 0; i < times.size(); i++) {
	
        temp += times[i]->time.getCurrentTime();

    }
    
	return temp;

}


