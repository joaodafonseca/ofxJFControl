#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(20);
    ofEnableAntiAliasing();
    
    slider = ofxJFSlider("slider 1", 0, 300, 10, 10, 260, 50);
    slider2 = ofxJFSlider("slider 2", 0, 300, 10, 60, 260, 50);
    slider3 = ofxJFSlider("slider 2", 0, 300, 10, 110, 260, 50);
    
   
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    slider.update();
    slider2.update();
    slider3.update();
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    
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
