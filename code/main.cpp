//
// Created by christopher on 2023-04-08.
//


#include <SFML/Graphics.hpp>
#include <iostream>
#include "header/gui/WindowHandler.h"
#include "header/utils/ObjectUtil.h"
#include "header/simulation//PhysicsSceneHandler.h"

int main() {
    std::string recordOption = "temp";
    std::cout << "\nType record if you wish to record else no: ";
    std::cin >> recordOption;

    int windowsWidth = 1600;
    int windowsHeight = 700;
    int border = 50;
    WindowHandler windowHandler(windowsWidth, windowsHeight, border);

    sf::Vector2i CurrentMousePosition;
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    SimulationConfig simulationConfig(150, 60, border, border, windowsWidth - border, windowsHeight - border, 50);
    PhysicsSceneHandler sceneHandler(simulationConfig);

    int iteration = 0;
    double updatesPerSecond = 1.0 / simulationConfig.getFrameRate();
    while (true) {
        sf::Event event{};
        timeSinceLastUpdate += clock.restart();
        if (timeSinceLastUpdate.asSeconds() > updatesPerSecond) {
            sceneHandler.updateScene();
            windowHandler.draw(sceneHandler.getBodies(), timeSinceLastUpdate.asSeconds());

            if (recordOption == "record") {
                windowHandler.takeScreenShot(iteration++);
            }

            timeSinceLastUpdate = sf::Time::Zero;

        }

        while (windowHandler.window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                windowHandler.window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                int a = 1;
            }
        }
    }

    return 0;
}