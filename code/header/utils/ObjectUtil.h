//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_OBJECTUTIL_H
#define PHYSICS_SIMULATIONS_OBJECTUTIL_H

#include <SFML/Graphics.hpp>
#include "../../header/utils/MathUtils.h"
#include "../simulation/objects/RigidRectangleBody.h"
#include "../simulation/objects/RigidCircleBody.h"

class ObjectUtil {
public:
    static RigidCircleBody createCircle(int objectId, int xMinBoundary, int yMinBoundary, int xMaxBoundary,
                                        int yMaxBoundary, double maxVelocity);

    static sf::Color getColorInterpolated(double velocityAbsolute, double maxVelocity);

    static RigidRectangleBody createRectangle(int objetId, float xSize, float ySize, float xPosition, float yPosition);
};


#endif //PHYSICS_SIMULATIONS_OBJECTUTIL_H
