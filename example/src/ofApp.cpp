#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);

	//set arg size and event fire time
	events.addEvents(3, 1.0, 2.0, 3.0);

	table.addEventTimer(3, 1.0, 2.0, 3.0);
	table.addEventTimer(3, 1.5, 2.5, 3.5);
	table.addEventTimer(3, 2.0, 3.0, 4.0);

	table.addEventTimer(ofxTE::newEvent(3, 1.0, 2.0, 3.0));

}

//--------------------------------------------------------------
void ofApp::update(){

	if (events.getNextEvent()) cout << "ofxTimerEvents Fire" << endl;

	if (table.getNextEvent(0)) cout << "ofxTimerEventTable id:0 Fire" << endl;
	if (table.getNextEvent(1)) cout << "ofxTimerEventTable id:1 Fire" << endl;
	if (table.getNextEvent(2)) cout << "ofxTimerEventTable id:2 Fire" << endl;
	if (table.getNextEvent(3)) cout << "ofxTimerEventTable id:3 Fire" << endl;

}

//--------------------------------------------------------------
void ofApp::draw(){

	int x = 30, y = 30;
	ofDrawBitmapString("core    : " + ofToString(core.getCurrentTime()), x, y);
	ofDrawBitmapString("events  : " + ofToString(events.getCurrentTime()), x, y + 20);
	ofDrawBitmapString("table 0 : " + ofToString(table.getCurrentTime(0)), x, y + 40);
	ofDrawBitmapString("table 1 : " + ofToString(table.getCurrentTime(1)), x, y + 60);
	ofDrawBitmapString("table 2 : " + ofToString(table.getCurrentTime(2)), x, y + 80);
	ofDrawBitmapString("table 3 : " + ofToString(table.getCurrentTime(3)), x, y + 100);

}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	//timer start
	if (key == 's') {
		core.start();
		events.start();
		table.startAll();
	}

	//timer pause
	if (key == 'p') {
		core.pause();
		events.pause();
		table.pauseAll();
	}

	//timer reset
	if (key == 'r') {
		core.reset();
		events.reset();//only timer reset
		events.reload();// event reload
		table.resetAll();
		table.reloadAll();
	}
}
