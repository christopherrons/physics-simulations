//
// Created by christopher on 2023-04-08.
//

#include <iostream>
#include "../../header/gui/WindowHandler.h"
#include "../../header/simulation/PhysicsObjectDetails.h"

WindowHandler::WindowHandler()
        : window(sf::VideoMode(1920.0, 1080.0), "Physics Simulation", sf::Style::Default),
          backgroundSprite(sf::Sprite()) {
}

void WindowHandler::draw(std::vector<PhysicsObjectDetails> &objects) {
    this->window.clear();
    this->drawBackground();
    for (auto &object: objects) {
        this->window.draw(object.getObject());
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