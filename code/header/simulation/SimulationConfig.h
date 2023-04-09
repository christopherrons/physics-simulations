//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H
#define PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H


class SimulationConfig {
public:
    explicit SimulationConfig(int nrOfObjects, int frameRate, int xMinBoundary, int yMinBoundary, int xMaxBoundary,
                              int yMaxBoundary, double maxVelocity);

    [[nodiscard]] int getNrOfObjects() const;

    void setNrOfOjects();

    int getFrameRate() const;

    double getDeltaTime() const;

    double getMaxVelocity() const;

    void setFrameRate();

    [[nodiscard]]  int getXMinBoundary() const;

    [[nodiscard]]  int getYMinBoundary() const;

    [[nodiscard]]  int getXMaxBoundary() const;

    [[nodiscard]]  int getYMaxBoundary() const;

private:
    int nrOfObjects;
    int frameRate;
    double deltaTime;
    int xMinBoundary;
    int yMinBoundary;
    int xMaxBoundary;
    int yMaxBoundary;
    double maxVelocity;
};


#endif //PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H
