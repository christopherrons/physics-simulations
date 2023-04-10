cmake_minimum_required(VERSION 3.24)
project(physics_simulations)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++17")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/..bin)

add_executable(physics_simulations
        code/main.cpp
        code/src/gui/WindowHandler.cpp
        code/src/utils/ObjectUtil.cpp
        code/header/utils/ObjectUtil.h
        code/header/gui/WindowHandler.h
        code/src/utils/MathUtils.cpp
        code/header/utils/MathUtils.h
        code/header/simulation/PhysicsSceneHandler.h
        code/src/simulation/PhysicsSceneHandler.cpp
        code/src/simulation/SimulationConfig.cpp
        code/header/simulation/SimulationConfig.h code/header/simulation/objects/RigidBody.h code/src/simulation/objects/RigidRectangleBody.cpp code/header/simulation/objects/RigidRectangleBody.h code/src/simulation/objects/RigidCircleBody.cpp code/header/simulation/objects/RigidCircleBody.h code/src/simulation/PhysicsEngine.cpp code/header/simulation/PhysicsEngine.h code/src/math/Vector2D.cpp code/header/math/Vector2D.h code/src/simulation/Grid.cpp code/src/simulation/Grid.h)

target_link_libraries(physics_simulations
        -lsfml-graphics
        -lsfml-window
        -lsfml-system)
