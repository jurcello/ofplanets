#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // Setup gui.
    fadeTime.addListener(this, &ofApp::fadeTimeChanged);
    gui.setup();
    gui.add(radius.setup("Radius", 500, 10, 800));
    gui.add(offsetX.setup("X offset", 0, -500, 500));
    gui.add(offsetY.setup("Y offset", 0, -500, 500));
    gui.add(fadeTime.setup("Fade time", 2000, 500, 5000));
    gui.add(sunStrenght.setup("SunStrenght", 0.0, 0.0, 1.0));
    gui.add(gain.setup("Gain", 1.0, 0.5, 10.0));
    
    // Setup osc.
    // listen on the given port
    cout << "listening for osc messages on port " << PORT << "\n";
    receiver.setup(PORT);

    
    planets['1'] = new PlanetVideo;
    planets['1']->setup("Moon.mp4");
    planets['2'] = new PlanetVideo;
    planets['2']->setup("Jupiter.mp4");
    planets['3'] = new PlanetVideo;
    planets['3']->setup("Mercury.mp4");
    planets['4'] = new PlanetVideo;
    planets['4']->setup("Mars.mp4");
    
    planets['q'] = new PlanetImage;
    planets['q']->setup("PROTOTYPE PLANETS_01.jpg");
    planets['w'] = new PlanetImage;
    planets['w']->setup("PROTOTYPE PLANETS_02.jpg");
    planets['e'] = new PlanetImage;
    planets['e']->setup("PROTOTYPE PLANETS_03.jpg");
    planets['r'] = new PlanetImage;
    planets['r']->setup("PROTOTYPE PLANETS_04.jpg");
    planets['t'] = new PlanetImage;
    planets['t']->setup("PROTOTYPE PLANETS_05.jpg");
    planets['y'] = new PlanetImage;
    planets['y']->setup("PROTOTYPE PLANETS_06.jpg");
    planets['u'] = new PlanetImage;
    planets['u']->setup("PROTOTYPE PLANETS_07.jpg");
    planets['i'] = new PlanetImage;
    planets['i']->setup("PROTOTYPE PLANETS_08.jpg");
    planets['o'] = new PlanetImage;
    planets['o']->setup("PROTOTYPE PLANETS_09.jpg");
    
    sun.setup("Sun.mp4");
    sun.setOn(true);
    sun.setRadius(radius);
    sun.setOffsetX(offsetX);
    sun.setOffsetY(offsetY);
    
    for (auto& planet: planets) {
        planet.second->setRadius(radius);
        planet.second->setOffsetX(offsetX);
        planet.second->setOffsetY(offsetY);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        if(m.getAddress() == "/sunmachine"){
            sunStrenght = m.getArgAsFloat(0) * gain;
        }
    }

    for (auto& planet: planets) {
        planet.second->update();
    }
    sun.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    for (auto& planet: planets) {
        planet.second->draw(1 - sunStrenght);
    }
    sun.draw(sunStrenght);
    if (showGui) {
        gui.draw();
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
            if (planets.find(key) != planets.end()) {
                turnOtherOff(key);
                planets[key]->setOn(true);
            }
            break;
            
    }
    for (auto& planet: planets) {
        planet.second->setRadius(radius);
        planet.second->setOffsetX(offsetX);
        planet.second->setOffsetY(offsetY);
    }
    sun.setRadius(radius);
    sun.setOffsetX(offsetX);
    sun.setOffsetY(offsetY);
}

void ofApp::turnOtherOff(int except) {
    for (auto& planet: planets) {
        if (planet.first != except)
        planet.second->setOn(false);
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

void ofApp::fadeTimeChanged(float &fadeTime) {
    for (auto& planet: planets) {
       planet.second->setFadeTime(fadeTime);
    }
}
