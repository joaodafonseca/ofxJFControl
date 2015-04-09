//
//  ofxJFLabel.cpp
//  jfGui
//
//  Created by João Fonseca on 04/04/15.
//
//

#include "ofxJFLabel.h"
#include "ofxJFWidget.h"


ofxJFLabel::ofxJFLabel(){
    
}

void ofxJFLabel::addLabel(string _label, ofPoint _location){
    
    label=_label;
    location=_location;
    
    ofTrueTypeFont::setGlobalDpi(72);
    font.loadFont("font/helvetica.ttf", 13, true, true);
    //font.setLineHeight(18.0f);
    //font.setLetterSpacing(1.037);
    drawFont=true;
    alignment=0;
    
}


void ofxJFLabel::setAlignment(int _alignment){
    alignment=_alignment;
}

void ofxJFLabel::setLPosition(ofPoint _labelLocation){

    location=_labelLocation;
}

void ofxJFLabel::setLabel(string _label){
    label=_label;
}



void ofxJFLabel::drawLabel(){
    
    if(drawFont){
        ofPushStyle();
        ofSetColor(COLOR_LABEL);
        ofRectangle bounds = font.getStringBoundingBox(label, 0, 0);
        ofPoint alignmentLoaction;
        
        if(alignment==0){
            alignmentLoaction.x=location.x;
            alignmentLoaction.y=location.y+(bounds.height/2);
        
        }else if(alignment==1){
            
            alignmentLoaction.x=location.x-(bounds.width/2);
            alignmentLoaction.y=location.y+(bounds.height/2);
            
         }else if(alignment==2){
            
            alignmentLoaction.x=location.x-(bounds.width);
            alignmentLoaction.y=location.y+(bounds.height/2);
        }



        font.drawString(label, alignmentLoaction.x,alignmentLoaction.y);
        ofPopStyle();
    }
}