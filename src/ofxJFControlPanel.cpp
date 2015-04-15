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
    
    offsetX = 5;
    offsetY = 5;
    groupLocation.set(location.x+offsetX, location.y+size.y);
    groupSize.set(size.x-(2*offsetX),size.y);
    
    addLabel(name, ofPoint(location.x+offsetX, location.y+(size.y/2)));
    
    
}

void ofxJFControlPanel::addGroup(string _name){


    groups.push_back(new ofxJFControlGroup(_name, groupLocation.x, groupLocation.y,groupSize.x));
    groupLocation.y+=groups[groups.size()-1]->totalHeight+offsetY;

    
    size.y+=groups[groups.size()-1]->totalHeight+offsetY;
}


void ofxJFControlPanel::addSlider(string _name, float _min, float _max){

    groups[groups.size()-1]->addSlider(_name,  _min,  _max);


}

void ofxJFControlPanel::addMultiSlider(string _name, float _min, float _max){
    
    
    
}

void ofxJFControlPanel::update(){

    for (int i = 0; i<groups.size(); i++) {
        
        if(groups[i]->maximize)groupMaximized(i);
        if(groups[i]->minimize)groupMinimized(i);
        
        groups[i]->update();
    }
}


void ofxJFControlPanel::groupMaximized(int _pos){

    for (int i = _pos; i<groups.size(); i++) {
        

            groups[i]->setLocation(ofPoint(groups[i]->location.x,groups[i]->location.y+groups[_pos]->totalHeight));
            
        }
    }


void ofxJFControlPanel::groupMinimized(int _pos){

    for (int i = _pos; i<groups.size(); i++) {
        
        
            groups[i]->setLocation(ofPoint(groups[i]->location.x,groups[_pos]->location.y-groups[_pos]->totalHeight));
        
    }

    
}



void ofxJFControlPanel::drawController(){
    
    ofPushStyle();
    ofSetColor(panelColor);
    ofRect(location.x, location.y, size.x, size.y);
    drawLabel();
    
    if(!isMaximized){
        for(int i = 0; i < groups.size(); i++){
            groups[i]->drawController();
        }
    
    }
    
    ofPopStyle();
    
    
}

void ofxJFControlPanel::mousePressed(int x, int y, int button){

    isMaximized=!isMaximized;
    
}
