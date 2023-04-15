//
// Created by christopher on 2023-04-08.
//

#include <iostream>
#include "../../header/gui/WindowHandler.h"
#include "../../header/utils/ObjectUtil.h"


WindowHandler::WindowHandler(int width, int height, int border)
        : window(sf::VideoMode(width, height), "Physics Simulation", sf::Style::Default),
          textFont(sf::Font()),
          frameRateText(sf::Text("FPS: ", textFont)),
          backgroundSprite(sf::Sprite()) {

    frameRateText.setOutlineThickness(1.f);
    frameRateText.setFillColor(sf::Color::White);
    frameRateText.setCharacterSize(20);
    frameRateText.setPosition(15.f, 15.f);
    frameRateText.setStyle(sf::Text::Style::Bold);

    initWalls(width, height, border);
    loadFont();
}

void WindowHandler::initWalls(float widthNoBorder, float heightNoBorder, int border) {
    float width = widthNoBorder - 2 * border;
    float height = heightNoBorder - 2 * border;
    float wallThickness = 1.0;

    walls.push_back(ObjectUtil::createRectangle(walls.size(), wallThickness, height, border, border));
    walls.push_back(ObjectUtil::createRectangle(walls.size(), wallThickness, height, width + border, border));
    walls.push_back(ObjectUtil::createRectangle(walls.size(), width, wallThickness, border, border));
    walls.push_back(ObjectUtil::createRectangle(walls.size(), width, wallThickness, border, height + border));
}

void WindowHandler::draw(std::vector<RigidCircleBody> &bodies, double frameRate) {
    this->window.clear();
    this->drawBackground();
    this->frameRateText.setString("FPS: " + std::to_string((int) round(1.0 / frameRate)) + " | # Particles: " + std::to_string(bodies.size()));
    this->window.draw(this->frameRateText);

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

void WindowHandler::loadFont() {
    if (!this->textFont.loadFromFile("../code/resources/fonts/OpenSans-Regular.ttf")) {
        std::cout << "Failed to load font" << std::endl;
    }
}

void WindowHandler::takeScreenShot(int iteration) {
    sf::Texture texture;
    texture.create(window.getSize().x, window.getSize().y);
    texture.update(window);
    if (texture.copyToImage().saveToFile("../recording/images/screenshot_" + std::to_string(iteration) + ".png")) {
      //  std::cout << "Screenshot saved" << std::endl;
    } else {
        std::cout << "NOT SAVED" << std::endl;
    }
}
