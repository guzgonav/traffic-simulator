#ifndef VEHICLE_H
#define VEHICLE_H

#include "TrafficLight.hpp"

#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <SFML/Graphics.hpp>

class Vehicle {
protected:
    std::string id; 
    int speed; 
    float position; 
    sf::Color color;
    std::string road_name;
    int lane; 
    std::thread vehicle_thread; 
    std::atomic <bool> running; //Flag to stop the thread

public: 
    Vehicle(std::string id, int speed, std::string road_name, int lane); 
    virtual ~Vehicle(); 
    virtual void move(TrafficLight& light) = 0; 

    [[nodiscard]] float getPosition() const { return position; }
    [[nodiscard]] sf::Color getColor() const { return color; }
    [[nodiscard]] std::string getRoadName() const { return road_name; }
    [[nodiscard]] int getLane() const { return lane; }

    void setPosition(const float new_position) { position = new_position; }

    void changeLane(int new_lane); 
    void changeRoad(std::string new_road);

    void start(TrafficLight& light); //Initialize the vehicle thread
    void stop(); //Stop the vehicle thread
};

class Car : public Vehicle {
public:
    Car(std::string id, int speed, std::string road_name, int lane); 
    void move(TrafficLight& light) override; 
};

#endif