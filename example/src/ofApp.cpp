#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    timerFlag.addFlagTimes(3,1.0,2.0,3.0);
    timerControll.addTimeData("test1");
    timerControll.addTimeData("test2");
    timerControll.addTimeData("test3");
    timerControll.addTimeSettingFlag("test4", 3,1.0,2.0,3.0);
    timerControll.addTimeSettingFlag("test5", 3,3.0,4.0,5.0);
}

//--------------------------------------------------------------
void ofApp::update(){

    if(timerFlag.getNextFlag()){
        ofLog() << "flag";
    }
    
    if(timerControll.getNextFlag("test4")){
        ofLog() << "test4";
    }
    
    if(timerControll.getNextFlag("test5")){
        ofLog() << "test5";
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofDrawBitmapString(ofToString(timer.getCurrentTime()), 10, 10);
    ofDrawBitmapString(ofToString(timerFlag.getCurrentTime()), 10, 30);
    ofDrawBitmapString(ofToString(timerControll.getCurrentTime("test1")), 10, 50);
    ofDrawBitmapString(ofToString(timerControll.getCurrentTime("test2")), 10, 70);
    ofDrawBitmapString(ofToString(timerControll.getCurrentTime("test3")), 10, 90);
    ofDrawBitmapString(ofToString(timerControll.getCurrentTime("test4")), 10, 110);
    ofDrawBitmapString(ofToString(timerControll.getCurrentTime("test5")), 10, 130);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 's'){
        timer.start();
        timerFlag.start();
        timerControll.startAll();
    }
    
    if(key == 'p'){
        timer.pause();
        timerFlag.pause();
        timerControll.pauseAll();
    }
    
    if(key == 'r'){
        timer.reset();
        timerFlag.reset();
        timerFlag.flagReload();
        timerControll.resetAll();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
