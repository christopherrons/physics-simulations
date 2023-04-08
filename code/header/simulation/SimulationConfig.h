//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H
#define PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H


class SimulationConfig {
public:
    explicit SimulationConfig(int nrOfObjects, int frameRate);

    int getNrOfObjects() const;

    void setNrOfOjects();

    int getFrameRate() const;

    void setFrameRate();

private:
    int nrOfObjects;
    int frameRate;
};


#endif //PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H
