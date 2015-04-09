//
//  ofxJFControlPanel.cpp
//  jfGui
//
//  Created by João Fonseca on 03/04/15.
//
//

#include "ofxJFControlGroup.h"



ofxJFControlGroup::ofxJFControlGroup(){
    
}


void ofxJFControlGroup::createPanel(string _name, int _x, int _y, int _width,  int _height, int _horizontalOffset){
    

    controlHeight=_height;
    controlOffset=10;
    
    name=_name;
    location.set(_x, _y);
    controlLocation.set(_x+controlOffset, _y+controlOffset);
    controlSize.set(_width-(2*controlOffset),controlHeight-horizontalOffset-(2*controlOffset));
 
    horizontalOffset=_horizontalOffset;
    size.set(_width,controlHeight-horizontalOffset+(2*controlOffset));
    
    addLabel(name, ofPoint(controlLocation.x,location.y+(controlHeight/2)));
    
    nControls=0;
    minimize=true;
    enableMouseEvents();
    setEventArea(location, size);
    
    
}

void ofxJFControlGroup::addSlider(string _name, float _min, float _max){
    
    size.y+=controlHeight+horizontalOffset;
    
    contolls.push_back(new ofxJFSlider(_name, _min, _max, controlLocation.x, controlLocation.y+(contolls.size()*(controlHeight+horizontalOffset))+controlHeight, controlSize.x, controlHeight));
    
    
    setEventArea(location, size);
    nControls++;
}

void ofxJFControlGroup::addMultiSlider(string _name, float _min, float _max){
/*
    size.y+=controlHeight+horizontalOffset;
    
    contolls.push_back(new ofxJFMultiSlider(_name, _min, _max, controlLocation.x, controlLocation.y+(contolls.size()*(controlHeight+horizontalOffset))+controlHeight, controlSize.x, controlHeight));
    
    
    setEventArea(location, size);
    nControls++;
 */
}

void ofxJFControlGroup::addButton(string _name){
    
    size.y+=controlHeight+horizontalOffset;
    
    contolls.push_back(new ofxJFButton(_name, controlLocation.x, controlLocation.y+(contolls.size()*(controlHeight+horizontalOffset))+controlHeight, (controlSize.x/4)*3, controlHeight));
   // contolls[contolls.size()-1]->setLabelPosition(ofPoint(controlLocation.x,controlLocation.y+(contolls.size()*(controlHeight+horizontalOffset))+(controlSize.y/2)));
    
    setEventArea(location, size);
    nControls++;
}


/*
void ofxJFControlPanel::addSliderNB(string _name){
    
    size.y+=controlHeight+horizontalOffset;
    
    int yLocation=controlLocation.y+(nControls*(controlHeight+horizontalOffset))+controlHeight;
    
    contolls.push_back(new ofxJFSimpleSlider(_name, controlLocation.x+(controlSize.x/4), yLocation, controlSize.x/2, controlHeight));
    contolls[contolls.size()-1]->setLabelPosition(ofPoint(controlLocation.x,yLocation+controlHeight/2));
    
    contolls.push_back(new ofxJFNumberBox(_name, controlLocation.x+(controlSize.x/4)*3, yLocation, 4, (controlSize.x/4), controlHeight));
    contolls[contolls.size()-1]->showLabel(false);
   
    setEventArea(location, size);
    nControls++;
}

void ofxJFControlPanel::addSimpleSlider(string _name){
    
    size.y+=controlHeight+horizontalOffset;
    
    contolls.push_back(new ofxJFSimpleSlider(_name, controlLocation.x, controlLocation.y+(nControls*(controlHeight+horizontalOffset))+controlHeight, controlSize.x, controlHeight));
    
    
    setEventArea(location, size);
    nControls++;
}



void ofxJFControlPanel::addNumberBox(string _name, int _precision){
    
    size.y+=controlHeight+horizontalOffset;
    
    contolls.push_back(new ofxJFNumberBox(_name, location.x, location.y+(nControls*(controlHeight+horizontalOffset))+controlHeight, _precision, size.x, controlHeight));
    
  
    setEventArea(location, size);
        nControls++;
}
*/



void ofxJFControlGroup::update(){

    for (int i=0; i< contolls.size(); i++) {
        
        if( contolls[i]->maximize){
            updateSize(i,0);
        }
        if( contolls[i]->minimize){
            updateSize(i,1);
            cout<<"mini"<<endl;
        }
        
        contolls[i]->update();
        
        
    }

}


void ofxJFControlGroup::updateSize(int _pos, int _state){

    int totalSize=0;
    
    for (int i=0; i< contolls.size(); i++) {
        contolls[i]->update();
        totalSize+=contolls[i]->totalHeight;
    }
    
    for(int i = _pos+1; i< contolls.size(); i++){
     
        if(_state==0)contolls[i]->setLocation(ofPoint(contolls[i]->getLocation().x,contolls[i]->getLocation().y+contolls[_pos]->totalHeight));
        if(_state==1)contolls[i]->setLocation(ofPoint(contolls[i]->getLocation().x,contolls[i]->getLocation().y-contolls[_pos]->totalHeight));
    }
    
     size.y=totalSize+(horizontalOffset*contolls.size())+controlHeight+horizontalOffset;
     setEventArea(location, size);


}

void ofxJFControlGroup::draw(){
    
    
    
    
    
    ofPushStyle();
    ofSetColor(COLOR_PANEL);
    
    if(minimize){
        
        ofRectRounded(location, size.x, controlHeight,5);
        
    }else{
        
         ofSetColor(COLOR_PANEL);
        ofRectRounded(location, size.x, size.y,5);
        
       
        ofSetColor(180);
        for (int i=1; i< nControls; i++) {
        int yLocation=controlLocation.y+(i*(controlHeight+horizontalOffset))+controlHeight-(horizontalOffset/2) ;
            ofLine(controlLocation.x, yLocation, controlLocation.x+controlSize.x, yLocation);
        
        }
        
        
        for (int i=0; i< contolls.size(); i++) {
            contolls[i]->drawController();
        }
        
        ofSetColor(COLOR_FILL);
        ofLine(location.x+size.x-2, location.y+50, location.x+size.x-2, location.y+size.y/2);
        ofLine(location.x+size.x-1, location.y+50, location.x+size.x-1, location.y+size.y/2);
    }
    
  
    
    drawLabel();
    ofPopStyle();
}


void ofxJFControlGroup::mousePressed(int x, int y, int button){
    
    if(hitTest(x, y, size.x, controlHeight)){
        minimize=!minimize;
    }
    
    
//    if(!minimize){
//        
//        for(int i = 0; i < contolls.size(); i++){
//            
//            contolls[i]->setLocation(ofPoint(ofGetMouseX(),ofGetMouseY()));
//            
//            
//        }
//    }
    
}

