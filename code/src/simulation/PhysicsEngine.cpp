//
// Created by christopher on 2023-04-09.
//

#include "../../header/simulation/PhysicsEngine.h"
#include <cmath>
#include <map>

PhysicsEngine::PhysicsEngine(SimulationConfig &simulationConfig) :
        simulationConfig(simulationConfig) {
    initGrid();
}

void PhysicsEngine::initGrid() {
    double nrOfGridsPerRow = simulationConfig.getNrOfGridsPerRowAndColumn();
    double nrOfGridsPerColumn = simulationConfig.getNrOfGridsPerRowAndColumn();

    double xOffset = simulationConfig.getXMaxBoundary() / nrOfGridsPerColumn;
    double yOffset = simulationConfig.getYMaxBoundary() / nrOfGridsPerRow;
    for (int row = 0; row < nrOfGridsPerRow; row++) {
        for (int column = 0; column < nrOfGridsPerColumn; column++) {
            grids.emplace_back(
                    grids.size(),
                    xOffset * column,
                    yOffset * row,
                    xOffset * (1 + column),
                    yOffset * (1 + row)
            );
        }
    }
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

    handleCollisions(bodies);
}

void PhysicsEngine::handleCollisions(std::vector<RigidCircleBody> &bodies) {

    std::map<int, std::vector<std::reference_wrapper<RigidCircleBody>>> gridIdToBodyInGrid;
    for (auto &body: bodies) {
        for (auto &grid: grids) {
            if (grid.isInGrid(body.getPositionX() + body.getRadius(), body.getPositionY() + body.getRadius()) ||
                grid.isInGrid(body.getPositionX(), body.getPositionY())) {
                gridIdToBodyInGrid[grid.getGridId()].emplace_back(body);
            }
        }
    }

    for (auto &gridItemPairs: gridIdToBodyInGrid) {
        if (gridItemPairs.second.size() < 2) {
            continue;
        }
        handleBodyCollisions(gridItemPairs.second);
    }

    for (auto &body: bodies) {
        handleWallCollision(body);
    }
}


void PhysicsEngine::handleBodyCollisions(std::vector<std::reference_wrapper<RigidCircleBody>> &bodies) {
    for (auto &bodyA: bodies) {
        for (auto &bodyB: bodies) {
            if (bodyA.get().getObjectId() == bodyB.get().getObjectId() || !areColliding(bodyA, bodyB)) {
                continue;
            }
            disIntersectCollidingBodies(bodyA, bodyB);
            updatePostCollisionVelocity(bodyA, bodyB);
        }
    }
}

void PhysicsEngine::disIntersectCollidingBodies(RigidCircleBody &bodyA, RigidCircleBody &bodyB) {
    Vector2D positionA = bodyA.getPositionCopy();
    Vector2D positionB = bodyB.getPositionCopy();

    Vector2D directionVectorAB = positionB.subtract(positionA);
    Vector2D directionVectorBA = positionA.subtract(positionB);
    double distance = directionVectorAB.magnitude();

    Vector2D directionVectorNormalizedAB = directionVectorAB.scalar(1 / distance);
    Vector2D directionVectorNormalizedBA = directionVectorBA.scalar(1 / distance);
    double positionCorrection = (bodyA.getRadius() + bodyB.getRadius() - distance) / 2.0;

    bodyA.updatePositionX(bodyA.getPositionX() + directionVectorNormalizedAB.getX() * -positionCorrection);
    bodyA.updatePositionY(bodyA.getPositionY() + directionVectorNormalizedAB.getY() * -positionCorrection);

    bodyB.updatePositionX(bodyB.getPositionX() + directionVectorNormalizedBA.getX() * -positionCorrection);
    bodyB.updatePositionY(bodyB.getPositionY() + directionVectorNormalizedBA.getY() * -positionCorrection);
}

void PhysicsEngine::updatePostCollisionVelocity(RigidCircleBody &bodyA, RigidCircleBody &bodyB) {
    Vector2D positionA = bodyA.getPositionCopy();
    Vector2D velocityA = bodyA.getVelocityCopy();

    Vector2D velocityB = bodyB.getVelocityCopy();
    Vector2D positionB = bodyB.getPositionCopy();

    double massA = bodyA.getMass();
    double massB = bodyB.getMass();

    Vector2D velocityAfterCollisionA = velocityAfterCollision(velocityA, positionA, massA, velocityB, positionB,
                                                              massB);
    Vector2D velocityAfterCollisionB = velocityAfterCollision(velocityB, positionB, massB, velocityA, positionA,
                                                              massA);

    bodyA.updateVelocityX(velocityAfterCollisionA.getX());
    bodyA.updateVelocityY(velocityAfterCollisionA.getY());

    bodyB.updateVelocityX(velocityAfterCollisionB.getX());
    bodyB.updateVelocityY(velocityAfterCollisionB.getY());
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
    return distance + 0.0001 <= circleA.getRadius() + circleB.getRadius();
}

Vector2D PhysicsEngine::velocityAfterCollision(Vector2D &velocityOne, Vector2D &positionOne, double massOne,
                                               Vector2D &velocityTwo, Vector2D &positionTwo, double massTwo) {
    Vector2D direction = positionOne.subtract(positionTwo);
    Vector2D velocityDirection = velocityOne.subtract(velocityTwo);
    double massRatio = (2 * massTwo) / (massOne + massTwo);
    double scalar = massRatio *
                    velocityDirection.dot(direction) /
                    direction.dot(direction);
    return velocityOne.subtract(direction.scalar(scalar));
}


