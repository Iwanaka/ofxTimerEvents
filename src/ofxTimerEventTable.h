#pragma once
#include "ofxTimerEvents.h"

using namespace std;

namespace ofxTE {

	typedef shared_ptr<ofxTimerEvents> Event;
	Event newEvent(int argnum, ...);

	class ofxTimerEventTable
	{
	public:

		ofxTimerEventTable();
		~ofxTimerEventTable();

		void addEventTimer(shared_ptr<ofxTimerEvents> e);
		void addEventTimer(int argnum, ...);

		void start(int index);
		void pause(int index);
		void reset(int index);
		void flagReload(int index);

		void startAll();
		void pauseAll();
		void resetAll();
		void reloadAll();


		bool getNextEvent(int index);
		float getCurrentTime(int index);
		int getEventSize(int index);

		int getSize();

	private:

		vector<Event> Events;

	};
}