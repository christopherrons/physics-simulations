//
// Created by christopher on 2023-04-10.
//

#ifndef PHYSICS_SIMULATIONS_GRID_H
#define PHYSICS_SIMULATIONS_GRID_H


class Grid {
public:
    explicit Grid(int gridId, double xMinBoundary, double yMinBoundary, double xMaxBoundary, double yMaxBoundary);

    bool isInGrid(double x, double y);

    int getGridId();

private:
    int gridId;
    double xMinBoundary;
    double yMinBoundary;
    double xMaxBoundary;
    double yMaxBoundary;
};


#endif //PHYSICS_SIMULATIONS_GRID_H
