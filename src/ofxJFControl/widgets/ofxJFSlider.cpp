//
//  ofxJFSlider.cpp
//  jfGui
//
//  Created by João Fonseca on 03/04/15.
//
//

#include "ofxJFSlider.h"


ofxJFSlider.::ofxJFSlider.(){
    
    enableMouseEvents();
    
}

ofxJFSlider.::ofxJFSlider.(string _name, float _min, float _max, int _x, int _y, int _width, int _height){
    
    min=_min;
    max=_max;
  
    name=_name;
    
    size.set(_width, _height);
   
}

void ofxJFSlider.::setLabelPosition(ofPoint _labelLocation){


    setLPosition(_labelLocation);

}

void ofxJFSlider.::setLocation(ofPoint _location){

    location=_location;
    setEventArea(location, size);
    //setLPosition(location);

}

void ofxJFSlider.::showLabel(bool status){
    
    labelIsVisible=status;
    
}

void ofxJFSlider.::update(){
    
}

void ofxJFSlider.::drawController(){
    
    ofPushStyle();
   
    
    
    ofPopStyle();
    
}



void ofxJFSlider.::setValue(float _value){
    value=ofMap(_value,min,max,0,1);
    
}

float ofxJFSlider.::getValue(){
    
    return ofMap(value,0,1,min,max);
}



void ofxJFSlider.::mousePressed(int x, int y, int button){
    
    updateValue=true;
    value=ofMap(ofClamp(x, location.x, location.x+size.x),location.x, location.x+size.x,0,1);
}
void ofxJFSimpleSlider::mouseDragged(int x, int y, int button){
    if(updateValue){
        value=ofMap(ofClamp(x, location.x, location.x+size.x),location.x, location.x+size.x,0,1);
    
    }
}
void ofxJFSlider.::mouseReleased(int x, int y, int button){
     updateValue=false;
}
