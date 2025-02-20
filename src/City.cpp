#include "City.hpp"

void City::addRoad(const Road &road) {
    roads.push_back(road);
}

void City::addTrafficLight(const TrafficLight &light) {
    traffic_lights.push_back(light);
}

void City::addVehicle(Vehicle *vehicle) {
    vehicles.push_back(vehicle);
    vehicle->start(traffic_lights[0]); //Start the vehicle's thread
}

void City::stopVehicles() {
    for (const auto &vehicle: vehicles) {
        vehicle->stop();
    }
}

void City::update() {
    std::cout << "Updating city..." << std::endl;
    for (auto &road: roads) {
        road.update();
    }
    for (auto &light: traffic_lights) {
        light.update();
    }
    for (const auto &vehicle: vehicles) {
        vehicle->move(traffic_lights[0]);
    }
}

Vehicle *City::prepareVehicle(int id) {
    std::string road_name;
    if (!roads.empty()) {
        const ulong random_index = rand() % roads.size();
        road_name = roads[random_index].getName(); //Select a random road
    }
    const Road &road = getRoadByName(road_name);
    const int lane = rand() % road.getNumLanes(); //Assign a random lane
    const int speed = 2 + rand() % 3; //Random speed between 2 and 4
    return new Car("Car" + std::to_string(id), speed, road_name, lane);
}

TrafficLight &City::getTrafficLight() {
    return traffic_lights[0];
}

LightState City::getTrafficLightState() const {
    return traffic_lights[0].getState();
}

std::vector<Vehicle *> City::getVehicles() {
    return vehicles;
}

std::vector<Road> City::getRoads() {
    return roads;
}

Road &City::getRoadByName(const std::string &name) {
    for (auto &road: roads) {
        if (road.getName() == name) {
            return road;
        }
    }
    throw std::runtime_error("Road: " + name + " not found");
}
