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
    
    //value=ofRandom(1);
    min=_min;
    max=_max;
    
    location.set(_x, _y);
    
    size.set(_width, _height/1.6);
    
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
    
    maximizedHeight=size.y+(sliders.size()*sliderHeight);
    
    totalHeight=size.y;

    widgetChangedSize=false;

    
    initialLocation=location;
    
}


ofxJFMultiSlider::ofxJFMultiSlider(string _name, ofPoint &_var, float _min, float _max, int _x, int _y, int _width, int _height){
    
    name=_name;
    
    //value=ofRandom(1);
    min=_min;
    max=_max;
    
    location.set(_x, _y);
    
    size.set(_width, _height/1.6);
    
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
    sliders.push_back(new ofxJFSlider("x", _var.x, min, max, location.x,sliderPositionY+(0*sliderHeight),size.x,sliderHeight));
    sliders.push_back(new ofxJFSlider("y", _var.y, min, max, location.x,sliderPositionY+(1*sliderHeight),size.x,sliderHeight));
    sliders.push_back(new ofxJFSlider("z", _var.z, min, max, location.x,sliderPositionY+(2*sliderHeight),size.x,sliderHeight));
    
    maximizedHeight=size.y+(sliders.size()*sliderHeight);
    
    totalHeight=size.y;
    isMaximized=false;
    
    widgetChangedSize=false;

    
    initialLocation=location;
    
}

ofxJFMultiSlider::ofxJFMultiSlider(string _name, ofVec2f &_var, float _min, float _max, int _x, int _y, int _width, int _height){
    
    name=_name;
    
    //value=ofRandom(1);
    min=_min;
    max=_max;
    
    location.set(_x, _y);
    
    size.set(_width, _height/1.6);
    
    setEventArea(location, size);
    enableMouseEvents();
    sliders.clear();
    panelColor = PANEL_COLOR;
    backgroundColor = SLIDER_BACKGROUND_COLOR;
    
    
    sliderPositionY=location.y+size.y;
    sliderHeight=_height;
    
    sliderOffsetX=10;
    
    addLabel(name, ofPoint(location.x+sliderOffsetX,location.y+size.y/2));
    
    //for 2 sliders
    sliders.push_back(new ofxJFSlider("x", _var.x, min, max, location.x,sliderPositionY+(0*sliderHeight),size.x,sliderHeight));
    sliders.push_back(new ofxJFSlider("y", _var.y, min, max, location.x,sliderPositionY+(1*sliderHeight),size.x,sliderHeight));
    
    maximizedHeight=size.y+(sliders.size()*sliderHeight);
    
    totalHeight=size.y;
    isMaximized=false;
    
    widgetChangedSize=false;
    
    initialLocation=location;
    
}



void ofxJFMultiSlider::update(){
    
    for (int i = 0; i< sliders.size(); i++) {
        sliders[i]->update();
    }
 
    //minimize=false;
    //maximize=false;
    widgetChangedSize=false;
  
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
        
        ofSetColor(panelColor);
        ofLine((location.x+size.x)-20, location.y+(size.y/2), (location.x+size.x)-10, location.y+(size.y/2));

    }else{
        
        ofSetColor(panelColor);
        ofRect(location.x,location.y, size.x, size.y);
        ofSetColor(backgroundColor);
        ofLine(location.x, location.y, location.x+size.x, location.y);
        
        
        ofSetColor(backgroundColor);
        ofLine((location.x+size.x)-20, location.y+(size.y/2), (location.x+size.x)-10, location.y+(size.y/2));
        ofLine((location.x+size.x)-15, location.y+(size.y/2)-5, (location.x+size.x)-15, location.y+(size.y/2)+5);
        
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
    widgetChangedSize=true;
    
    if(isMaximized){
        //maximize=true;
        totalHeight=maximizedHeight;
        
        for (int i = 0; i< sliders.size(); i++) {
            sliders[i]->enableMouseEvents();
        }

    }else{
       // minimize=true;
        totalHeight=size.y;
        for (int i = 0; i< sliders.size(); i++) {
            sliders[i]->disableMouseEvents();
        }
        
    }
    
    
}

void ofxJFMultiSlider::mouseDragged(int x, int y, int button){
    
}

void ofxJFMultiSlider::mouseReleased(int x, int y, int button){
    
}