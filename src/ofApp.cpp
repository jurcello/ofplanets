#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    moonVideo.load("Mercury.mp4");
    moonVideo.play();
    moonVideo.setLoopState(OF_LOOP_NORMAL);
    moonWidth = moonVideo.getWidth();
    moonHeight = moonVideo.getHeight();
    
    moonColor.allocate(moonWidth, moonHeight);
    moonGrey.allocate(moonWidth, moonHeight);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    moonVideo.update();
    
    if (moonVideo.isFrameNew()) {
        // Update the color image.
        moonColor.setFromPixels(moonVideo.getPixels());
        // Set the grey scale image from the color image.
        moonGrey = moonColor;
        
        ofPixels blackWhite = moonGrey.getPixels();
        ofPixels original = moonGrey.getPixels();
        for (int i = 0; i < original.size(); i++) {
            blackWhite[i] = original[i] < 30 ? 0 : 255;
        }
        moonGrey.setFromPixels(blackWhite);
        
        
        // Find the contours.
        moonContour.findContours(moonGrey, moonWidth*moonHeight / 7, moonWidth*moonHeight, 10, false);

        if (moonContour.nBlobs > 0) {
            // Calculate the translation.
            moonTranslate.x = ofWindowSettings().width/2 - moonContour.blobs[0].centroid.x;
            moonTranslate.y = ofWindowSettings().height/2 - moonContour.blobs[0].centroid.y;
            
            // Now correct for the radius we want.
            float factorX = radius / moonContour.blobs[0].boundingRect.width;
            float factorY = radius / moonContour.blobs[0].boundingRect.height;
            
            moonTranslate.x += (moonVideo.getWidth() / 2) * (1 - factorX);
            moonTranslate.y += (moonVideo.getHeight() / 2) * (1 - factorY);
            
            moonNewWidth = factorX * moonVideo.getWidth();
            moonNewHeight = factorY * moonVideo.getHeight();
            
            cout << "Moon new width: " << moonNewWidth << ",factorX: " << factorX << ", trans x" << moonTranslate.x << "\n";
        }

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    moonVideo.draw(moonTranslate, moonNewWidth, moonNewHeight);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
