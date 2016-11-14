#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "Planet.h"
#include "ofxGui.h"
#include <map>

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
    
    map<int, Planet> planets;
    
    // Gui.
    ofxPanel gui;
    
    ofxIntSlider radius;
    ofxIntSlider offsetX;
    ofxIntSlider offsetY;
    
    bool showGui = false;
};
