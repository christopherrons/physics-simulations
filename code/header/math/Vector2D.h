//
// Created by christopher on 2023-04-09.
//

#ifndef PHYSICS_SIMULATIONS_VECTOR2D_H
#define PHYSICS_SIMULATIONS_VECTOR2D_H


class Vector2D {
public:
    explicit Vector2D(double x, double y);

    double magnitude() const;

    double getX() const;

    double getY() const;

    double dot(const Vector2D &otherVector) const;

    Vector2D add(const Vector2D &otherVector) const;

    Vector2D subtract(const Vector2D &otherVector) const;

    Vector2D scalar(const double scalar) const;

    void setX(double x);

    void setY(double y);

private:
    double x;
    double y;
};


#endif //PHYSICS_SIMULATIONS_VECTOR2D_H
