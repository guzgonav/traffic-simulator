#ifndef CITY_H
#define CITY_H

#include <vector>
#include <iostream>
#include "Road.hpp"
#include "TrafficLight.hpp"
#include "Vehicle.hpp"

class City {
private:
    std::vector<Road> roads;
    std::vector<TrafficLight> traffic_lights;
    std::vector<Vehicle*> vehicles;
public: 
    void addRoad(const Road& road); 
    void addTrafficLight(const TrafficLight& light);
    void addVehicle(Vehicle* vehicle);

    void stopVehicles(); 
    void update();

    Vehicle* prepareVehicle(int id); 

    TrafficLight& getTrafficLight();
    LightState getTrafficLightState() const;
    std::vector<Vehicle*> getVehicles();
    std::vector<Road> getRoads();
    Road& getRoadByName(const std::string& name); 
};

#endif