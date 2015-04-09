//
//  ofxJFcontroller.cpp
//  jfGui
//
//  Created by João Fonseca on 03/04/15.
//
//

#include "ofxJFEvent.h"


//--------------------------------------------------------------
ofxJFEvent::ofxJFEvent(){
    
    //enableMouseEvents();
    //enableKeyEvents();
}

//--------------------------------------------------------------
ofxJFEvent::~ofxJFEvent() {
    disableMouseEvents();
    disableKeyEvents();
}

//--------------------------------------------------------------
void ofxJFEvent::setEventArea(ofPoint _location, ofVec2f _size){
    location = _location;
    size = _size;
}

//--------------------------------------------------------------
bool ofxJFEvent::hitTest(int tx, int ty) const {
    return ((tx > location.x) && (tx < location.x + size.x) && (ty > location.y) && (ty < location.y + size.y));
}

//--------------------------------------------------------------
void ofxJFEvent::enableMouseEvents() {
    ofAddListener(ofEvents().mousePressed, this, &ofxJFEvent::_mousePressed);
    ofAddListener(ofEvents().mouseMoved, this, &ofxJFEvent::_mouseMoved);
    ofAddListener(ofEvents().mouseDragged, this, &ofxJFEvent::_mouseDragged);
    ofAddListener(ofEvents().mouseReleased, this, &ofxJFEvent::_mouseReleased);
}

//--------------------------------------------------------------
void ofxJFEvent::disableMouseEvents() {
    ofRemoveListener(ofEvents().mousePressed, this, &ofxJFEvent::_mousePressed);
    ofRemoveListener(ofEvents().mouseMoved, this, &ofxJFEvent::_mouseMoved);
    ofRemoveListener(ofEvents().mouseDragged, this, &ofxJFEvent::_mouseDragged);
    ofRemoveListener(ofEvents().mouseReleased, this, &ofxJFEvent::_mouseReleased);
}

//--------------------------------------------------------------
void ofxJFEvent::enableKeyEvents() {
    ofAddListener(ofEvents().keyPressed, this, &ofxJFEvent::_keyPressed);
    ofAddListener(ofEvents().keyReleased, this, &ofxJFEvent::_keyReleased);
}

//--------------------------------------------------------------
void ofxJFEvent::disableKeyEvents() {
    ofRemoveListener(ofEvents().keyPressed, this, &ofxJFEvent::_keyPressed);
    ofRemoveListener(ofEvents().keyReleased, this, &ofxJFEvent::_keyReleased);
}


//--------------------------------------------------------------
bool ofxJFEvent::hitTest(int tx, int ty, int w, int h) const {
    return ((tx > location.x) && (tx < location.x + w) && (ty > location.y) && (ty < location.y + h));
}

//--------------------------------------------------------------
void ofxJFEvent::_mousePressed(ofMouseEventArgs &e) {
 
    if(hitTest(e.x, e.y)){
        mousePressed(e.x,  e.y, e.button);
        if(clickedTwice())doubleClick(e.x,  e.y, e.button);
    }
}

//--------------------------------------------------------------
void ofxJFEvent::_mouseMoved(ofMouseEventArgs &e) {
    mouseMoved( e.x,  e.y);
}

//--------------------------------------------------------------
void ofxJFEvent::_mouseDragged(ofMouseEventArgs &e) {
    mouseDragged( e.x,  e.y, e.button);
}

//--------------------------------------------------------------
void ofxJFEvent::_mouseReleased(ofMouseEventArgs &e) {
    mouseReleased(e.x, e.y, e.button);
}

//--------------------------------------------------------------
bool ofxJFEvent::clickedTwice(){
    
    //the moment in millisecond() of the current click
    float currentClick = ofGetElapsedTimeMillis();
    
    //the difference between the two clicks
    float clickDifference = currentClick - lastClick;
    
    //set lastClick equal to currentClick
    lastClick = currentClick;
    
    //maximum amount of time in milliseconds to be counted as a double-click
    float doubleClickSpeed = 250;
    
    if(clickDifference < doubleClickSpeed){
        return true;
    }
    else{
        return false;
    }
    
    
}

//--------------------------------------------------------------
void ofxJFEvent::_keyPressed(ofKeyEventArgs &e) {
    keyPressed(e.key);
}

//--------------------------------------------------------------
void ofxJFEvent::_keyReleased(ofKeyEventArgs &e) {
    keyReleased(e.key);
}
