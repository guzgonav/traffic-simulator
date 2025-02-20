cmake_minimum_required(VERSION 3.10)
project(traffic_simulator)

#Activate C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)


#Define the directory for the source files and headers
include_directories(include)

#Add the source files
set (SOURCES
    src/Vehicle.cpp
    src/City.cpp
    src/Road.cpp
    src/TrafficLight.cpp
    src/main.cpp
    src/Simulation.cpp
    src/Graphics/Graphics.cpp
)

#Add the executable
add_executable(traffic_simulator ${SOURCES})

#Link libraries
target_link_libraries(traffic_simulator sfml-graphics sfml-window sfml-system)
