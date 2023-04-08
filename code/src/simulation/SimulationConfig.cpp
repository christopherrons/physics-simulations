//
// Created by christopher on 2023-04-08.
//

#include "../../header/simulation/SimulationConfig.h"

SimulationConfig::SimulationConfig(int nrOfObjects, int frameRate, int xBoundary, int yBoundary) :
        nrOfObjects(nrOfObjects),
        frameRate(frameRate),
        xBoundary(xBoundary),
        yBoundary(yBoundary) {
}

int SimulationConfig::getNrOfObjects() const {
    return nrOfObjects;
}

int SimulationConfig::getFrameRate() const {
    return frameRate;
}

int SimulationConfig::getXBoundary() const {
    return xBoundary;
}

int SimulationConfig::getYBoundary() const {
    return yBoundary;
}