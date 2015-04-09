//
//  ofxJFControlPanel.h
//  jfGui
//
//  Created by João Fonseca on 03/04/15.
//
//

#pragma once
#include "ofxJFIncludes.h"

class ofxJFControlGroup: public ofxJFEvent, ofxJFLabel {
    
public:
    ofxJFControlGroup();
    
    void createPanel(string _name, int _x, int _y, int _width=300, int _height=40, int _horizontalOffset=0);
    void addSimpleSlider(string _name);
    void addSlider(string _name, float _min, float _max);
    void addMultiSlider(string _name, float _min, float _max);
    void addSliderNB(string _name);
    void addButton(string _name);
    void addNumberBox(string _name, int _precision);
    void draw();
    void update();
    void updateSize(int _pos, int _state);
    
    
    virtual void mousePressed(int x, int y, int button);//this should be double click
    
    string name;
    ofPoint location;
    ofPoint controlLocation;
    ofVec2f size;
    ofVec2f controlSize;
    int nControls;
    bool minimize;
    int controlHeight;
    int horizontalOffset;
    int controlOffset;
    
    vector<ofxJFWidget *> contolls;
    
};