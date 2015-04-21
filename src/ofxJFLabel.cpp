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
    labelLocation=_location;
    
    ofTrueTypeFont::setGlobalDpi(72);
    font.loadFont("font/helvetica.ttf", 12, false);
    font.setLineHeight(18.0f);
    //font.setLetterSpacing(1.037);
    drawFont=true;
    alignment=0;
    labelColor.set(255);
    
}


void ofxJFLabel::setAlignment(int _alignment){
    alignment=_alignment;
}

void ofxJFLabel::setLPosition(ofPoint _labelLocation){

    labelLocation=_labelLocation;
}

void ofxJFLabel::setLabel(string _label){
    label=_label;
}

void ofxJFLabel::setLabelColor(ofColor _labelColor){
    
    labelColor=_labelColor;
}

void ofxJFLabel::drawLabel(){
    
    if(drawFont){
        ofPushStyle();
        ofSetColor(labelColor);
        ofRectangle bounds = font.getStringBoundingBox(label, 0, 0);
        ofPoint alignmentLoaction;
        
        if(alignment==0){
            alignmentLoaction.x=labelLocation.x;
            alignmentLoaction.y=labelLocation.y+(bounds.height/2);
        
        }else if(alignment==1){
            
            alignmentLoaction.x=labelLocation.x-(bounds.width/2);
            alignmentLoaction.y=labelLocation.y+(bounds.height/2);
            
         }else if(alignment==2){
            
            alignmentLoaction.x=labelLocation.x-(bounds.width);
            alignmentLoaction.y=labelLocation.y+(bounds.height/2);
        }



        //font.drawString(label, alignmentLoaction.x,alignmentLoaction.y);
        ofDrawBitmapString(label, alignmentLoaction);
        ofPopStyle();
    }
}


ofRectangle ofxJFLabel::getBoundingBox(){
    
    ofRectangle bounds = font.getStringBoundingBox(label, 0, 0);
    return font.getStringBoundingBox(label, labelLocation.x-(bounds.width), labelLocation.y+(bounds.height/2));

}