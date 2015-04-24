#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(20);
    ofEnableAntiAliasing();
    
    variable=30;
    multiPoint.set(20,50,200);
    multivec.set(20,50,200);
    
    panel = ofxJFControlPanel("ofxJFPanel", 10, 10, 280);
    
    panel.createGroup("Controls 1");
    panel.addSlider("slider1", variable, 0, 550);
    panel.addSlider("slider2", 0, 550);
    panel.addSlider("slider3", 0, 550);
    panel.addSlider("slider4", 0, 550);
    
    panel.createGroup("Controls 2");
    panel.addSlider("slider1", 0, 550);
    panel.addMultiSlider("multi slider", multiPoint, 0, 200);
    panel.addMultiSlider("multi slider", multivec, 0, 200);
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

    
    
    
    panel2 = ofxJFControlPanel("ofxJFPanel 2", 300, 10, 280);
    
    panel2.createGroup("Controls 1");
    panel2.addSlider("slider1", 0, 550);
    panel2.addSlider("slider2", 0, 550);
    panel2.addSlider("slider3", 0, 550);
    panel2.addSlider("slider4", 0, 550);
    
    panel2.createGroup("Controls 2");
    panel2.addSlider("slider1", 0, 550);
    panel2.addMultiSlider("multi slider", 0, 200);
    panel2.addMultiSlider("multi slider", 0, 200);
    panel2.addSlider("slider3", 0, 550);
    panel2.addSlider("slider4", 0, 550);
    
    panel2.createGroup("Controls 3");
    panel2.addSlider("slider1", 0, 550);
    panel2.addSlider("slider1", 0, 550);
    
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
    //float &temp=float(10);
    
    //pointer=&variable;
    
    //pointer=&variable;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 1));
    
    panel.update();
    panel2.update();
    
    //cout<<multivec<<endl;
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(80);
    
    panel.drawController();
    panel2.drawController();
    
    // *pointer=ofGetMouseX();

 
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
