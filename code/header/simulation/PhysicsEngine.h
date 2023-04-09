//
// Created by christopher on 2023-04-09.
//

#ifndef PHYSICS_SIMULATIONS_PHYSICSENGINE_H
#define PHYSICS_SIMULATIONS_PHYSICSENGINE_H


#include "SimulationConfig.h"
#include "objects/RigidCircleBody.h"

class PhysicsEngine {
public:
    explicit PhysicsEngine(SimulationConfig &simulationConfig);

    void updateState(std::vector<RigidCircleBody> &bodies);

private:
    void handleCollisions(RigidCircleBody &body);

    void handleBodyCollisions(RigidCircleBody &bodyA, RigidCircleBody &bodyB);

    void handleWallCollision(RigidCircleBody &body);

    bool areColliding(RigidCircleBody &circleA, RigidCircleBody &circleB);

    Vector2D velocityAfterCollision(Vector2D &velocityOne, Vector2D &positionOne, double massOne, Vector2D &velocityTwo,
                                    Vector2D &positionTwo, double massTwo);

private:
    SimulationConfig &simulationConfig;
};


#endif //PHYSICS_SIMULATIONS_PHYSICSENGINE_H
