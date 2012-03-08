#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(100);
	ofSetLogLevel(OF_LOG_NOTICE);

	for (int i=0; i<COUNT; i++)
		positions.push_back(ofVec2f(ofRandom(WIDTH), ofRandom(WIDTH)));


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
	ofVec2f position;

	//draw nodes
	for (int i=0; i<positions.size(); i++) {
		position = positions[i];
		ofCircle(position.x, position.y, 10);
		ofDrawBitmapString(ofToString(i), position.x, position.y);
	}


	//draw routes
	ofColor col(200,100,100);

	for (int i=0; i<solvedRoutes.size(); i++) {
		col.setHue(float(i) / float(solvedRoutes.size()) * 360.0f);
		ofSetColor(col);
		ofBeginShape();
		for (int j=0; j<solvedRoutes[i].size(); j++) {
			position = positions[solvedRoutes[i][j]];
			ofVertex(position.x, position.y);
		}
		ofEndShape(false);
	}

	ofSetColor(255);
	ofDrawBitmapString("[SPACE] to re-solve", 10, 10);
	ofDrawBitmapString("Finding shortest routes from node 0 to all other nodes", 10, 25);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == ' ')
		solve();
}

//--------------------------------------------------------------
void testApp::solve() {
	this->defineJourneys();

	for (int i=1; i<COUNT; i++)
		this->solve(i);
}

//--------------------------------------------------------------
void testApp::defineJourneys() {
	float length;
	for (int i=0; i<COUNT; i++) {
		for (int j=i+1; j<COUNT; j++) {
			length = (positions[i] - positions[j]).length() + ofRandom(WIDTH); //add some abitrary cost to deny trivial solution
			problem.addJourneyCost(i, j, length);
			cout << "Insert journey " << i << " to " << j << " with distance " << length;

			Journey journey(i, j);
			cout << " [" << journey.asInt32() << "]" << endl;
		}
	}

	this->problem.nodeCount = COUNT;
}

//--------------------------------------------------------------
void testApp::solve(int routeTo) {
	ofxTSP::RouteFind routeFinder(0, routeTo);
	
	cout << "solving..." << endl;
	this->solvedRoutes.push_back(routeFinder.solve(problem));
	cout << "done." << endl;

	cout << "Route from 0 to " << routeTo << ": [";
	for (int i=0; i<this->solvedRoutes.back().size(); i++) {
		if (i != 0)
			cout << ", ";
		cout << this->solvedRoutes.back()[i];
	}
	cout << "], cost " << routeFinder.getCost() << endl;
}