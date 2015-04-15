//
//  ofxJFNumberBox.cpp
//  jfGui
//
//  Created by João Fonseca on 05/04/15.
//
//

#include "ofxJFNumberBox.h"

ofxJFNumberBox::ofxJFNumberBox(){
    
    enableKeyEvents();
    enableMouseEvents();

}
ofxJFNumberBox::ofxJFNumberBox(string _name, float _min, float _max, int _x, int _y, int _precision, int _width, int _height){
    
    min=_min;
    max=_max;
   
    name=_name;
    
    precision=_precision;
    
    location.set(_x, _y);
    size.set(_width,_height);
    totalHeight=size.y;

    
    enableKeyEvents();
    enableMouseEvents();
    
    value=ofRandom(1);
    
    boxPositionX=location.x-size.x;
    boxPositionY=location.y-(size.x/4);
    
    
    addLabel(ofToString(value,precision), ofPoint(location.x,location.y));
    ofRectangle bounds=getBoundingBox();
    setEventArea(ofPoint(bounds.x,bounds.y), ofVec2f(bounds.width,bounds.height));
    setAlignment(JF_RIGHT);
   
    
    
    backgroundColor=SLIDER_BACKGROUND_COLOR;
    sliderColor=SLIDER_COLOR;
    handleColor=SLIDER_HANDLE_COLOR;
    
    
    inputValue="";
   
    maximize=false;
    minimize=false;
    updateValue=false;
    updatedInputValue=false;
}


void ofxJFNumberBox::setLocation(ofPoint _location){
    
    location=_location;
    setLPosition(ofPoint(location.x,location.y));
    ofRectangle bounds=getBoundingBox();
    setEventArea(ofPoint(bounds.x,bounds.y), ofVec2f(bounds.width,bounds.height));

    
}


void ofxJFNumberBox::showLabel(bool status){

    labelIsVisible=status;

}

void ofxJFNumberBox::update(){
    updatedInputValue=false;
}
void ofxJFNumberBox::drawController(){
    
    
    //ofRect =
    
    ofPushStyle();
    //ofSetColor(255,80);
    //ofRect(getBoundingBox());
    
      
    drawLabel();
    ofPopStyle();
    
}



void ofxJFNumberBox::setValue(float _value){
    
    value=_value;
    setLabel(ofToString(value,precision));
    
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
        setLabel(ofToString(value,precision));
        inputValue="";
        updatedInputValue=true;
        ofRectangle bounds=getBoundingBox();
        setEventArea(ofPoint(bounds.x,bounds.y), ofVec2f(bounds.width,bounds.height));
    }
     
}

void ofxJFNumberBox::doubleClick(int x, int y, int button){
    updateValue=true;
    setLabel(inputValue);


}

void ofxJFNumberBox::keyPressed(int key){
    

    
    if(updateValue){
        if ((key>=48 && key<=57) || key == 46 ) {
        //    if(inputValue.size()<precision){
                inputValue+=key;
                setLabel(inputValue);
           //}
        
        }else if(key == 127 ){
          
             if(inputValue.size())inputValue.resize(inputValue.size()-1);
             setLabel(inputValue);
        
        }else if( key== 13 ){
            updateValue=false;
            if(inputValue!="")value=ofClamp(ofToFloat(inputValue),min,max);
            setLabel(ofToString(value,precision));
            inputValue="";
            updatedInputValue=true;
            ofRectangle bounds=getBoundingBox();
            setEventArea(ofPoint(bounds.x,bounds.y), ofVec2f(bounds.width,bounds.height));
        }
        
        
    }
}
void ofxJFNumberBox::keyReleased(int key){

}
