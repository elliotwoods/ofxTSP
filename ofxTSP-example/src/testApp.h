#pragma once

#include "ofMain.h"

#include "ofxTSP.h"

#define COUNT 7
#define WIDTH 1024
using namespace ofxTSP;

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void solve();

	vector<ofVec2f> positions;

	ofxTSP::Problem problem;
	ofxTSP::BruteForce solver;
	vector<int> solvedRoute;
};
