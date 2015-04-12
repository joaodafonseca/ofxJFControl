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
}


void ofxJFControlGroup::addSlider(string _name, float _min, float _max){

    int yLoc=initialWigetYlocation();
    controls.push_back(new ofxJFSlider(_name, _min, _max, location.x, yLoc,size.x,widgetHeight));
}

void ofxJFControlGroup::addMultiSlider(string _name, float _min, float _max){
    int yLoc=initialWigetYlocation();
    controls.push_back(new ofxJFMultiSlider(_name, _min, _max, location.x, yLoc,size.x,widgetHeight));
}



void ofxJFControlGroup::update(){

    for (int i=0; i< controls.size(); i++){
        
        if(controls[i]->maximize)widgetMaximized(i);
        if(controls[i]->minimize)widgetMinimized(i);
        
        controls[i]->update();
    }
    
    

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
    
    
    
 }


int ofxJFControlGroup::initialWigetYlocation(){

    int yLoc=location.y+size.y;
    
    for (int i=0; i< controls.size(); i++) {
        yLoc+=controls[i]->size.y;
    }
    return yLoc;
}


void ofxJFControlGroup::widgetMaximized(int _pos){
    for(int i = _pos+1; i< controls.size();i++){
    
        controls[i]->setLocation(ofPoint(controls[i]->location.x,controls[i]->location.y+(controls[_pos]->totalHeight-controls[_pos]->size.y)));
    }

}

void ofxJFControlGroup::widgetMinimized(int _pos){

    for(int i = _pos+1; i< controls.size();i++){
        controls[i]->setLocation(ofPoint(controls[i]->location.x,controls[i]->location.y-((controls[_pos]->totalHeight-controls[_pos]->size.y))));
        
    }

}

void ofxJFControlGroup::mousePressed(int x, int y, int button){
    
    if(hitTest(x, y, size.x, size.y)){
        isMaximized=!isMaximized;
    }
    
}

