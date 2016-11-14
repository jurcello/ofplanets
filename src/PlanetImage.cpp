//
//  PlanetImage.cpp
//  sunMachine
//
//  Created by Jur de Vries on 14/11/16.
//
//

#include "PlanetImage.h"

void PlanetImage::setup(string imageName) {

    image.load(imageName);
    width = image.getWidth();
    height = image.getHeight();
    
    colorImage.allocate(width, height);
    colorImage.setFromPixels(image.getPixels());
    greyScaleImage.allocate(width, height);
    
    findContours();
}

void PlanetImage::update() {
    if (shouldUpdate()) {
        updateFading();
        // End of update fading behaviour.
        updateTranslation();
    }

}

void PlanetImage::draw() {
    if (shouldUpdate()) {
        ofSetColor(255, 255, 255, opacity);
        image.draw(moonTranslate, newWidth, newHeight);
        ofSetColor(255, 255, 255, 255);
    }
}

void PlanetImage::findContours() {
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
}


void PlanetImage::updateTranslation() {
    if (contour.nBlobs > 0) {
        // Now correct for the radius we want.
        double factorX = radius / contour.blobs[0].boundingRect.width;
        double factorY = radius / contour.blobs[0].boundingRect.height;
        
        // Calculate the translation.
        moonTranslate.x = ofWindowSettings().width/2 - contour.blobs[0].centroid.x * factorX;
        moonTranslate.y = ofWindowSettings().height/2 - contour.blobs[0].centroid.y * factorY;

        
        // As a last thing: add the offsets.
        moonTranslate.x += offsetX;
        moonTranslate.y += offsetY;
        
        newWidth = factorX * width;
        newHeight = factorY * height;
    }
}