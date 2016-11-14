//
//  Planet.hpp
//  sunMachine
//
//  Created by Jur de Vries on 14/11/16.
//
//

#ifndef Planet_h
#define Planet_h

#include <stdio.h>
#include "ofMain.h"
#include "ofxOpenCv.h"

class Planet {
public:
    virtual void setup(string name) = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    
    void setRadius(int radius);
    
    void setOffsetX(int offset);
    void setOffsetY(int offset);
    
    bool isOn();
    void setOn(bool isOn);

protected:
    bool shouldUpdate();
    void updateFading();
        
    int width;
    int height;
    
    int offsetX = 0;
    int offsetY = 0;
    
    int radius = 200;
    float newWidth;
    float newHeight;
    
    ofPoint moonTranslate;
    
    // Fading behaviour
    float fadeTime = 2000;
    int stateChangedTime = 0;
    bool on = false;
    bool changing = false;
    int opacity = 0;
    
};

#endif /* Planet_h */
