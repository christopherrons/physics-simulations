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