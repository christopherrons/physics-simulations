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

class PhysicsSceneHandler {
public:
    explicit PhysicsSceneHandler(SimulationConfig simulationConfig);

    void updateScene();

    void restartSimulation();

    std::vector<RigidRectangleBody> &getWalls();
    std::vector<RigidCircleBody> &getBodies();

private:
    void initWalls();

    void initBodies();

private:
    SimulationConfig simulationConfig;
    std::vector<RigidRectangleBody> walls;
    std::vector<RigidCircleBody> bodies;
};


#endif //PHYSICS_SIMULATIONS_PHYSICSSCENEHANDLER_H
