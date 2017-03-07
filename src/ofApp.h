#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void BubbleSort();
        void CocktailSort();
        void SinghalSort();
        void IdkSort();
        void MergeSort();
    
    private:
        int n[1440];
        int length = 1440;
        int cycleCount = 0;
        int mergeCycles = 1;
};
