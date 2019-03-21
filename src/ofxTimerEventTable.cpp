#include "ofxTimerEventTable.h"

using namespace ofxTE;

Event ofxTE::newEvent(int argnum, ...) {

	auto n = make_shared<ofxTimerEvents>();
	va_list args;
	va_start(args, argnum);

	for (int i = 0; i < argnum; i++) {

		double _time = va_arg(args, double);

		n->addEvents(1, _time);

	}
	va_end(args);

	return n;

}

//--------------------------------------------------------------
ofxTimerEventTable::ofxTimerEventTable(){}

//--------------------------------------------------------------
ofxTimerEventTable::~ofxTimerEventTable(){}

//--------------------------------------------------------------
void ofxTimerEventTable::addEventTimer(shared_ptr<ofxTimerEvents> e) {
	
	Events.push_back(e);

}

//--------------------------------------------------------------
void ofxTimerEventTable::addEventTimer(int argnum, ...) {

	Event temp = make_shared<ofxTimerEvents>();
	
	va_list args;
	va_start(args, argnum);
	
	for (int i = 0; i < argnum; i++) {
        
		double _time = va_arg(args, double);
        
		temp->addEvents(1, _time);
	
    }
	va_end(args);

	Events.push_back(temp);

}

//--------------------------------------------------------------
void ofxTimerEventTable::start(int index) {
	for (int i = 0; i < Events.size(); i++) {
		if (i == index) {
			Events[i]->start();
			break;
		}
	}
}

//--------------------------------------------------------------
void ofxTimerEventTable::pause(int index) {
    for (int i = 0; i < Events.size(); i++) {
		if (i == index) {
			Events[i]->pause();
			break;
		}
	}
}

//--------------------------------------------------------------
void ofxTimerEventTable::reset(int index) {
    for (int i = 0; i < Events.size(); i++) {
		if (i == index) {
			Events[i]->reset();
			break;
		}
	}
}

//--------------------------------------------------------------
void ofxTimerEventTable::flagReload(int index) {
    for (int i = 0; i < Events.size(); i++) {
		if (i == index) {
			Events[i]->reload();
			break;
		}
    }
}

//--------------------------------------------------------------
void ofxTimerEventTable::startAll() {
    for (int i = 0; i < Events.size(); i++) {	
		Events[i]->start();
	}
}

//--------------------------------------------------------------
void ofxTimerEventTable::pauseAll() {
    for (int i = 0; i < Events.size(); i++) {
		Events[i]->pause();
	}
}

//--------------------------------------------------------------
void ofxTimerEventTable::resetAll() {
    for (int i = 0; i < Events.size(); i++) {
		Events[i]->reset();
	}
}

//--------------------------------------------------------------
void ofxTimerEventTable::reloadAll() {
    for (int i = 0; i < Events.size(); i++) {
		Events[i]->reload();
    }
}

//--------------------------------------------------------------
bool ofxTimerEventTable::getNextEvent(int index) {
	
    for (int i = 0; i < Events.size(); i++) {
        if (i == index) {
			if (Events[i]->getNextEvent()) return true;
		}
	}
   
	return false;

}

//--------------------------------------------------------------
float ofxTimerEventTable::getCurrentTime(int index){
    
    for(int i = 0; i < Events.size(); i++){
        if(i == index){
            return Events[i]->getCurrentTime();
        }
    }
    
}

//--------------------------------------------------------------
int ofxTimerEventTable::getEventSize(int index) {
	
    for (int i = 0; i < Events.size(); i++) {
        if (i == index) {
            return Events[i]->getEventSize();
        }
	}
    
	return 0;
}

//--------------------------------------------------------------
int ofxTimerEventTable::getSize() {
    return Events.size();
}


