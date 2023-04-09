//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_PHYSICSSCENEHANDLER_H
#define PHYSICS_SIMULATIONS_PHYSICSSCENEHANDLER_H

#include <SFML/Graphics.hpp>
#include "SimulationConfig.h"
#include "objects/RigidBody.h"
#include "objects/RigidRectangleBody.h"
#include "objects/RigidCircleBody.h"
#include "PhysicsEngine.h"

class PhysicsSceneHandler {
public:
    explicit PhysicsSceneHandler(SimulationConfig &simulationConfig);

    void updateScene();

    void restartSimulation();

    std::vector<RigidCircleBody> &getBodies();

private:
    void initBodies();

private:
    SimulationConfig &simulationConfig;
    PhysicsEngine physicsEngine;
    std::vector<RigidCircleBody> bodies;
};


#endif //PHYSICS_SIMULATIONS_PHYSICSSCENEHANDLER_H
