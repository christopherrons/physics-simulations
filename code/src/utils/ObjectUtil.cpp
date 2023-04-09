//
// Created by christopher on 2023-04-08.
//

#include "../../header/utils/ObjectUtil.h"
#include "../../header/simulation/objects/RigidRectangleBody.h"
#include "../../header/simulation/objects/RigidCircleBody.h"

/*PhysicsObjectDetails ObjectUtil::createObject(int id, double density, int xBoundary, int yBoundary) {
    sf::CircleShape circle = createCircle(xBoundary, yBoundary);
    return PhysicsObjectDetails(id, circle, density);
}*/

RigidCircleBody ObjectUtil::createCircle(int objectId, int xBoundary, int yBoundary) {
    sf::CircleShape circleShape;
    double radius = MathUtils::getUniformRandomNumber(3, 10);
    circleShape.setRadius(radius);
    circleShape.setPosition(MathUtils::getUniformRandomNumber(0, xBoundary - radius),
                            MathUtils::getUniformRandomNumber(0, yBoundary - radius)
    );
    return RigidCircleBody(objectId, 1.0, circleShape);
}

RigidRectangleBody ObjectUtil::createRectangle(int objectId,
                                               float xSize,
                                               float ySize,
                                               float xPosition,
                                               float yPosition) {
    sf::RectangleShape rectangleShape;
    rectangleShape.setSize({xSize, ySize});
    rectangleShape.setPosition({xPosition, yPosition});

    rectangleShape.setFillColor({255, 255, 255});
    return RigidRectangleBody(objectId, 1.0, rectangleShape);
}


