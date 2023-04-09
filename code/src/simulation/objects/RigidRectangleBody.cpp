//
// Created by christopher on 2023-04-08.
//

#include "../../../header/simulation/objects/RigidRectangleBody.h"
#include "../../../header/utils/MathUtils.h"
#include "../../../header/utils/ObjectUtil.h"

RigidRectangleBody::RigidRectangleBody(int objectId, double density, sf::RectangleShape rectangleShape) :
        objectId(objectId),
        rectangleShape(rectangleShape),
        density(density) {
    this->mass =
            MathUtils::calculateVolumeOfRectangle(rectangleShape.getSize().x, rectangleShape.getSize().y, 1.0) *
            density;
}

int RigidRectangleBody::getObjectId() const {
    return objectId;
}

sf::RectangleShape &RigidRectangleBody::getShape() {
    return rectangleShape;
}