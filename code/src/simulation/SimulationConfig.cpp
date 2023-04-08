//
// Created by christopher on 2023-04-08.
//

#include "../../header/simulation/SimulationConfig.h"

SimulationConfig::SimulationConfig(int nrOfObjects, int frameRate) :
        nrOfObjects(nrOfObjects),
        frameRate(frameRate) {
}

int SimulationConfig::getNrOfObjects() const {
    return this->nrOfObjects;
}

int SimulationConfig::getFrameRate() const {
    return this->frameRate;
}