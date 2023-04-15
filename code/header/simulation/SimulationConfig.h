//
// Created by christopher on 2023-04-08.
//

#ifndef PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H
#define PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H


class SimulationConfig {
public:
    explicit SimulationConfig(int nrOfObjects, int frameRate, int xMinBoundary, int yMinBoundary, int xMaxBoundary,
                              int yMaxBoundary, double maxVelocity, int nrOfGridsPerRowAndColumn);

    [[nodiscard]] int getNrOfObjects() const;

    void setNrOfOjects();

    int getFrameRate() const;

    [[nodiscard]]  double getDeltaTime() const;

    [[nodiscard]]  double getMaxVelocity() const;

    void setDeltaTime(double newDeltaTime);

    [[nodiscard]]  int getXMinBoundary() const;

    [[nodiscard]]  int getYMinBoundary() const;

    [[nodiscard]]  int getXMaxBoundary() const;

    [[nodiscard]]  int getYMaxBoundary() const;

    [[nodiscard]]  int getNrOfGridsPerRowAndColumn() const;

private:
    int nrOfObjects;
    int frameRate;
    double deltaTime;
    int xMinBoundary;
    int yMinBoundary;
    int xMaxBoundary;
    int yMaxBoundary;
    double maxVelocity;
    int nrOfGridsPerRowAndColumn;
};


#endif //PHYSICS_SIMULATIONS_SIMULATIONCONFIG_H
