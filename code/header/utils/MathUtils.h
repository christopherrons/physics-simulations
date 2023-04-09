//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_MATHUTILS_H
#define PHYSICS_SIMULATIONS_MATHUTILS_H

#include <math.h>

class MathUtils {
public:
    static double getUniformRandomNumber(double min, double max);

    static double calculateAreaOfCircle(double radius);

    static double calculateVolumeOfSphere(double radius);

    static double calculateAreaOfRectangle(double width, double height);

    static double calculateVolumeOfRectangle(double width, double height, double depth);
};


#endif //PHYSICS_SIMULATIONS_MATHUTILS_H
