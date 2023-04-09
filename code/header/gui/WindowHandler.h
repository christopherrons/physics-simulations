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
    WindowHandler(int width, int height);

private:
    sf::Sprite backgroundSprite;

public:
    sf::RenderWindow window;

    void draw(std::vector<RigidRectangleBody> &walls, std::vector<RigidCircleBody> &bodies);

    void drawBackground();

    void displayWindow();

    double getWindowHeight();

    double getWindowWidth();

    void takeScreenShot(int iteration);
};


#endif //PHYSICS_SIMULATIONS_WINDOWHANDLER_H
