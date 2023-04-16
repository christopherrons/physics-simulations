//
// Created by christopher on 2023-04-08.
//

#include <random>
#include "../../header/utils/MathUtils.h"

double MathUtils::getUniformRandomNumber(const double min, const double max) {
    std::random_device randomDevice;
    std::default_random_engine generator(randomDevice());
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}

double MathUtils::getNormalRandomNumber(const double mean, const double std) {
    std::random_device randomDevice;
    std::default_random_engine generator(randomDevice());
    std::normal_distribution<double> distribution(mean, std);
    return distribution(generator);
}

double MathUtils::calculateAreaOfCircle(double radius) {
    return 2 * M_PI * radius * radius;
}

double MathUtils::calculateVolumeOfSphere(double radius) {
    return 4.0 / 3 * M_PI * radius * radius * radius;
}

double MathUtils::calculateAreaOfRectangle(double width, double height) {
    return width * height;
}

double MathUtils::calculateVolumeOfRectangle(double width, double height, double depth) {
    return width * height * depth;
}

double MathUtils::scaleValue(double value, double minValue, double maxValue, double scaleMin, double scaleMax) {
    return scaleMin + ((value - minValue) / (maxValue - minValue)) * (scaleMax - scaleMin);
}

double MathUtils::linearInterpolation(double x, double x0, double x1, double y0, double y1) {
    double rise = y0 * (x1 - x) + y1 * (x - x0);
    double run = x1 - x0;
    return rise / run;
}