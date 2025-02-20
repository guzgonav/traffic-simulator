#include "Road.hpp"

Road::Road(std::string name, int capacity, int lanes) : name(name), capacity(capacity), num_lanes(lanes) {}

void Road::addVehicle(Vehicle* vehicle){
    if(vehicles.size() < capacity){
        vehicles.push(vehicle);
        std::cout << "Vehicle added to " << name << std::endl;
    }
}

void Road::update(){
    std::cout << "Updating road: " << name << std::endl; 
}
