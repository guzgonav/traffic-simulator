#include "Vehicle.hpp"

Vehicle::Vehicle(std::string id, int speed, std::string road_name, int lane) : id(id), speed(speed), road_name(road_name), lane(lane), position(0) //id, speed,
{
    //Generate random color
    color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
}

Vehicle::~Vehicle() { 
    stop(); //Stop the vehicle thread before destroying the object
}   

void Vehicle::start(TrafficLight& light) {
    running = true;
    vehicle_thread = std::thread([this, &light] {
        while(running){
            move(light);
            std::this_thread::sleep_for(std::chrono::seconds(1)); //Wait one second between each move
        }
    }); 
}

void Vehicle::stop() {
    running = false; 
    if (vehicle_thread.joinable()) {
        vehicle_thread.join();
    }
}


Car::Car(std::string id, int speed, std::string road_name, int lane) : Vehicle(id, speed, road_name, lane) {}

void Car::move(TrafficLight& light) {
    //Only move if traffic light is green
    if(light.getState() == LightState::GREEN){
        position += speed; 
        std::cout << "Car " << id << " is moving at " << speed << " km/h, Position: " << position << std::endl;
    } else {
        std::cout << "Car " << id << " is waiting at the red light." << std::endl;
    }
}