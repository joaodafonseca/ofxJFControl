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
    minimize=false;
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
    
    if(isMaximized)totalHeight=maximizedHeight;
    else totalHeight=size.y;

    
    
    for (int i=0; i< controls.size(); i++){
        
        if(controls[i]->maximize)widgetMaximized(i);
        if(controls[i]->minimize)widgetMinimized(i);
        
        controls[i]->update();
    }
    
    maximize=false;
    minimize=false;

}



void ofxJFControlGroup::drawController(){
    
    ofPushStyle();
    ofSetColor(backgroundColor);
    ofRect(location.x, location.y, size.x, size.y);
    
    
    if(isMaximized){

        for (int i=0; i< controls.size(); i++) {
            
            controls[i]->drawController();
        }
    }
    
    drawLabel();
    ofPopStyle();
    ofSetColor(255, 0, 0);
    ofLine(20, location.y+totalHeight, size.x+20, location.y+totalHeight);
    
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

}

void ofxJFControlGroup::widgetMinimized(int _pos){

    maximizedHeight-=(controls[_pos]->totalHeight-controls[_pos]->size.y);
    for(int i = _pos+1; i< controls.size();i++){
        controls[i]->setLocation(ofPoint(controls[i]->location.x,controls[i]->location.y-((controls[_pos]->totalHeight-controls[_pos]->size.y))));
        
    }

}


void ofxJFControlGroup::setLocation(ofPoint _location){
    
  // location=_location;

    for(int i = 0; i< controls.size();i++){
        
      //  controls[i]->setLocation(ofPoint(controls[i]->location.x,controls[i]->location.y+_location.y));
    }
 
     //location=_location;

}




void ofxJFControlGroup::mousePressed(int x, int y, int button){
    
    if(hitTest(x, y, size.x, size.y)){
        isMaximized=!isMaximized;
        if(isMaximized)maximize=true;
        else minimize=true;
    }
    
}

