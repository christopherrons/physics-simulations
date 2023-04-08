//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_OBJECTUTIL_H
#define PHYSICS_SIMULATIONS_OBJECTUTIL_H

#include <SFML/Graphics.hpp>
#include "../../header/utils/MathUtils.h"
#include "../simulation/PhysicsObjectDetails.h"

class ObjectUtil {
public:
    static sf::CircleShape createCircle(int xBoundary, int yBoundary);

    static PhysicsObjectDetails createObject(int id, double density, int xBoundary, int yBoundary);
};


#endif //PHYSICS_SIMULATIONS_OBJECTUTIL_H
