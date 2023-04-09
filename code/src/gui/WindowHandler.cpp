//
// Created by christopher on 2023-04-08.
//

#include <iostream>
#include "../../header/gui/WindowHandler.h"


WindowHandler::WindowHandler(int width, int height)
        : window(sf::VideoMode(width, height), "Physics Simulation", sf::Style::Fullscreen),
          backgroundSprite(sf::Sprite()) {
}


void WindowHandler::draw(std::vector<RigidRectangleBody> &walls, std::vector<RigidCircleBody> &bodies) {
    this->window.clear();
    this->drawBackground();

    for (auto &wall: walls) {
        this->window.draw(wall.getShape());
    }

    for (auto &body: bodies) {
        this->window.draw(body.getShape());
    }

    this->window.display();
}

void WindowHandler::drawBackground() {
    this->window.draw(this->backgroundSprite);
}

void WindowHandler::displayWindow() {
    this->window.display();
}

double WindowHandler::getWindowHeight() {
    return this->window.getSize().y;
}

double WindowHandler::getWindowWidth() {
    return this->window.getSize().x;
}

void WindowHandler::takeScreenShot(int iteration) {
    sf::Texture texture;
    texture.create(window.getSize().x, window.getSize().y);
    texture.update(window);
    if (texture.copyToImage().saveToFile("../recording/images/screenshot_" + std::to_string(iteration) + ".png")) {
        std::cout << "Screenshot saved" << std::endl;
    } else {
        std::cout << "NOT SAVED" << std::endl;
    }
}
