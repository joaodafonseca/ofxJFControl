//
//  ofxJFControlPanel.cpp
//  ofxJFControl
//
//  Created by João Fonseca on 09/04/15.
//
//

#include "ofxJFControlPanel.h"


ofxJFControlPanel::ofxJFControlPanel(){
    
    enableMouseEvents();
    
}

ofxJFControlPanel::ofxJFControlPanel(string _name, int _x, int _y, int _width, int _height){
    
    groups.clear();
    
    name=_name;
    location.set(_x,_y);
    size.set(_width,_height);
    
    
    setEventArea(location, size);
    enableMouseEvents();
    
    isMaximized=false;
    
    panelColor.set(PANEL_COLOR);
    
    offsetX = 8;
    offsetY = 5;
    groupLocation.set(location.x+offsetX, location.y+size.y);
    groupSize.set(size.x-(2*offsetX),size.y);
    
    addLabel(name, ofPoint(location.x+offsetX, location.y+(size.y/2)));
    totalHeight=0;
    
    initialLocation=location;
    
    maximizedSize=0;
    tSize=0;
    totalHeight=size.y;
    maximizedSize=size.y;
}

void ofxJFControlPanel::createGroup(string _name){
    
    
    groups.push_back(new ofxJFControlGroup(_name, groupLocation.x, groupLocation.y,groupSize.x));
    groupLocation.y+=groups[groups.size()-1]->totalHeight+offsetY;
    
    
    maximizedSize+=groups[groups.size()-1]->size.y+offsetY;
    //totalHeight=maximizedSize;
   // totalHeight=size.y;
}


void ofxJFControlPanel::addSlider(string _name, float _min, float _max){
    
    if(groups.size())groups[groups.size()-1]->addSlider(_name,  _min,  _max);
}

void ofxJFControlPanel::addSlider(string _name, float &_val, float _min, float _max){
    
    if(groups.size())groups[groups.size()-1]->addSlider(_name, _val, _min,  _max);
}

void ofxJFControlPanel::addMultiSlider(string _name, float _min, float _max){
    
    
    if(groups.size())groups[groups.size()-1]->addMultiSlider(_name,  _min,  _max);
    
}

void ofxJFControlPanel::update(){
    
    for (int i = 0; i<groups.size(); i++) {
        
        if(groups[i]->groupChangedSize){
            // cout<<groups[i]->totalHeight<<endl;
            relocateGroup(i);
        }
        
        
        groups[i]->update();
    }
       //cout<<maximizedSize<<endl;
}


void ofxJFControlPanel::relocateGroup(int _pos){
    
    for (int i = _pos+1; i<groups.size(); i++) {
        
        int relocation=0;
        
        for(int p = 0; p < i; p++){
            
            relocation+=groups[p]->totalHeight-groups[p]->size.y;
        }
        
        groups[i]->setLocation(ofPoint(groups[i]->location.x,relocation));
    }

    
    tSize=0;
    
    for(int i = 0; i < groups.size();i++){
        tSize+=groups[i]->totalHeight-groups[i]->size.y;
    }
    
    totalHeight=maximizedSize+tSize;
     
}




void ofxJFControlPanel::drawController(){
    
    ofPushStyle();
    ofSetColor(panelColor);
    ofRectRounded(location.x, location.y, size.x, totalHeight,3);
    drawLabel();
    
    if(isMaximized){
        for(int i = 0; i < groups.size(); i++){
            groups[i]->drawController();
        }
        
    }
    
    ofPopStyle();
    
    
}

void ofxJFControlPanel::mousePressed(int x, int y, int button){
    
    isMaximized=!isMaximized;
    
    
    if(isMaximized){
        // maximize=true;
        totalHeight=maximizedSize+tSize;
        // cout<<"maximized"<<totalHeight<<endl;
    }
    else {
        // minimize=true;
        totalHeight=size.y;
        //cout<<"minimized"<<totalHeight<<endl;
    }

    
}
