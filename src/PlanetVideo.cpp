//
//  PlanetVideo.cpp
//  sunMachine
//
//  Created by Jur de Vries on 11/11/16.
//
//

#include "PlanetVideo.h"

void PlanetVideo::setup(string videoName) {
    video.load(videoName);
    video.play();
    video.setLoopState(OF_LOOP_NORMAL);
    width = video.getWidth();
    height = video.getHeight();
    
    colorImage.allocate(width, height);
    greyScaleImage.allocate(width, height);
}

void PlanetVideo::update() {
    video.update();
    
    if (video.isFrameNew()) {
        // Update the fading behaviour.
        updateFading();
        // End of update fading behaviour.
        updateTranslation();
    }
}

void PlanetVideo::draw() {
    ofSetColor(255, 255, 255, opacity);
    video.draw(moonTranslate, newWidth, newHeight);
    ofSetColor(255, 255, 255, 255);
}

void PlanetVideo::updateTranslation() {
    // Update the color image.
    colorImage.setFromPixels(video.getPixels());
    // Set the grey scale image from the color image.
    greyScaleImage = colorImage;
    
    ofPixels blackWhite = greyScaleImage.getPixels();
    ofPixels original = greyScaleImage.getPixels();
    for (int i = 0; i < original.size(); i++) {
        blackWhite[i] = original[i] < 30 ? 0 : 255;
    }
    greyScaleImage.setFromPixels(blackWhite);
    
    
    // Find the contours.
    contour.findContours(greyScaleImage, width*height / 7, width*height, 10, false);
    
    if (contour.nBlobs > 0) {
        // Calculate the translation.
        moonTranslate.x = ofWindowSettings().width/2 - contour.blobs[0].centroid.x;
        moonTranslate.y = ofWindowSettings().height/2 - contour.blobs[0].centroid.y;
        
        // Now correct for the radius we want.
        float factorX = radius / contour.blobs[0].boundingRect.width;
        float factorY = radius / contour.blobs[0].boundingRect.height;
        
        moonTranslate.x += (video.getWidth() / 2) * (1 - factorX);
        moonTranslate.y += (video.getHeight() / 2) * (1 - factorY);
        
        // As a last thing: add the offsets.
        moonTranslate.x += offsetX;
        moonTranslate.y += offsetY;
        
        newWidth = factorX * video.getWidth();
        newHeight = factorY * video.getHeight();
        
    }
}