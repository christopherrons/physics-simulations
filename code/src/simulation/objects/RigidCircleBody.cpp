//
// Created by christopher on 2023-04-09.
//

#include "../../../header/simulation/objects/RigidCircleBody.h"
#include "../../../header/utils/MathUtils.h"
#include "../../math/Vector2D.h"

RigidCircleBody::RigidCircleBody(int objectId,
                                 double density,
                                 Vector2D initialVelocity,
                                 Vector2D initialPosition,
                                 sf::CircleShape circleShape) :
        objectId(objectId),
        density(density),
        velocity(initialVelocity),
        position(initialPosition),
        circleShape(circleShape) {
    this->mass = MathUtils::calculateVolumeOfSphere(circleShape.getRadius()) * density;
}

int RigidCircleBody::getObjectId() const {
    return objectId;
}

sf::CircleShape &RigidCircleBody::getShape() {
    circleShape.setPosition(position.x(), position.y());
    return circleShape;
}

void RigidCircleBody::updatePosition(Vector2D currentPosition) {
    position.setX(currentPosition.x());
    position.setY(currentPosition.y());
}

void RigidCircleBody::updateVelocity(Vector2D currentVelocity) {
    position.setX(currentVelocity.x());
    position.setY(currentVelocity.y());
}
