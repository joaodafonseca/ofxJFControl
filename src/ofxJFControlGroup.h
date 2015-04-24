//
//  ofxJFControlPanel.h
//  jfGui
//
//  Created by João Fonseca on 03/04/15.
//
//

#pragma once

#include "ofxJFIncludes.h"

class ofxJFControlGroup: public ofxJFWidget, ofxJFLabel {
    
public:
    ofxJFControlGroup();
    ofxJFControlGroup(string _name, int _x, int _y, int _width, int _height=30);
    
    void addSlider(string _name, float _min, float _max);
    void addSlider(string _name, float &_var, float _min, float _max);
    
    void addMultiSlider(string _name, float _min, float _max);
    void addMultiSlider(string _name, ofPoint &_var, float _min, float _max);
    
    void drawController();
    void update();
    
    int initialWigetYlocation();
    void relocateControls(int _pos);
    void widgetMaximized(int _pos);
    void widgetMinimized(int _pos);
    void setLocation(ofPoint _location);
    
    void mousePressed(int x, int y, int button);
    
    
    vector<ofxJFWidget *> controls;

    int widgetHeight;
    
    int maximizedHeight;
    


    
};