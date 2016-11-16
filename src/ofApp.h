#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxOsc.h"
#include "PlanetVideo.h"
#include "PlanetImage.h"
#include "Planet.h"
#include "ofxGui.h"
#include <map>

// listen on port 1337
#define PORT 1337

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void turnOtherOff(int except);
    void fadeTimeChanged(float &fadeTime);
    
    map<int, Planet*> planets;
    map<int, Planet*>::iterator planetIterator;
    
    PlanetVideo sun;
    
    bool slideShowOn = false;
    int lastSlideChange = 0;
    int lastSlide;
    
    // Gui.
    ofxPanel gui;
    
    ofxIntSlider radius;
    ofxIntSlider offsetX;
    ofxIntSlider offsetY;
    ofxFloatSlider fadeTime;
    ofxIntSlider slideTime;
    
    ofxFloatSlider sunStrenght;
    ofxFloatSlider gain;
   	ofxOscReceiver receiver;
    
    bool showGui = false;
    
protected:
    void updateSlideShow();
    
};
