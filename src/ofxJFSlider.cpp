//
//  ofxJFSlider.cpp
//  jfGui
//
//  Created by João Fonseca on 03/04/15.
//
//

#include "ofxJFSlider.h"


ofxJFSlider::ofxJFSlider(){
    
    enableMouseEvents();
    
}

ofxJFSlider::ofxJFSlider(string _name, float _min, float _max, int _x, int _y, int _width, int _height){
    
    name=_name;
    
    value=ofRandom(1);
    min=_min;
    max=_max;
    
    location.set(_x, _y);
    size.set(_width, _height);
    
    sliderOffsetX=10;
    sliderOffsetY=15;
    
    sliderLocationX=location.x+sliderOffsetX;
    sliderLocationY=location.y+(size.y-sliderOffsetY);
    
    sliderWidth=size.x-(sliderOffsetX*2);
    sliderHeight=3;
    
    handleRadius=8;
    hadleLocationX=sliderLocationX;
    hadleLocationY=sliderLocationY+sliderHeight/2;

    
    setEventArea(ofPoint(sliderLocationX,sliderLocationY-(handleRadius)), ofVec2f(sliderWidth,handleRadius*2));
    enableMouseEvents();
 
    backgroundColor=SLIDER_BACKGROUND_COLOR;
    sliderColor=SLIDER_COLOR;
    handleColor=SLIDER_HANDLE_COLOR;
    
    addLabel(name, ofPoint(location.x+sliderOffsetX,location.y+sliderOffsetY));
    
    nb = ofxJFNumberBox(name+"_numberBox", min, max, sliderLocationX+sliderWidth, location.y+sliderOffsetY, 0, sliderWidth/4, 20);
    
    updateValue=false;
    
}

void ofxJFSlider::setLabelPosition(ofPoint _labelLocation){


    setLPosition(_labelLocation);

}

void ofxJFSlider::setLocation(ofPoint _location){

    location=_location;
    setEventArea(location, size);
    //setLPosition(location);

}

void ofxJFSlider::showLabel(bool status){
    
    labelIsVisible=status;
    
}

void ofxJFSlider::update(){
    //nb.update();
    
    if(updateValue){
        value=getValue();
        nb.setValue(value);
    }
    
    if(nb.updatedInputValue){
        value=nb.getValue();
        setValue(value);
        
    }

    
    
}

void ofxJFSlider::drawController(){
    
    
    ofPushStyle();
    
    sliderOffsetX=10;
    sliderOffsetY=15;
  
    sliderLocationX=location.x+sliderOffsetX;
    sliderLocationY=location.y+(size.y-sliderOffsetY);
    
    sliderWidth=size.x-(sliderOffsetX*2);
    sliderHeight=3;
    
    handleRadius=8;
    hadleLocationX=sliderLocationX+handleRadius/2;
    hadleLocationY=sliderLocationY+sliderHeight/2;
    
    
    ofPushStyle();
    
    ofSetColor(backgroundColor);
    ofRect(location.x, location.y, size.x, size.y);
    
    nb.drawController();
    drawLabel();
    
    ofSetColor(sliderColor);
    ofRectRounded(sliderLocationX, sliderLocationY, sliderWidth, sliderHeight, 20);
    
    ofSetColor(handleColor);
    
    ofCircle(hadleLocationX+((sliderWidth-handleRadius)*value), hadleLocationY, handleRadius);

    ofPopStyle();
    
}



void ofxJFSlider::setValue(float _value){
    value=ofMap(_value,min,max,0,1);
    
}

float ofxJFSlider::getValue(){
    
    return ofMap(value,0,1,min,max);
}



void ofxJFSlider::mousePressed(int x, int y, int button){

    
    updateValue=true;
    value=ofMap(ofClamp(x, sliderLocationX, sliderLocationX+sliderWidth),sliderLocationX, sliderLocationX+sliderWidth,0,1);
}

void ofxJFSlider::mouseDragged(int x, int y, int button){
    if(updateValue){
         value=ofMap(ofClamp(x, sliderLocationX, sliderLocationX+sliderWidth),sliderLocationX, sliderLocationX+sliderWidth,0,1);
    
    }
}

void ofxJFSlider::mouseReleased(int x, int y, int button){
     updateValue=false;
}
