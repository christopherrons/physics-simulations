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
        code/header/simulation/SimulationStateMachine.h
        code/src/simulation/SimulationStateMachine.cpp
        code/src/simulation/SimulationConfig.cpp
        code/header/simulation/SimulationConfig.h)

target_link_libraries(physics_simulations
        -lsfml-graphics
        -lsfml-window
        -lsfml-system)
