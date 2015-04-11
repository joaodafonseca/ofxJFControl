//
//  ofxJFNumberBox.h
//  jfGui
//
//  Created by João Fonseca on 05/04/15.
//
//

#pragma once
#include "ofxJFWidget.h"
#include "ofxJFLabel.h"

class ofxJFNumberBox: public ofxJFWidget, ofxJFLabel {
    
    
public:
    
    ofxJFNumberBox();
    ofxJFNumberBox(string _name, float _min, float _max, int _x, int _y, int _precision, int _width, int _height);
    
    void showLabel(bool status);
    void setLocation(ofPoint _location);

    void update();
    void drawController();
    
    void setValue(float _value);
    float getValue();
    
    virtual void mousePressed(int x, int y, int button);
    virtual void mouseDragged(int x, int y, int button);
    virtual void mouseReleased(int x, int y, int button);
    virtual void doubleClick(int x, int y, int button);
    virtual void keyPressed(int key);
    virtual void keyReleased(int key);
    

    ofPoint mousePressedLocation;
    int precision;
    string inputValue;
    
    
    bool updatedInputValue;
    
    
    int boxPositionX;
    int boxPositionY;
    
    
};