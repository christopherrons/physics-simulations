//
// Created by christopher on 2023-04-08.
//

#include "../../header/gui/WindowHandler.h"

WindowHandler::WindowHandler()
        : window(sf::VideoMode(1920.0, 1080.0), "Physics Simulation", sf::Style::Default),
          backgroundSprite(sf::Sprite()) {
}

void WindowHandler::draw(std::vector <sf::CircleShape> const &objects) {
    this->window.clear();
    this->drawBackground();
    for (auto &object: objects) {
        this->window.draw(object);
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