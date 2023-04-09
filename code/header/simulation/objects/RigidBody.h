//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_RIGIDBODY_H
#define PHYSICS_SIMULATIONS_RIGIDBODY_H


#include <SFML/Graphics/Shape.hpp>

class RigidBody {
public:
    virtual ~RigidBody() = default;

    virtual int getObjectId() const = 0;

    virtual sf::Shape &getShape();
};


#endif //PHYSICS_SIMULATIONS_RIGIDBODY_H
