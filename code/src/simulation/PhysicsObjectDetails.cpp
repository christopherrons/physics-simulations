//
// Created by christopher on 2023-04-08.
//

#include "../../header/simulation/PhysicsObjectDetails.h"
#include "../../header/utils/MathUtils.h"


PhysicsObjectDetails::PhysicsObjectDetails(int id, sf::CircleShape &object, double density) :
        id(id),
        object(object),
        density(density) {
    this->mass = MathUtils::calculateVolumeOfSphere(object.getRadius()) * density;
}

double PhysicsObjectDetails::getMass() {
    return mass;
}

sf::CircleShape PhysicsObjectDetails::getObject() {
    return object;
}
