//
//  ofxJFMultiSlider.cpp
//  ofxJFControl
//
//  Created by João Fonseca on 11/04/15.
//
//

#include "ofxJFMultiSlider.h"


ofxJFMultiSlider::ofxJFMultiSlider(){
    enableMouseEvents();
}

ofxJFMultiSlider::ofxJFMultiSlider(string _name, float _min, float _max, int _x, int _y, int _width, int _height){
    
    name=_name;
    
    value=ofRandom(1);
    min=_min;
    max=_max;
    
    location.set(_x, _y);
    
    size.set(_width, _height/1.5);
    
    setEventArea(location, size);
    enableMouseEvents();
    sliders.clear();
    panelColor = PANEL_COLOR;
    backgroundColor = SLIDER_BACKGROUND_COLOR;
    
    
    sliderPositionY=location.y+size.y;
    sliderHeight=_height;
    
    sliderOffsetX=10;
    
    addLabel(name, ofPoint(location.x+sliderOffsetX,location.y+size.y/2));
    
    //for 3 sliders
    sliders.push_back(new ofxJFSlider("x", min, max, location.x,sliderPositionY+(0*sliderHeight),size.x,sliderHeight));
    sliders.push_back(new ofxJFSlider("y", min, max, location.x,sliderPositionY+(1*sliderHeight),size.x,sliderHeight));
    sliders.push_back(new ofxJFSlider("z", min, max, location.x,sliderPositionY+(2*sliderHeight),size.x,sliderHeight));
    
    totalHeight=size.y+(sliders.size()*sliderHeight);
    
    isMaximized=false;
    maximize=false;
    minimize=false;
    
}

void ofxJFMultiSlider::update(){
    
    for (int i = 0; i< sliders.size(); i++) {
        sliders[i]->update();
    }
    
    maximize=false;
    minimize=false;
}

void ofxJFMultiSlider::drawController(){
    ofPushStyle();
    
    
    
    if(isMaximized){
        
        ofSetColor(backgroundColor);
        ofRect(location.x,location.y, size.x, size.y);
        
        for (int i = 0; i< sliders.size(); i++) {
            sliders[i]->drawController();
        }
        
        ofSetColor(panelColor);
        ofLine(location.x, location.y, location.x+size.x, location.y);
        ofLine(location.x, location.y+totalHeight-1, location.x+size.x, location.y+totalHeight-1);

    }else{
        
        ofSetColor(panelColor);
        ofRect(location.x,location.y, size.x, size.y);
        
        
    }
    drawLabel();
    ofPopStyle();
}

void ofxJFMultiSlider::setValue(float _value){
    
}

void ofxJFMultiSlider::setLabelPosition(ofPoint _labelLocation){
    
}

void ofxJFMultiSlider::setLocation(ofPoint _location){
    
    location=_location;
    sliderPositionY=location.y+size.y;
    for(int i =0; i< sliders.size();i++){
        sliders[i]->setLocation(ofPoint(location.x,sliderPositionY+(i*sliderHeight)));
    
    }
    setEventArea(location, size);
    setLPosition(ofPoint(location.x+sliderOffsetX,location.y+size.y/2));

    
}

void ofxJFMultiSlider::showLabel(bool status){
    
}

float ofxJFMultiSlider::getValue(){
    
}

void ofxJFMultiSlider::mousePressed(int x, int y, int button){
    
    isMaximized=!isMaximized;
    
    if(isMaximized){
        maximize=true;
        
        
        for (int i = 0; i< sliders.size(); i++) {
            sliders[i]->enableMouseEvents();
        }

    }else{
        minimize=true;
        
        for (int i = 0; i< sliders.size(); i++) {
            sliders[i]->disableMouseEvents();
        }
        
    }
    
    
}

void ofxJFMultiSlider::mouseDragged(int x, int y, int button){
    
}

void ofxJFMultiSlider::mouseReleased(int x, int y, int button){
    
}