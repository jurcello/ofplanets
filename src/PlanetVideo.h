//
//  PlanetVideo.hpp
//  sunMachine
//
//  Created by Jur de Vries on 11/11/16.
//
//

#ifndef PlanetVideo_h
#define PlanetVideo_h

#include <stdio.h>
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "Planet.h"

class PlanetVideo: public Planet {
public:
    void setup(string videoName);
    void update();
    void draw();

protected:
    void updateTranslation();
    
    
    ofVideoPlayer video;
    ofxCvColorImage colorImage;
    ofxCvGrayscaleImage greyScaleImage;
    
    ofxCvContourFinder contour;
    
};

#endif /* PlanetVideo_h */
