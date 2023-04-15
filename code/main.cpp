//
// Created by christopher on 2023-04-08.
//


#include <SFML/Graphics.hpp>
#include <iostream>
#include "header/gui/WindowHandler.h"
#include "header/utils/ObjectUtil.h"
#include "header/simulation//PhysicsSceneHandler.h"
#include <chrono>

int main() {
    std::string recordOption = "tmp";
    // std::cout << "\nType record if you wish to record else no: ";
    // std::cin >> recordOption;

    int windowsWidth = 1900;
    int windowsHeight = 700;
    int border = 50;
    WindowHandler windowHandler(windowsWidth, windowsHeight, border);

    sf::Vector2i CurrentMousePosition;
    SimulationConfig simulationConfig(1500, 60, border, border, windowsWidth - border, windowsHeight - border, 75, 10);
    PhysicsSceneHandler sceneHandler(simulationConfig);

    int iteration = 0;
    int screenShotNumber = 0;
    double aggregatedDeltaTime = 0.0;
    double deltaTime = 1.0 / 120;
    double refreshTimeMin = 1.0 / 60;
    double refreshTime = 0.0;

    sceneHandler.updateScene();
    while (true) {
        sf::Event event{};
        aggregatedDeltaTime += deltaTime;
        simulationConfig.setDeltaTime(deltaTime);
        refreshTime += deltaTime;

        auto start = std::chrono::high_resolution_clock::now();
        sceneHandler.updateScene();

        if (refreshTime > refreshTimeMin) {
            windowHandler.draw(sceneHandler.getBodies(), aggregatedDeltaTime / (iteration + 1));
            auto end = std::chrono::high_resolution_clock::now();
            deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;
            refreshTime = 0;
            if (recordOption == "record") {
                windowHandler.takeScreenShot(screenShotNumber++);
            }

        } else {
            auto end = std::chrono::high_resolution_clock::now();
            deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;
        }

        while (windowHandler.window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                windowHandler.window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                int a = 1;
            }
        }

        iteration++;
    }

    return 0;
}
