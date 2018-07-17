#pragma once
#include "ofMain.h"
#include "TimeMeasurement.h"

class TimeSettingFlag : public TimeMeasurement
{
public:
    
    TimeSettingFlag();
    ~TimeSettingFlag();

    void setFlagTimes(int argnum, ...);
    void addFlagTimes(int argnum, ...);
    
    void flagReload();
    void flagClear();
    
    int getFlagSize();
    bool getNextFlag();
    
    
private:

	vector<float> flagTimes, _flagTimes;

};
