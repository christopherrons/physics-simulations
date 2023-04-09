//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_RIGIDRECTANGLEBODY_H
#define PHYSICS_SIMULATIONS_RIGIDRECTANGLEBODY_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "RigidBody.h"

class RigidRectangleBody {
public:
    explicit RigidRectangleBody(int objectId, double density, sf::RectangleShape rectangleShape);

    int getObjectId() const;

    sf::RectangleShape &getShape();

private:
    double mass;
    double density;
    int objectId;
    sf::RectangleShape rectangleShape;
};


#endif //PHYSICS_SIMULATIONS_RIGIDRECTANGLEBODY_H
