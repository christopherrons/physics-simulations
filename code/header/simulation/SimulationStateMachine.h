//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_SIMULATIONSTATEMACHINE_H
#define PHYSICS_SIMULATIONS_SIMULATIONSTATEMACHINE_H

#include <SFML/Graphics.hpp>
#include "SimulationConfig.h"

class SimulationStateMachine {
public:
    explicit SimulationStateMachine(SimulationConfig simulationConfig);

    void iterateSimulation();

    void restartSimulation();

    void initObjects();

    std::vector<sf::CircleShape> getObjects();


private:
    SimulationConfig simulationConfig;
    std::vector<sf::CircleShape> objects;
};


#endif //PHYSICS_SIMULATIONS_SIMULATIONSTATEMACHINE_H
