//
// Created by christopher on 2023-04-08.
//

#include "../../header/utils/ObjectUtil.h"


sf::CircleShape ObjectUtil::createCircle() {
    sf::CircleShape circle;
    circle.setRadius(MathUtils::getUniformRandomNumber(1, 10));
    circle.setPosition(MathUtils::getUniformRandomNumber(0, 1920), MathUtils::getUniformRandomNumber(0, 1080));
    return circle;
}
