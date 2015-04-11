//
//  ofxJFMultiSlider.h
//  ofxJFControl
//
//  Created by João Fonseca on 11/04/15.
//
//

#pragma once
#include "ofxJFWidget.h"

class ofxJFMultiSlider {
    
public:
    ofxJFMultiSlider();
    ofxJFMultiSlider(string _name, float _min, float _max, int _x, int _y, int _width, int _height);
    
    void setLabelPosition(ofPoint _labelLocation);
    void setLocation(ofPoint _location);
    void showLabel(bool status);
    void update();
    void drawController();
    
    void setValue(float _value);
    float getValue();
    
    void mousePressed(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
};