//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_SIMULATIONSTATEMACHINE_H
#define PHYSICS_SIMULATIONS_SIMULATIONSTATEMACHINE_H

#include <SFML/Graphics.hpp>
#include "SimulationConfig.h"
#include "PhysicsObjectDetails.h"

class SimulationStateMachine {
public:
    explicit SimulationStateMachine(SimulationConfig simulationConfig);

    void iterateSimulation();

    void restartSimulation();

    std::vector<PhysicsObjectDetails>& getObjects();

private:
    void initObjects();

private:
    SimulationConfig simulationConfig;
    std::vector<PhysicsObjectDetails> objects;
};


#endif //PHYSICS_SIMULATIONS_SIMULATIONSTATEMACHINE_H
