#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(100);
	ofSetLogLevel(OF_LOG_NOTICE);

	solve();
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(200);
	ofNoFill();
	ofEnableSmoothing();
	ofSetLineWidth(1.0f);
	ofBeginShape();
	ofVec2f position;
	for (int i=0; i<solvedRoute.size(); i++) {
		position = positions[solvedRoute[i]];
		ofVertex(position.x, position.y);
		ofCircle(position.x, position.y, 10);
		ofDrawBitmapString(ofToString(solvedRoute[i]), position.x, position.y);
	}
	ofEndShape(false);

	ofSetColor(255);
	ofDrawBitmapString("[SPACE] to re-solve", 10, 10);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == ' ')
		solve();
}

//--------------------------------------------------------------
void testApp::solve() {

	for (int i=0; i<COUNT; i++)
		positions.push_back(ofVec2f(ofRandom(WIDTH), ofRandom(WIDTH)));

	float length;
	for (int i=0; i<COUNT; i++) {
		for (int j=i+1; j<COUNT; j++) {
			length = (positions[i] - positions[j]).length();
			problem.addJourneyCost(i, j, length);
			cout << "Insert journey " << i << " to " << j << " with distance " << length;

			Journey journey(i, j);
			cout << " [" << journey.asInt32() << "]" << endl;
		}
	}

	problem.nodeCount = COUNT;

	cout << "solving..." << endl;
	this->solvedRoute = solver.solve(problem);
	cout << "done." << endl;

	cout << "Route : " << this->solvedRoute << endl;
}
