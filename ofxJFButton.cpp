//
//  ofxJFBotton.cpp
//  jfGui
//
//  Created by João Fonseca on 06/04/15.
//
//

#include "ofxJFButton.h"

ofxJFButton::ofxJFButton(){
    
    enableMouseEvents();
    
}

ofxJFButton::ofxJFButton(string _name, int _x, int _y, int _width, int _height){
    
    name=_name;
    size.set(_width, _height);
    location.set(_x+(size.x/3), _y);
    totalHeight=size.y;
    
    addLabel(name, ofPoint(location.x-(size.x/3),location.y+(size.y/2)));
    setEventArea(location, size);
    enableMouseEvents();
    
    value=0;
    
    
    state.setAlignment(JF_CENTER);
    
    widgetChangedSize=false;
    isMaximized=false;
    initialLocation=location;
}

void ofxJFButton::update(){
    
}

void ofxJFButton::setLocation(ofPoint _location){
    
    location=_location;
    setEventArea(location, size);
    setLPosition(ofPoint(location.x,location.y+(size.y/2)));
    state.setLPosition(location+(size/2));
    
}


void ofxJFButton::setLabelPosition(ofPoint _labelLocation){
    
    
    setLPosition(_labelLocation);
    
}

void ofxJFButton::drawController(){
    
    ofPushStyle();
    ofSetColor(PANEL_COLOR);
    ofRectRounded(location.x, location.y, size.x, size.y,5);
    ofSetColor(255);
    ofRectRounded(location.x, location.y, size.x*value, size.y,5);
    
    ofNoFill();
    ofSetColor(0);
    ofRectRounded(location.x, location.y, size.x, size.y,5);
    
    drawLabel();
    state.drawLabel();
    ofPopStyle();
    
}


ofPoint ofxJFButton::getLocation(){
    
    return location;
}


void ofxJFButton::mousePressed(int x, int y, int button){
    updateValue=true;
    value=!value;
    state.setLabel(value? "on" : "off");
    
}

void ofxJFButton::mouseReleased(int x, int y, int button){
    updateValue=false;
}
