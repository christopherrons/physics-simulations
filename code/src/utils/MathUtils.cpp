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