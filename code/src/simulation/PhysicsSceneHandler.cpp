//
// Created by christopher on 2023-04-08.
//

#include <iostream>
#include "../../header/simulation/PhysicsSceneHandler.h"
#include "../../header/utils/ObjectUtil.h"

PhysicsSceneHandler::PhysicsSceneHandler(SimulationConfig &simulationConfig) :
        simulationConfig(simulationConfig),
        physicsEngine(PhysicsEngine(simulationConfig)) {
    initBodies();
}

void PhysicsSceneHandler::initBodies() {
    for (int i = 0; i < simulationConfig.getNrOfObjects(); i++) {
        bodies.push_back(
                ObjectUtil::createCircle(
                        bodies.size(),
                        simulationConfig.getXMinBoundary(),
                        simulationConfig.getYMinBoundary(),
                        simulationConfig.getXMaxBoundary(),
                        simulationConfig.getYMaxBoundary(),
                        simulationConfig.getMaxVelocity()
                )
        );
    }
}

void PhysicsSceneHandler::updateScene() {
    physicsEngine.updateState(bodies);
}

void PhysicsSceneHandler::restartSimulation() {
    bodies.clear();
    initBodies();
}

std::vector<RigidCircleBody> &PhysicsSceneHandler::getBodies() {
    return bodies;
}

