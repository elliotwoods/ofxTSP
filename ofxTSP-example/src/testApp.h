#pragma once

#include "ofMain.h"

#include "ofxTSP.h"

#define COUNT 10

using namespace ofxTSP;

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void drawSelection();
	
	void keyPressed  (int key);

	vector<ofVec2f> positions;

	ofxTSP::Problem problem;
	ofxTSP::BruteForce solver;
	vector<int> solvedRoute;
};
