//
// Created by christopher on 2023-04-09.
//

#ifndef PHYSICS_SIMULATIONS_RIGIDCIRCLEBODY_H
#define PHYSICS_SIMULATIONS_RIGIDCIRCLEBODY_H


#include <SFML/Graphics/CircleShape.hpp>
#include "../../math/Vector2D.h"

class RigidCircleBody {
public:
    explicit RigidCircleBody(int objectId, double density, double maxVelocity, Vector2D initialAcceleration,
                             Vector2D initialVelocity,
                             Vector2D initialPosition,
                             sf::CircleShape circleShape);

    int getObjectId() const;

    sf::CircleShape &getShape();

    void updatePositionX(double x);

    void updatePositionY(double y);

    void updateVelocityX(double x);

    void updateVelocityY(double y);

    double getPositionX();

    double getPositionY();

    double getVelocityX();

    double getVelocityY();

    double getMass() const;

    Vector2D getPositionCopy();

    Vector2D getVelocityCopy();

    Vector2D getAccelerationCopy();

    double getRadius();


private:
    Vector2D velocity;
    Vector2D position;
    Vector2D acceleration;
    double mass;
    double density;
    double maxVelocity;
    int objectId;
    sf::CircleShape circleShape;
};


#endif //PHYSICS_SIMULATIONS_RIGIDCIRCLEBODY_H
