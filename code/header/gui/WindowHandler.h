//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_WINDOWHANDLER_H
#define PHYSICS_SIMULATIONS_WINDOWHANDLER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include "../simulation/objects/RigidBody.h"
#include "../simulation/objects/RigidRectangleBody.h"
#include "../simulation/objects/RigidCircleBody.h"

class WindowHandler {
public:
    WindowHandler(int width, int height, int border);

    void draw(std::vector<RigidCircleBody> &bodies, double frameRate);

    void drawBackground();

    void displayWindow();

    double getWindowHeight();

    double getWindowWidth();

    void loadFont();

    void takeScreenShot(int iteration);

private:
    void initWalls(float width, float height, int border);

public:
    sf::RenderWindow window;

private:
    sf::Sprite backgroundSprite;
    std::vector<RigidRectangleBody> walls;
    sf::Font textFont;
    sf::Text frameRateText;
    sf::Text nrOfParticlesText;
};


#endif //PHYSICS_SIMULATIONS_WINDOWHANDLER_H
