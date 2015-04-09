//
//  ofxJFBotton.h
//  jfGui
//
//  Created by João Fonseca on 06/04/15.
//
//
#pragma once
#include "ofxJFWidget.h"
#include "ofxJFLabel.h"

class ofxJFButton: public ofxJFWidget, ofxJFLabel{
    
public:
    
    ofxJFButton();
    ofxJFButton(string _name ,int _x, int _y, int _width, int _height);
    
    void setLabelPosition(ofPoint _labelLocation);
    void setLocation(ofPoint _location);
    ofPoint getLocation();
    void update();
    void drawController();
    
    
    
    virtual void mousePressed(int x, int y, int button);
    virtual void mouseReleased(int x, int y, int button);
    
    
    ofPoint location;
    ofVec2f size;
    
    ofxJFLabel state;
    
    
};