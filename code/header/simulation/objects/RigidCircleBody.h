//
// Created by christopher on 2023-04-09.
//

#ifndef PHYSICS_SIMULATIONS_RIGIDCIRCLEBODY_H
#define PHYSICS_SIMULATIONS_RIGIDCIRCLEBODY_H


#include <SFML/Graphics/CircleShape.hpp>
#include "../../../src/math/Vector2D.h"

class RigidCircleBody {
public:
    explicit RigidCircleBody(int objectId, double density, Vector2D initialVelocity, Vector2D initialPosition,
                             sf::CircleShape circleShape);

    int getObjectId() const;

    sf::CircleShape &getShape();

    void updatePosition(Vector2D currentPosition);

    void updateVelocity(Vector2D currentVelocity);

    double getMass();

    Vector2D getPosition();

    Vector2D getVelocity();

private:
    Vector2D velocity;
    Vector2D position;
    double mass;
    double density;
    int objectId;
    sf::CircleShape circleShape;
};


#endif //PHYSICS_SIMULATIONS_RIGIDCIRCLEBODY_H
