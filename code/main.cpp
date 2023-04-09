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
    // std::cout << "\nType record if you wish to record else no: ";
    //   std::cin >> recordOption;

    WindowHandler windowHandler(1920, 1080);

    sf::Vector2i CurrentMousePosition;
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    SimulationConfig simulationConfig(10, 60, windowHandler.getWindowWidth(), windowHandler.getWindowHeight());
    PhysicsSceneHandler sceneHandler(simulationConfig);

    int iteration = 0;
    while (true) {
        sf::Event event{};
        sceneHandler.updateScene();
        timeSinceLastUpdate += clock.restart();
        if (timeSinceLastUpdate.asSeconds() >= 1.0 / simulationConfig.getFrameRate()) {
            windowHandler.draw(sceneHandler.getWalls(), sceneHandler.getBodies());
            if (recordOption == "record") {
                windowHandler.takeScreenShot(iteration++);
            }
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