//
// Created by christopher on 2023-04-09.
//

#include "../../header/math/Vector2D.h"
#include <cmath>

Vector2D::Vector2D(double x, double y) :
        x(x),
        y(y) {
}

double Vector2D::magnitude() {
    return sqrt(pow(x, 2) + pow(y, 2));
}

double Vector2D::getX() {
    return x;
}

double Vector2D::getY() {
    return y;
}

void Vector2D::setX(double x) {
    this->x = x;
}

void Vector2D::setY(double y) {
    this->y = y;
}

Vector2D Vector2D::subtract(const Vector2D &otherVector) const {
    return Vector2D(x - otherVector.x, y - otherVector.y);
}

double Vector2D::dot(const Vector2D &otherVector) const {
    return x * otherVector.x + y * otherVector.y;
}

Vector2D Vector2D::scalar(const double scalar) const {
    return Vector2D(x * scalar, y * scalar);
}


