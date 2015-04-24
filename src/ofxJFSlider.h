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
#include "ofxJFNumberBox.h"

class ofxJFSlider: public ofxJFWidget, ofxJFLabel{
    
public:
    
    ofxJFSlider();
    ofxJFSlider(string _name, float _min, float _max, int _x, int _y, int _width, int _height);
    ofxJFSlider(string _name, float &_var, float _min, float _max, int _x, int _y, int _width, int _height);
    
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
    
    
    int sliderOffsetX;
    int sliderOffsetY;
    
    
    int sliderLocationX;
    int sliderLocationY;
    
    int sliderWidth;
    int sliderHeight;
    
    int handleRadius;
    int hadleLocationX;
    int hadleLocationY;
    
    ofxJFNumberBox nb;

};