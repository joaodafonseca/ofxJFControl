//
//  ofxJFLabel.h
//  jfGui
//
//  Created by João Fonseca on 04/04/15.
//
//

#pragma once
#include "ofMain.h"

#define JF_LEFT 0
#define JF_CENTER 1
#define JF_RIGHT 2

class ofxJFLabel {
    
public:
    
    ofxJFLabel();
    
    void addLabel(string _label, ofPoint _location);
    void setLabel(string _label);
    void setAlignment(int _alignment);
    void setLPosition(ofPoint _labelLocation);
    void drawLabel();
    
    ofRectangle getBoundingBox();
    
    string  label;
   
    
    ofTrueTypeFont  font;
    int alignment;
    
    bool drawFont;
    
private:
     ofPoint labelLocation;
};