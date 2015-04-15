#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(20);
    ofEnableAntiAliasing();
    
    
    panel = ofxJFControlPanel("ofxJFPanel", 10, 10, 280);
    
    panel.addGroup("Controls 1");
    panel.addSlider("SLIDER1", 0, 550);
    panel.addSlider("SLIDER2", 0, 550);
    panel.addSlider("SLIDER3", 0, 550);
    panel.addSlider("SLIDER4", 0, 550);
    
    panel.addGroup("Controls 2");
    panel.addSlider("SLIDER1", 0, 550);
    panel.addSlider("SLIDER2", 0, 550);
    panel.addSlider("SLIDER3", 0, 550);
    panel.addSlider("SLIDER4", 0, 550);
    
    panel.addGroup("Controls 3");
    panel.addSlider("SLIDER1", 0, 550);
    panel.addSlider("SLIDER2", 0, 550);
    panel.addSlider("SLIDER3", 0, 550);
    panel.addSlider("SLIDER4", 0, 550);
    
    
    /*
     cg = ofxJFControlGroup("group", 10, 10, 260);
     cg.addSlider("slider 1", 0,100);
     cg.addSlider("slider 2", 0,100);
     cg.addMultiSlider("multi 1", 0, 100);
     cg.addSlider("slider 3", 0,100);
     cg.addSlider("slider 3", 0,100);
     cg.addSlider("slider 1", 0,100);
     cg.addSlider("slider 2", 0,100);
     cg.addMultiSlider("multi 1", 0, 100);
     cg.addSlider("slider 1", 0,100);
     cg.addSlider("slider 2", 0,100);
     */
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 1));
    panel.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    panel.drawController();
    
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
