//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_PHYSICSOBJECTDETAILS_H
#define PHYSICS_SIMULATIONS_PHYSICSOBJECTDETAILS_H


#include <SFML/Graphics/CircleShape.hpp>

class PhysicsObjectDetails {

public:
    explicit PhysicsObjectDetails(int id, sf::CircleShape &object, double density);

    sf::CircleShape getObject();

    double getMass();

    double getDensity();

private:
    sf::CircleShape object;
    double mass;
    double density;
    int id;
};


#endif //PHYSICS_SIMULATIONS_PHYSICSOBJECTDETAILS_H
