//
//  ofxJFNumberBox.cpp
//  jfGui
//
//  Created by João Fonseca on 05/04/15.
//
//

#include "ofxJFNumberBox.h"

ofxJFNumberBox::ofxJFNumberBox(){

}
ofxJFNumberBox::ofxJFNumberBox(string _name, float _min, float _max, int _x, int _y, int _precision, int _width, int _height){
    
    min=_min;
    max=_max;
   
    name=_name;
    precision=_precision;
    location.set(_x, _y);
    size.set(_width,_height);
     totalHeight=size.y;

    setEventArea(location, size);
    enableKeyEvents();
    enableMouseEvents();
    
    value=ofRandom(1);
    
    numberLabel.addLabel(ofToString(value,precision), ofPoint(location.x+(size.x)-5,location.y+(size.y/2)));
    numberLabel.setAlignment(JF_RIGHT);
    addLabel(name, ofPoint(location.x+5, location.y+(size.y/2)));
    
    inputValue="";
   
    labelIsVisible=true;
    
    maximize=false;
    minimize=false;

}


void ofxJFNumberBox::setLocation(ofPoint _location){
    
    location=_location;
    setEventArea(location, size);
    numberLabel.setLPosition(ofPoint(location.x+(size.x)-5,location.y+(size.y/2)));
}


void ofxJFNumberBox::showLabel(bool status){

    labelIsVisible=status;

}

void ofxJFNumberBox::update(){
    updatedInputValue=false;
}
void ofxJFNumberBox::drawController(){
    
    
    ofPushStyle();
    ofSetColor(COLOR_BACKGROUND);
    ofRectRounded(location.x, location.y, size.x, size.y,5);
    
    numberLabel.drawLabel();
    
    ofNoFill();
    ofSetColor(COLOR_OUT_STORKE);
    ofRectRounded(location.x, location.y, size.x, size.y,5);
    
    if(labelIsVisible)drawLabel();
    ofPopStyle();
    
}



void ofxJFNumberBox::setValue(float _value){
    
    value=_value;
    numberLabel.setLabel(ofToString(value,precision));
    
}

float ofxJFNumberBox::getValue(){
    
    return value;
}


void ofxJFNumberBox::mousePressed(int x, int y, int button){
  
    mousePressedLocation.set(x,y);
    //value=ofMap(ofClamp(x, location.x, location.x+size.x),location.x, location.x+size.x,0,1);
    


}
void ofxJFNumberBox::mouseDragged(int x, int y, int button){
   /*
    updateValue=true;
    if(updateValue){
        
        float draggedDistance=ofClamp((mousePressedLocation.y-y),-200,200);//ofDist(x, y, mousePressedLocation.x, mousePressedLocation.y);
      //  value=ofMap(draggedDistance,-200,200,0,1);
        //value=ofMap(ofClamp(x, location.x, location.x+size.x),location.x, location.x+size.x,0,1);
        
    }
*/

}
void ofxJFNumberBox::mouseReleased(int x, int y, int button){
    
    if(!hitTest(x, y) && updateValue){
        updateValue=false;
        if(inputValue!="")value=ofClamp(ofToFloat(inputValue),min,max);
        numberLabel.setLabel(ofToString(value,precision));
        inputValue="";
        updatedInputValue=true;
    }
}

void ofxJFNumberBox::doubleClick(int x, int y, int button){
    updateValue=true;
    numberLabel.setLabel(inputValue);


}

void ofxJFNumberBox::keyPressed(int key){
    

    
    if(updateValue){
        if ((key>=48 && key<=57) || key == 46 ) {
        //    if(inputValue.size()<precision){
                inputValue+=key;
                numberLabel.setLabel(inputValue);
           //}
        
        }else if(key == 127 ){
          
             if(inputValue.size())inputValue.resize(inputValue.size()-1);
             numberLabel.setLabel(inputValue);
        
        }else if( key== 13 ){
            updateValue=false;
            if(inputValue!="")value=ofClamp(ofToFloat(inputValue),min,max);
            numberLabel.setLabel(ofToString(value,precision));
            inputValue="";
            updatedInputValue=true;
        }
        
        
    }
}
void ofxJFNumberBox::keyReleased(int key){

}
