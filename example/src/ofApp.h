#pragma once

#include "ofMain.h"
#include "ofxTimerEventTable.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);

		ofxTE::ofxTimerEventsCore core;
		ofxTE::ofxTimerEvents events;
		ofxTE::ofxTimerEventTable table;
		
};
