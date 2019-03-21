#pragma once
#include "ofThread.h"
#include "ofTimer.h"

namespace ofxTE {

	class ofxTimerEventsCore : public ofThread
	{
	public:

		ofxTimerEventsCore();
		~ofxTimerEventsCore();

		void start();
		void pause();
		void reset();

		void threadedFunction();

		float getCurrentTime();


	protected:

		float currentTime;
		float beforeTime;
		float tempTime;

		bool isRunning;

	};

}
