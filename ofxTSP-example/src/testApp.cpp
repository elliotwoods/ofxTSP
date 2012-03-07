#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(100);
	for (int i=0; i<COUNT; i++)
		positions.push_back(ofVec2f(ofRandom(512), ofRandom(512)));

	Journey journey;
	float length;
	for (int i=0; i<COUNT; i++) {
		for (int j=i+1; j<COUNT; j++) {
			journey = Journey(i, j);
			length = (positions[i] - positions[j]).length();
			problem.distance.insert(pair<Journey, float>(journey, length));
			cout << "Insert journey " << i << " to " << j << " with distance " << length << endl;
		}
	}

	cout << "solving..." << endl;

	problem.destinationCount = COUNT;

	this->solvedRoute = solver.solve(problem);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	for (int i=0; i<COUNT; i++) {
		ofCircle(positions[i].x, positions[i].y, 20);
	}

	ofNoFill();
	ofEnableSmoothing();
	ofSetLineWidth(2.0f);
	ofBeginShape();
	ofVec2f position;
	for (int i=0; i<solvedRoute.size(); i++) {
		position = positions[solvedRoute[i]];
		ofVertex(position.x, position.y);
	}
	ofEndShape(false);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}
