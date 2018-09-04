#pragma once
#include "ofMain.h"
#include "ofxTimeMeasurement.h"

class ofxTimeSettingFlag : public ofxTimeMeasurement
{
public:
    
    ofxTimeSettingFlag();
    ~ofxTimeSettingFlag();

    void setFlagTimes(int argnum, ...);
    void addFlagTimes(int argnum, ...);
    
    void flagReload();
    void flagClear();
    
    int getFlagSize();
    bool getNextFlag();
    
    
private:

	vector<float> flagTimes, _flagTimes;

};
