#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Setup gui.
    gui.setup();
    gui.add(radius.setup("Radius", 200, 10, 800));
    gui.add(offsetX.setup("X offset", 0, -500, 500));
    gui.add(offsetY.setup("Y offset", 0, -500, 500));
    
    moon.setup("Moon.mp4");
    jupiter.setup("Jupiter.mp4");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    moon.update();
    jupiter.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    if (showGui) {
        gui.draw();
    }
    moon.draw();
    jupiter.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '=':
            radius = radius + 1;
            break;
        case '-':
            radius = radius - 1;
            break;
        case OF_KEY_UP:
            offsetY = offsetY - 1;
            break;
        case OF_KEY_DOWN:
            offsetY = offsetY + 1;
            break;
        case OF_KEY_LEFT:
            offsetX = offsetX - 1;
            break;
        case OF_KEY_RIGHT:
            offsetX = offsetX + 1;
            break;
        case 'g':
            showGui = !showGui;
            break;
        case 'm':
            moon.setOn(true);
            jupiter.setOn(false);
            break;
        case 'j':
            jupiter.setOn(true);
            moon.setOn(false);
            break;
            
    }
    moon.setRadius(radius);
    moon.setOffsetX(offsetX);
    moon.setOffsetY(offsetY);
    jupiter.setRadius(radius);
    jupiter.setOffsetX(offsetX);
    jupiter.setOffsetY(offsetY);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
