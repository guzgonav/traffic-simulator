#ifndef SIMULATION_H
#define SIMULATION_H

#include "City.hpp"
#include <iostream>
#include <thread>
#include <chrono>

class Simulation {
    private: 
        City city;
        bool running; 
    public:
        Simulation();
        ~Simulation();
        void run();
        City& getCity();
}; 

#endif