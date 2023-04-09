//
// Created by christopher on 2023-04-09.
//

#include "../../../header/simulation/objects/RigidCircleBody.h"
#include "../../../header/utils/MathUtils.h"
#include "../../../header/utils/ObjectUtil.h"
#include "../../../header/math/Vector2D.h"


RigidCircleBody::RigidCircleBody(int objectId,
                                 double density,
                                 double maxVelocity,
                                 Vector2D initialAcceleration,
                                 Vector2D initialVelocity,
                                 Vector2D initialPosition,
                                 sf::CircleShape circleShape) :
        objectId(objectId),
        density(density),
        maxVelocity(maxVelocity),
        acceleration(initialAcceleration),
        velocity(initialVelocity),
        position(initialPosition),
        circleShape(circleShape) {
    this->mass = MathUtils::calculateVolumeOfSphere(circleShape.getRadius()) * density;
}

int RigidCircleBody::getObjectId() const {
    return objectId;
}

sf::CircleShape &RigidCircleBody::getShape() {
    circleShape.setFillColor(ObjectUtil::getColorInterpolated(velocity.magnitude(), maxVelocity));
    return circleShape;
}

void RigidCircleBody::updatePositionX(double x) {
    circleShape.setPosition(x, circleShape.getPosition().y);
    position.setX(x);
}

void RigidCircleBody::updatePositionY(double y) {
    circleShape.setPosition(circleShape.getPosition().x, y);
    position.setY(y);
}

void RigidCircleBody::updateVelocityX(double x) {
    if (abs(x) > maxVelocity) {
        velocity.setX(maxVelocity);
    } else {
        velocity.setX(x);
    }
}

void RigidCircleBody::updateVelocityY(double y) {
    if (abs(y) > maxVelocity) {
        velocity.setY(maxVelocity);
    } else {
        velocity.setY(y);
    }
}

double RigidCircleBody::getPositionX() {
    return position.getX();
}

double RigidCircleBody::getPositionY() {
    return position.getY();
}

Vector2D RigidCircleBody::getPositionCopy() {
    return position;
}

double RigidCircleBody::getVelocityX() {
    return velocity.getX();
}

double RigidCircleBody::getVelocityY() {
    return velocity.getY();
}

Vector2D RigidCircleBody::getVelocityCopy() {
    return velocity;
}

Vector2D RigidCircleBody::getAccelerationCopy() {
    return acceleration;
}

double RigidCircleBody::getMass() const {
    return mass;
}

double RigidCircleBody::getRadius() {
    return circleShape.getRadius();
}



