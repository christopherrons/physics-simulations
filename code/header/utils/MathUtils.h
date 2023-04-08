//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_MATHUTILS_H
#define PHYSICS_SIMULATIONS_MATHUTILS_H

#include <math.h>

class MathUtils {
public:
    static double getUniformRandomNumber(double min, double max);

    static double calculateAreaOfCircle(double radius) {
        return 2 * M_PI * radius * radius;
    }

    static double calculateVolumeOfSphere(double radius) {
        return 4.0 / 3 * M_PI * radius * radius * radius;
    }
};


#endif //PHYSICS_SIMULATIONS_MATHUTILS_H
