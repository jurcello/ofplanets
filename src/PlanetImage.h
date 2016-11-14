//
//  PlanetImage.hpp
//  sunMachine
//
//  Created by Jur de Vries on 14/11/16.
//
//

#ifndef PlanetImage_h
#define PlanetImage_h

#include <stdio.h>
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "Planet.h"

class PlanetImage: public Planet {
public:
    void setup(string imageName);
    void update();
    void draw(float intensity);
    
protected:
    void updateTranslation();
    void findContours();
    
    ofImage image;
    
    ofxCvColorImage colorImage;
    ofxCvGrayscaleImage greyScaleImage;
    
    ofxCvContourFinder contour;
    
};

#endif /* PlanetImage_h */
