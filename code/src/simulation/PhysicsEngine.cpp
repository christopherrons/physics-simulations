//
// Created by christopher on 2023-04-09.
//

#include "../../header/simulation/PhysicsEngine.h"
#include <cmath>

PhysicsEngine::PhysicsEngine(SimulationConfig &simulationConfig) :
        simulationConfig(simulationConfig) {
}

void PhysicsEngine::updateState(std::vector<RigidCircleBody> &bodies) {
    double deltaTime = simulationConfig.getDeltaTime();
    for (auto &body: bodies) {
        double updatedVelocityX = body.getVelocityX(); //+ body.getAcceleration().getX() * deltaTime;
        double updatedVelocityY = body.getVelocityY(); // + body.getAcceleration().getY() * deltaTime;

        double updatedPositionX = body.getPositionX() + body.getVelocityX() * deltaTime;
        double updatedPositionY = body.getPositionY() + body.getVelocityY() * deltaTime;

        body.updateVelocityX(updatedVelocityX);
        body.updateVelocityY(updatedVelocityY);
        body.updatePositionX(updatedPositionX);
        body.updatePositionY(updatedPositionY);
    }
    for (auto &bodyA: bodies) {
        for (auto &bodyB: bodies) {
            if (bodyA.getObjectId() == bodyB.getObjectId()) {
                continue;
            }
            handleBodyCollisions(bodyA, bodyB);
        }
    }

    for (auto &body: bodies) {
        handleWallCollision(body);
    }
}

void PhysicsEngine::handleCollisions(RigidCircleBody &body) {
    handleWallCollision(body);
}

void PhysicsEngine::handleBodyCollisions(RigidCircleBody &bodyA, RigidCircleBody &bodyB) {
    if (!areColliding(bodyA, bodyB)) {
        return;
    }

    Vector2D velocityA = bodyA.getVelocityCopy();
    Vector2D positionA = bodyA.getPositionCopy();
    double massA = bodyA.getMass();

    Vector2D velocityB = bodyB.getVelocityCopy();
    Vector2D positionB = bodyB.getPositionCopy();
    double massB = bodyB.getMass();

    Vector2D velocityAfterCollisionA = velocityAfterCollision(velocityA, positionA, massA, velocityB, positionB, massB);
    Vector2D velocityAfterCollisionB = velocityAfterCollision(velocityB, positionB, massB, velocityA, positionA, massA);

    bodyA.updateVelocityX(velocityAfterCollisionA.getX());
    bodyA.updateVelocityY(velocityAfterCollisionA.getY());

    bodyB.updateVelocityX(velocityAfterCollisionB.getX());
    bodyB.updateVelocityY(velocityAfterCollisionB.getY());

    double deltaTime = simulationConfig.getDeltaTime();
    while (areColliding(bodyA, bodyB)) {
        bodyA.updatePositionX(bodyA.getPositionX() + bodyA.getVelocityX() * deltaTime);
        bodyA.updatePositionY(bodyA.getPositionY() + bodyA.getVelocityY() * deltaTime);

        bodyB.updatePositionX(bodyB.getPositionX() + bodyB.getVelocityX() * deltaTime);
        bodyB.updatePositionY(bodyB.getPositionY() + bodyB.getVelocityY() * deltaTime);
    }
}

void PhysicsEngine::handleWallCollision(RigidCircleBody &body) {

    double updatedPositionX = body.getPositionX();
    double updatedPositionY = body.getPositionY();

    if (updatedPositionX <= simulationConfig.getXMinBoundary() + body.getRadius()) {
        double updatedVelocityX = body.getVelocityX() * -1;
        updatedPositionX = simulationConfig.getXMinBoundary() + body.getRadius();
        body.updateVelocityX(updatedVelocityX);
        body.updatePositionX(updatedPositionX);
    }

    if (updatedPositionX >= simulationConfig.getXMaxBoundary() - body.getRadius()) {
        double updatedVelocityX = body.getVelocityX() * -1;
        updatedPositionX = simulationConfig.getXMaxBoundary() - body.getRadius();
        body.updateVelocityX(updatedVelocityX);
        body.updatePositionX(updatedPositionX);
    }

    if (updatedPositionY <= simulationConfig.getYMinBoundary() + body.getRadius()) {
        double updatedVelocityY = body.getVelocityY() * -1;
        updatedPositionY = simulationConfig.getYMinBoundary() + body.getRadius();
        body.updateVelocityY(updatedVelocityY);
        body.updatePositionY(updatedPositionY);
    }

    if (updatedPositionY >= simulationConfig.getYMaxBoundary() - body.getRadius()) {
        double updatedVelocityY = body.getVelocityY() * -1;
        updatedPositionY = simulationConfig.getYMaxBoundary() - body.getRadius();
        body.updateVelocityY(updatedVelocityY);
        body.updatePositionY(updatedPositionY);
    }
}

bool PhysicsEngine::areColliding(RigidCircleBody &circleA, RigidCircleBody &circleB) {
    double distance = sqrt(
            pow(circleA.getPositionX() - circleB.getPositionX(), 2) +
            pow(circleA.getPositionY() - circleB.getPositionY(), 2)
    );
    return distance <= circleA.getRadius() + circleB.getRadius();
}

Vector2D PhysicsEngine::velocityAfterCollision(Vector2D &velocityOne, Vector2D &positionOne, double massOne,
                                               Vector2D &velocityTwo, Vector2D &positionTwo, double massTwo) {
    Vector2D positionDifference = positionOne.subtract(positionTwo);
    Vector2D velocityDifference = velocityOne.subtract(velocityTwo);
    double massRatio = (2 * massTwo) / (massOne + massTwo);
    double scalar = massRatio * velocityDifference.dot(positionDifference) / positionDifference.dot(positionDifference);
    return velocityOne.subtract(positionDifference.scalar(scalar));
}






