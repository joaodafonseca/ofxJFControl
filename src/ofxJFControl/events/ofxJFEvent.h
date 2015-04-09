//
//  ofxJFcontroller.h
//  jfGui
//
//  Created by João Fonseca on 03/04/15.
//
//

#pragma once
#include "ofMain.h"


class ofxJFEvent {
    
    
public:
    
    ofxJFEvent();
    virtual ~ofxJFEvent();
    
    void setEventArea(ofPoint _location, ofVec2f _size);
    bool hitTest(int tx, int ty) const;
    virtual bool hitTest(int tx, int ty, int w, int h) const;
    
    void enableMouseEvents();
    void disableMouseEvents();
    void enableKeyEvents();
    void disableKeyEvents();
    
    // you shouldn't need access to any of these unless you know what you are doing
    // (i.e. disable auto updates and call these manually)
    /*§
    void _setup(ofEventArgs &e);
    void _update(ofEventArgs &e);
    void _draw(ofEventArgs &e);
    void _exit(ofEventArgs &e);
    */
    
    bool clickedTwice();
    
    void _mouseMoved(ofMouseEventArgs &e);
    void _mousePressed(ofMouseEventArgs &e);
    void _mouseDragged(ofMouseEventArgs &e);
    void _mouseReleased(ofMouseEventArgs &e);
    
    void _keyPressed(ofKeyEventArgs &e);
    void _keyReleased(ofKeyEventArgs &e);
    
    
    // these are called when the relevant event occurs without caring where it actually happened
    // i.e. its the raw event
    virtual void mouseMoved(int x, int y) {}                     // called when mouse moves anywhere
    virtual void mousePressed(int x, int y, int button) {}       // called when mouse pressed anywhere
    virtual void mouseDragged(int x, int y, int button) {}       // called when mouse dragged anywhere
    virtual void mouseReleased(int x, int y, int button) {}      // called when mouse released anywhere
    virtual void doubleClick(int x, int y, int button) {}      // called when mouse released anywhere
    
    virtual void keyPressed(int key) {}                          // called when keypressed anywhere
    virtual void keyReleased(int key) {}                         // called when keyreleased anywhere

    
    ofPoint location;
    ofVec2f size;
    
    float lastClick;
    
    
};