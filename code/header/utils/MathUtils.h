//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_MATHUTILS_H
#define PHYSICS_SIMULATIONS_MATHUTILS_H

#include <math.h>

class MathUtils {
public:
    static double getUniformRandomNumber(double min, double max);

    static double getNormalRandomNumber(double mean, double std);

    static double calculateAreaOfCircle(double radius);

    static double calculateVolumeOfSphere(double radius);

    static double calculateAreaOfRectangle(double width, double height);

    static double calculateVolumeOfRectangle(double width, double height, double depth);

    static double scaleValue(double value, double minValue, double maxValue, double scaleMin, double scaleMax);

    static double linearInterpolation(double x, double x0, double x1, double y0, double y1);
};


#endif //PHYSICS_SIMULATIONS_MATHUTILS_H
