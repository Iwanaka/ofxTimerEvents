#pragma once
#include "ofxTimerEventsCore.h"

namespace ofxTE {

	class ofxTimerEvents : public ofxTimerEventsCore
	{
	public:

		ofxTimerEvents();
		~ofxTimerEvents();

		void setEvents(int argnum, ...);
		void addEvents(int argnum, ...);

		void reload();
		void clear();

		int getEventSize();
		bool getNextEvent();


	private:

		std::vector<float> flagTimes, _flagTimes;

	};
}