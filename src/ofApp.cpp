#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(20);
    ofEnableAntiAliasing();
    
    
    panel = ofxJFControlPanel("ofxJFPanel", 10, 10, 280);
    
    panel.createGroup("Controls 1");
    panel.addSlider("slider1", 0, 550);
    panel.addSlider("slider2", 0, 550);
    panel.addSlider("slider3", 0, 550);
    panel.addSlider("slider4", 0, 550);
    
    panel.createGroup("Controls 2");
    panel.addSlider("slider1", 0, 550);
    panel.addMultiSlider("multi slider", 0, 200);
    panel.addMultiSlider("multi slider", 0, 200);
    panel.addSlider("slider3", 0, 550);
    panel.addSlider("slider4", 0, 550);
    
    panel.createGroup("Controls 3");
    panel.addSlider("slider1", 0, 550);
    panel.addSlider("slider1", 0, 550);
    panel.addSlider("slider1", 0, 550);
    panel.addSlider("SLIDER4", 0, 550);
    
    panel.createGroup("Controls 4");
    panel.addSlider("slider1", 0, 550);
    panel.addSlider("slider1", 0, 550);
    panel.addMultiSlider("multi slider1", 0, 200);
    panel.addSlider("slider1", 0, 550);
    panel.addSlider("slider1", 0, 550);
    
    panel.createGroup("Controls 5");
    panel.addSlider("slider1", 0, 550);
    panel.addMultiSlider("multi slider1", 0, 200);
    panel.addSlider("slider1", 0, 550);
    panel.addSlider("slider1", 0, 550);

    
    
    /*
     cg = ofxJFControlGroup("group", 300, 10, 260);
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
    cg.addSlider("slider 2", 0,100);
    cg.addMultiSlider("multi 1", 0, 100);
    cg.addSlider("slider 1", 0,100);
    cg.addSlider("slider 2", 0,100);
    cg.addMultiSlider("multi 1", 0, 100);
    cg.addSlider("slider 1", 0,100);
    cg.addSlider("slider 2", 0,100);
    cg.addSlider("slider 2", 0,100);
    
    */
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 1));
    panel.update();
    cg.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(80);
    
    panel.drawController();
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
