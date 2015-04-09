//
//  ofxJFControl.h
//  jfGui
//
//  Created by João Fonseca on 03/04/15.
//
//

#pragma once
#include "ofxJFEvent.h"
#include "ofxJFColors.h"

class ofxJFWidget: public ofxJFEvent {
    
public:
    
    ofxJFWidget();
    
    
    virtual void setLabelPosition(ofPoint _labelLocation);
    virtual void showLabel(bool _state);
    virtual void setValue(float _value);
    virtual void setLocation(ofPoint _location);
    virtual ofPoint getLocation();
    virtual float getValue();
    
    virtual void drawController();
    virtual void update();
    
    float value;
    float max;
    float min;
    bool updateValue;
    bool labelIsVisible;
    string name;
    int totalHeight;
    bool maximize;
    bool minimize;
    

};