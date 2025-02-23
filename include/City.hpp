#ifndef CITY_H
#define CITY_H

#include <vector>
#include <memory>
#include <iostream>
#include "Road.hpp"
#include "TrafficLight.hpp"
#include "Vehicle.hpp"

class City {
private:
    std::vector<Road> roads;
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    std::vector<TrafficLight> traffic_lights;
public:
    void addTrafficLight(const TrafficLight& light);
    void addVehicle(const std::shared_ptr<Vehicle> &vehicle);
    void addRoad(const Road& road);

    void stopVehicles(); 
    void update();

    std::shared_ptr<Vehicle> prepareVehicle(int id);

    TrafficLight& getTrafficLight();
    LightState getTrafficLightState() const;
    std::vector<std::shared_ptr<Vehicle>> getVehicles();
    std::vector<Road> getRoads();
    Road& getRoadByName(const std::string& name); 
};

#endif