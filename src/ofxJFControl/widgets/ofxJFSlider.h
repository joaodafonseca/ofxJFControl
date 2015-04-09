//
//  ofxJFSlider.h
//  jfGui
//
//  Created by João Fonseca on 03/04/15.
//
//

#pragma once
#include "ofxJFWidget.h"
#include "ofxJFLabel.h"

class ofxJFSlider: public ofxJFWidget, ofxJFLabel{
    
public:
    
    ofxJFSlider();
    ofxJFSlider(string _name, float _min, float _max, int _x, int _y, int _width, int _height);
    
    void setLabelPosition(ofPoint _labelLocation);
    void setLocation(ofPoint _location);
    void showLabel(bool status);
    void update();
    void drawController();
    
    void setValue(float _value);
    float getValue();
    
    virtual void mousePressed(int x, int y, int button);
    virtual void mouseDragged(int x, int y, int button);
    virtual void mouseReleased(int x, int y, int button);

    
    ofPoint location;
    ofVec2f size;
    
    
};