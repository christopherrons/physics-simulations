//
// Created by christopher on 2023-04-08.
//


#include <SFML/Graphics.hpp>
#include "header/gui/WindowHandler.h"
#include "header/utils/ObjectUtil.h"
#include "header/simulation//SimulationStateMachine.h"

int main() {
    WindowHandler windowHandler;
    windowHandler.drawBackground();

    sf::Vector2i CurrentMousePosition;
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    SimulationConfig simulationConfig(10, 60);
    SimulationStateMachine simulationStateMachine(simulationConfig);

    while (true) {
        sf::Event event{};
        simulationStateMachine.iterateSimulation();
        timeSinceLastUpdate += clock.restart();
        if (timeSinceLastUpdate.asSeconds() >= 1.0 / simulationConfig.getFrameRate()) {
            windowHandler.draw(simulationStateMachine.getObjects());
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