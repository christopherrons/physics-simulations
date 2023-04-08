//
// Created by christopher on 2023-04-08.
//

#include "../../header/simulation/SimulationStateMachine.h"
#include "../../header/simulation/SimulationConfig.h"
#include "../../header/utils/ObjectUtil.h"

SimulationStateMachine::SimulationStateMachine(SimulationConfig simulationConfig) :
        simulationConfig(simulationConfig) {
}

void SimulationStateMachine::initObjects() {
    for (int i = 0; i < this->simulationConfig.getNrOfObjects(); i++) {
        objects.push_back(ObjectUtil::createCircle());
    }
}

void SimulationStateMachine::iterateSimulation() {
}

void SimulationStateMachine::restartSimulation() {
    objects.clear();
    initObjects();
}

std::vector<sf::CircleShape> SimulationStateMachine::getObjects() {
    return this->objects;
}

