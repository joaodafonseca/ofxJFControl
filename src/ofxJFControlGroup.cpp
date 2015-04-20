//
//  ofxJFControlPanel.cpp
//  jfGui
//
//  Created by João Fonseca on 03/04/15.
//
//

#include "ofxJFControlGroup.h"



ofxJFControlGroup::ofxJFControlGroup(){
    enableMouseEvents();
}

ofxJFControlGroup::ofxJFControlGroup(string _name, int _x, int _y, int _width, int _height){
    
    name=_name;
    location.set(_x,_y);
    size.set(_width,_height);
    
    setEventArea(location, size);
    enableMouseEvents();
    
    addLabel(name, ofPoint(location.x+10,location.y+(size.y/2)));
    backgroundColor = SLIDER_BACKGROUND_COLOR;
    
    widgetHeight=48;
    
    maximizedHeight=size.y;
    totalHeight=size.y;
    
    isMaximized=false;
    maximize=false;
    minimize=false;
    groupChangedSize=false;
    
    
    initialLocation=location;
}


void ofxJFControlGroup::addSlider(string _name, float _min, float _max){
    
    int yLoc=initialWigetYlocation();
    controls.push_back(new ofxJFSlider(_name, _min, _max, location.x, yLoc,size.x,widgetHeight));
    
    maximizedHeight+=controls[controls.size()-1]->size.y;
}

void ofxJFControlGroup::addMultiSlider(string _name, float _min, float _max){
    int yLoc=initialWigetYlocation();
    controls.push_back(new ofxJFMultiSlider(_name, _min, _max, location.x, yLoc,size.x,widgetHeight));
    
    maximizedHeight+=controls[controls.size()-1]->size.y;
}



void ofxJFControlGroup::update(){
    
     groupChangedSize=false;
    
    for (int i=0; i< controls.size(); i++){
        
        if(controls[i]->maximize)widgetMaximized(i);
        if(controls[i]->minimize)widgetMinimized(i);
        
        controls[i]->update();
    }
    
   
    
}



void ofxJFControlGroup::drawController(){
    
    ofPushStyle();
    ofSetColor(backgroundColor);
    ofRectRounded(location.x, location.y, size.x, size.y,3);
    
    
    if(isMaximized){
        
        for (int i=0; i< controls.size(); i++) {
            
            controls[i]->drawController();
        }
    }
    
    drawLabel();
    ofPopStyle();
    //ofSetColor(255, 0, 0);
    //ofLine(20, location.y+totalHeight, size.x+20, location.y+totalHeight);
    
}


int ofxJFControlGroup::initialWigetYlocation(){
    
    int yLoc=location.y+size.y;
    
    for (int i=0; i< controls.size(); i++) {
        yLoc+=controls[i]->size.y;
        
    }
    return yLoc;
}


void ofxJFControlGroup::widgetMaximized(int _pos){
    
    maximizedHeight+=(controls[_pos]->totalHeight-controls[_pos]->size.y);
    
    for(int i = _pos+1; i< controls.size();i++){
        
        controls[i]->setLocation(ofPoint(controls[i]->location.x,controls[i]->location.y+(controls[_pos]->totalHeight-controls[_pos]->size.y)));
    }
    
    if(isMaximized){
        totalHeight=maximizedHeight;
    }
    else {
        totalHeight=size.y;
    }
    groupChangedSize=true;
}

void ofxJFControlGroup::widgetMinimized(int _pos){
    
    maximizedHeight-=(controls[_pos]->totalHeight-controls[_pos]->size.y);
    for(int i = _pos+1; i< controls.size();i++){
        controls[i]->setLocation(ofPoint(controls[i]->location.x,controls[i]->location.y-((controls[_pos]->totalHeight-controls[_pos]->size.y))));
        
    }
    
    if(isMaximized){
        // maximize=true;
        totalHeight=maximizedHeight;
    }
    else {
        // minimize=true;
        totalHeight=size.y;
    }
    groupChangedSize=true;
}


void ofxJFControlGroup::setLocation(ofPoint _location){
    
    
    
    
    for(int i = 0; i< controls.size();i++){
        
        controls[i]->setLocation(ofPoint(controls[i]->location.x,controls[i]->initialLocation.y+_location.y));
    }
    
    location.y=initialLocation.y+_location.y;
    setLPosition(ofPoint(location.x+10,location.y+(size.y/2)));
    setEventArea(location, size);
    
    //location=_location;
    
}




void ofxJFControlGroup::mousePressed(int x, int y, int button){
    
    if(hitTest(x, y, size.x, size.y)){
        isMaximized=!isMaximized;
        groupChangedSize=true;
        
        if(isMaximized){
            // maximize=true;
            totalHeight=maximizedHeight;
            // cout<<"maximized"<<totalHeight<<endl;
        }
        else {
            // minimize=true;
            totalHeight=size.y;
            //cout<<"minimized"<<totalHeight<<endl;
        }
        
    }
    
}

