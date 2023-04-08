//
// Created by christopher on 2023-04-08.
//

#include "../../header/utils/ObjectUtil.h"

PhysicsObjectDetails ObjectUtil::createObject(int id, double density, int xBoundary, int yBoundary) {
    sf::CircleShape circle = createCircle(xBoundary, yBoundary);
    return PhysicsObjectDetails(id, circle, density);
}

sf::CircleShape ObjectUtil::createCircle(int xBoundary, int yBoundary) {
    sf::CircleShape circle;
    double radius = MathUtils::getUniformRandomNumber(3, 10);
    circle.setRadius(radius);
    circle.setPosition(MathUtils::getUniformRandomNumber(0, xBoundary - radius),
                       MathUtils::getUniformRandomNumber(0, yBoundary - radius)
    );
    return circle;
}


