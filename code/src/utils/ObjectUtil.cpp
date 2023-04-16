//
// Created by christopher on 2023-04-08.
//

#include "../../header/utils/ObjectUtil.h"


RigidCircleBody ObjectUtil::createCircle(int objectId, int xMinBoundary, int yMinBoundary, int xMaxBoundary,
                                         int yMaxBoundary, double maxVelocity) {
    sf::CircleShape circleShape;
    double radius = std::round(MathUtils::getUniformRandomNumber(2, 8) * 1000.0) / 1000.0;
    circleShape.setRadius(radius);
    circleShape.setOrigin(radius, radius);

    Vector2D initialAcceleration(0, 0);
    Vector2D initialVelocity(MathUtils::getNormalRandomNumber(0, maxVelocity / 2),
                             MathUtils::getNormalRandomNumber(0, maxVelocity / 2));
    Vector2D initialPosition(MathUtils::getUniformRandomNumber(xMinBoundary + radius, xMaxBoundary - radius),
                             MathUtils::getUniformRandomNumber(yMinBoundary + radius, yMaxBoundary - radius));

    return RigidCircleBody(objectId, 1.0, maxVelocity, initialAcceleration, initialVelocity, initialPosition,
                           circleShape);
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

sf::Color ObjectUtil::getColorInterpolated(double velocityAbsolute, double maxVelocity) {
    sf::Uint8 alpha = 255;
    double slowVelocity = 0.30;
    double mediumVelocity = 0.60;
    double fastVelocity = 0.90;

    double velocity = velocityAbsolute / sqrt(maxVelocity * maxVelocity + maxVelocity * maxVelocity);
    if (velocity < slowVelocity) {
        sf::Uint8 red = MathUtils::linearInterpolation(velocity, 0.0, slowVelocity, 0, 66);
        sf::Uint8 green = MathUtils::linearInterpolation(velocity, 0.0, slowVelocity, 0, 107);
        sf::Uint8 blue = MathUtils::linearInterpolation(velocity, 0.0, slowVelocity, 100, 200);
        return {red, green, blue, alpha};

    } else if (velocity >= slowVelocity && velocity < mediumVelocity) {
        sf::Uint8 red = MathUtils::linearInterpolation(velocity, slowVelocity, mediumVelocity, 66, 200);
        sf::Uint8 green = MathUtils::linearInterpolation(velocity, slowVelocity, mediumVelocity, 107, 200);
        sf::Uint8 blue = MathUtils::linearInterpolation(velocity, slowVelocity, mediumVelocity, 200, 230);
        return {red, green, blue, alpha};

    } else if (velocity >= mediumVelocity && velocity < fastVelocity) {
        sf::Uint8 red = MathUtils::linearInterpolation(velocity, mediumVelocity, fastVelocity, 200, 255);
        sf::Uint8 green = MathUtils::linearInterpolation(velocity, mediumVelocity, fastVelocity, 200, 255);
        sf::Uint8 blue = MathUtils::linearInterpolation(velocity, mediumVelocity, fastVelocity, 230, 255);
        return {red, green, blue, alpha};
    }

    return {255, 255, 255, alpha};
}


