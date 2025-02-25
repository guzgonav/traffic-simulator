#ifndef ROAD_H
#define ROAD_H

#include <queue>
#include <iostream>
#include <memory>

#include "Vehicle.hpp"

class Road{
    private:
        std::string name; 
        int num_lanes;
        int y_position; 
        int capacity; 
        std::queue<std::shared_ptr<Vehicle>> vehicles;
    public:
        Road(std::string name, int capacity, int lanes);
        void addVehicle(const std::shared_ptr<Vehicle> &vehicle);

        std::string getName() const { return name; }
        int getNumLanes() const { return num_lanes; }
        float getYPosition() const { return y_position; }

        void update() const;
}; 

#endif
