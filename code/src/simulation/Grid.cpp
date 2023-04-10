//
// Created by christopher on 2023-04-10.
//

#include "Grid.h"

Grid::Grid(int gridId, double xMinBoundary, double yMinBoundary, double xMaxBoundary, double yMaxBoundary) :
        gridId(gridId),
        xMinBoundary(xMinBoundary),
        yMinBoundary(yMinBoundary),
        xMaxBoundary(xMaxBoundary),
        yMaxBoundary(yMaxBoundary) {
}

bool Grid::isInGrid(double x, double y) {
    return x >= xMinBoundary &&
           x <= xMaxBoundary &&
           y >= yMinBoundary &&
           y <= yMaxBoundary;
}

int Grid::getGridId() {
    return gridId;
}
