#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(20);
    ofEnableAntiAliasing();
    
    
    cg = ofxJFControlGroup("group", 10, 10, 260);
    cg.addSlider("slider 1", 0,100);
    cg.addSlider("slider 2", 0,100);
    cg.addMultiSlider("multi 1", 0, 100);
    cg.addSlider("slider 3", 0,100);
       cg.addSlider("slider 3", 0,100);
    cg.addSlider("slider 1", 0,100);
    cg.addSlider("slider 2", 0,100);
    cg.addMultiSlider("multi 1", 0, 100);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    cg.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    cg.drawController();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
