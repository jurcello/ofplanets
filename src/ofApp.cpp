#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Setup gui.
    gui.setup();
    gui.add(radius.setup("Radius", 200, 10, 800));
    gui.add(offsetX.setup("X offset", 0, -500, 500));
    gui.add(offsetY.setup("Y offset", 0, -500, 500));
    
    planets['a'] = *new Planet;
    planets['a'].setup("Moon.mp4");
    planets['s'] = *new Planet;
    planets['s'].setup("Jupiter.mp4");
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (auto& planet: planets) {
        planet.second.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    if (showGui) {
        gui.draw();
    }
    for (auto& planet: planets) {
        planet.second.draw();
    }

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
        default:
            turnOtherOff(key);
            planets[key].setOn(true);
            break;
            
    }
    for (auto& planet: planets) {
        planet.second.setRadius(radius);
        planet.second.setOffsetX(offsetX);
        planet.second.setOffsetY(offsetY);
    }
}

void ofApp::turnOtherOff(int except) {
    for (auto& planet: planets) {
        if (planet.first != except)
        planet.second.setOn(false);
    }
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
