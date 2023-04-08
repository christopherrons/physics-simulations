//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H
#define PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H


class SimulationConfig {
public:
    explicit SimulationConfig(int nrOfObjects, int frameRate, int xBoundary, int yBoundary);

    [[nodiscard]] int getNrOfObjects() const;

    void setNrOfOjects();

    int getFrameRate() const;

    void setFrameRate();

    [[nodiscard]]  int getXBoundary() const;

    [[nodiscard]]  int getYBoundary() const;

private:
    int nrOfObjects;
    int frameRate;
    int xBoundary;
    int yBoundary;
};


#endif //PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H
