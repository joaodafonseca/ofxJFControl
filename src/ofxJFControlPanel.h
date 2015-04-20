//
//  ofxJFControlPanel.h
//  ofxJFControl
//
//  Created by João Fonseca on 09/04/15.
//
//

#pragma once
#include "ofxJFIncludes.h"


class ofxJFControlPanel: public ofxJFWidget, ofxJFLabel {
    
    
public:
    
    ofxJFControlPanel();
    ofxJFControlPanel(string _name, int _x, int _y, int _width, int _height=50);
    
    
    void addGroup(string _name);
    void addSlider(string _name, float _min, float _max);
    void addMultiSlider(string _name, float _min, float _max);
    
    void relocateGroup(int _pos);

    
    void update();
    void drawController();
    
    void mousePressed(int x, int y, int button);
    
    ofPoint groupLocation;
    ofVec2f groupSize;
    int offsetY;
    int offsetX;
    
    bool isMaximized;
    int minimizedSize;
    
    vector<ofxJFControlGroup *> groups;
    
    
};
