//
// Created by christopher on 2023-04-08.
//

#include "../../header/simulation/SimulationConfig.h"

SimulationConfig::SimulationConfig(int nrOfObjects, int frameRate, int xMinBoundary, int yMinBoundary, int xMaxBoundary,
                                   int yMaxBoundary, double maxVelocity) :
        nrOfObjects(nrOfObjects),
        frameRate(frameRate),
        deltaTime(1.0 / frameRate),
        xMinBoundary(xMinBoundary),
        yMinBoundary(yMinBoundary),
        xMaxBoundary(xMaxBoundary),
        yMaxBoundary(yMaxBoundary),
        maxVelocity(maxVelocity) {
}

int SimulationConfig::getNrOfObjects() const {
    return nrOfObjects;
}

int SimulationConfig::getFrameRate() const {
    return frameRate;
}

int SimulationConfig::getXMinBoundary() const {
    return xMinBoundary;
}

int SimulationConfig::getYMinBoundary() const {
    return yMinBoundary;
}

int SimulationConfig::getXMaxBoundary() const {
    return xMaxBoundary;
}

int SimulationConfig::getYMaxBoundary() const {
    return yMaxBoundary;
}

double SimulationConfig::getDeltaTime() const {
    return deltaTime;
}

double SimulationConfig::getMaxVelocity() const {
    return maxVelocity;
}
