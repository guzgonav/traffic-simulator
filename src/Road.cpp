#include "Road.hpp"

Road::Road(const std::string &name, const int capacity, const int lanes) : name(name), num_lanes(lanes), y_position(0),
                                                        capacity(capacity) {
}

void Road::addVehicle(const std::shared_ptr<Vehicle> &vehicle){
    if(vehicles.size() < capacity){
        vehicles.push(vehicle);
        std::cout << "Vehicle added to " << name << std::endl;
    }
}

void Road::update() const {
    std::cout << "Updating road: " << name << std::endl; 
}
