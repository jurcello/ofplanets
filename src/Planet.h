//
//  Planet.hpp
//  sunMachine
//
//  Created by Jur de Vries on 11/11/16.
//
//

#ifndef Planet_hpp
#define Planet_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxOpenCv.h"

class Planet {
public:
    void setup(string videoName);
    void update();
    void draw();
    void setRadius(int radius);
    
    void setOffsetX(int offset);
    void setOffsetY(int offset);
    
    bool isOn();
    void setOn(bool isOn);

protected:
    void updateFading();
    void updateTranslation();
    
    
    ofVideoPlayer video;
    ofxCvColorImage colorImage;
    ofxCvGrayscaleImage greyScaleImage;
    
    ofxCvContourFinder contour;
    
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

#endif /* Planet_hpp */
