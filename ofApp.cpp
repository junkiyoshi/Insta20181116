#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofNoFill();
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int i = 0; i < 50; i++) {

		ofColor color;
		color.setHsb(ofRandom(255), 255, 230);
		ofSetColor(color);

		ofPoint point = ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
		this->draw_star(point, ofRandom(20, 60));
	}
}

//--------------------------------------------------------------
void ofApp::draw_star(ofPoint location, float radius) {

	ofPushMatrix();
	ofTranslate(location);

	ofRotate(ofRandom(360));

	int count = 0;
	vector<ofPoint> vertices;

	for (int deg = 0; deg < 720 * 5; deg += 72 * 2) {

		ofPoint point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		ofPoint noisy_gap = ofPoint(ofMap(ofNoise(ofRandom(100), ofGetFrameNum() * 0.03), 0, 1, -radius * 0.15, radius * 0.15), ofMap(ofNoise(ofRandom(100), ofGetFrameNum() * 0.03), 0, 1, -radius * 0.15, radius * 0.15));
		vertices.push_back(point + noisy_gap);
	}

	ofBeginShape();
	ofVertices(vertices);
	ofEndShape(true);

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}