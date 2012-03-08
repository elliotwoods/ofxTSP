#pragma once

#include "ofMain.h"

#include "ofxTSP.h"

#define COUNT 7
#define WIDTH 600
using namespace ofxTSP;

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void solve();
	void defineJourneys();
	void solve(int routeTo);

	vector<ofVec2f> positions;

	ofxTSP::Problem problem;
	vector<vector<int> > solvedRoutes;
};
