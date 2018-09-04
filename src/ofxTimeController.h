#pragma once
#include "ofMain.h"
#include "ofxTimeSettingFlag.h"

class ofxTimeController
{
public:
    
	ofxTimeController();
	~ofxTimeController();


	void addTimeData(string index);
	void addTimeSettingFlag(string index, int argnum, ...);

	void start(string index);
	void pause(string index);
	void reset(string index);
    void flagReload(string index);
    
	void startAll();
	void pauseAll();
	void resetAll();
    void flagReloadAll();
    

	bool getNextFlag(string index);
    float getCurrentTime(string index);
    int getFlagSize(string index);
    
	int getTotalTimeSize();
	float getTotalTime();

private:

	typedef struct
	{
		string index;
		ofxTimeSettingFlag time;
        
	}timeFlag;

	vector<shared_ptr<timeFlag>> times;

};
