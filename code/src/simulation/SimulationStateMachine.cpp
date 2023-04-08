//
// Created by christopher on 2023-04-08.
//

#include "../../header/simulation/SimulationStateMachine.h"
#include "../../header/simulation/SimulationConfig.h"
#include "../../header/utils/ObjectUtil.h"

SimulationStateMachine::SimulationStateMachine(SimulationConfig simulationConfig) :
        simulationConfig(simulationConfig) {
    initObjects();
}

void SimulationStateMachine::initObjects() {
    for (int i = 0; i < simulationConfig.getNrOfObjects(); i++) {
        objects.push_back(
                ObjectUtil::createObject(i, 1.0, simulationConfig.getXBoundary(), simulationConfig.getYBoundary())
        );
    }
}

void SimulationStateMachine::iterateSimulation() {
}

void SimulationStateMachine::restartSimulation() {
    objects.clear();
    initObjects();
}

std::vector<PhysicsObjectDetails> &SimulationStateMachine::getObjects() {
    return objects;
}

