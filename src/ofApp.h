#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    private:
        int n[1440];
        int length = 1440;
        int cycleCount = 0;
};
