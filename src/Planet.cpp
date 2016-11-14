//
//  Planet.cpp
//  sunMachine
//
//  Created by Jur de Vries on 14/11/16.
//
//

#include "Planet.h"

void Planet::setRadius(int newRadius) {
    radius = newRadius;
}

void Planet::setOffsetX(int offset) {
    offsetX = offset;
}

void Planet::setOffsetY(int offset) {
    offsetY = offset;
}

bool Planet::isOn() {
    return on;
}

void Planet::setOn(bool isOn) {
    if (on != isOn) {
        stateChangedTime = ofGetElapsedTimeMillis();
        changing = true;
    }
    on = isOn;
}

void Planet::setFadeTime(float newFadeTime) {
    fadeTime = newFadeTime;
}

bool Planet::shouldUpdate() {
    return isOn() || (!isOn() && changing);
}

void Planet::updateFading() {
    if (changing) {
        float currentTime = ofGetElapsedTimeMillis();
        // Get the ratio for the fade.
        float ratio = (currentTime - stateChangedTime) / fadeTime;
        // If the ratio is bigger than one, the fade is finished.
        if (ratio > 1) {
            changing = false;
            ratio = 1;
        }
        opacity = on ? ratio * 255 : (1 - ratio) * 255;
    }
}