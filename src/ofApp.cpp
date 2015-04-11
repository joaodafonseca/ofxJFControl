#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(20);
    ofEnableAntiAliasing();
    
    slider = ofxJFSlider("slider 1", 0, 300, 5, 10, 260, 48);
    slider2 = ofxJFSlider("slider 2", 0, 300, 5, 58, 260, 48);
    slider3 = ofxJFSlider("slider 2", 0, 300, 5, 106, 260, 48);
    
   
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    slider.update();
    slider2.update();
    slider3.update();
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(42, 48, 67);
    
    slider.drawController();
    slider2.drawController();
    slider3.drawController();

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
