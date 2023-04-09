//
// Created by christopher on 2023-04-08.
//

#include "../../header/simulation/PhysicsSceneHandler.h"
#include "../../header/utils/ObjectUtil.h"

PhysicsSceneHandler::PhysicsSceneHandler(SimulationConfig simulationConfig) :
        simulationConfig(simulationConfig) {
    initWalls();
    initBodies();
}

void PhysicsSceneHandler::initBodies() {
    for (int i = 0; i < simulationConfig.getNrOfObjects(); i++) {
        bodies.push_back(
                ObjectUtil::createCircle(walls.size() + bodies.size(), simulationConfig.getXBoundary(),
                                         simulationConfig.getYBoundary())
        );
    }
}

void PhysicsSceneHandler::initWalls() {
    float wallThickness = 1.0;
    float height = simulationConfig.getYBoundary();
    float width = simulationConfig.getXBoundary();

    walls.push_back(ObjectUtil::createRectangle(walls.size(), wallThickness, height, 0, 0));
    walls.push_back(ObjectUtil::createRectangle(walls.size(), wallThickness, height, width - 1, 0));
    walls.push_back(ObjectUtil::createRectangle(walls.size(), width, wallThickness, 0, 0));
    walls.push_back(ObjectUtil::createRectangle(walls.size(), width, wallThickness, 0, height - 1));
}

void PhysicsSceneHandler::updateScene() {
    for (int i = 0; i < bodies.size(); i++) {
        for(int j = 0; j < bodies.size(); j++) {
            if (i == j) {
                continue;
            }

        }
    }
}

void PhysicsSceneHandler::restartSimulation() {
    bodies.clear();
    initBodies();
}

std::vector<RigidRectangleBody> &PhysicsSceneHandler::getWalls() {
    return walls;
}

std::vector<RigidCircleBody> &PhysicsSceneHandler::getBodies() {
    return bodies;
}

