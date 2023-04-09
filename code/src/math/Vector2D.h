//
// Created by christopher on 2023-04-09.
//

#ifndef PHYSICS_SIMULATIONS_VECTOR2D_H
#define PHYSICS_SIMULATIONS_VECTOR2D_H


class Vector2D {
public:
    explicit Vector2D(double x, double y);

    double magnitude();

    double x();

    double y();

    double dot(Vector2D otherVector);

    Vector2D scalar(double scalar);

    void setX(double x);

    void setY(double y);
};


#endif //PHYSICS_SIMULATIONS_VECTOR2D_H
