#include "Simulation.hpp"

Simulation::Simulation() : running(true){
    //Configure the initial city
    city.addRoad(Road("Main Street", 3, 4)); 
    // city.addRoad(Road("Secondary street", 3, 2)); 
    // city.addRoad(Road("Tertiary street", 3, 1));
    city.addTrafficLight(TrafficLight());
    for (int i = 0; i < 10; ++i) {
        Vehicle* vehicle = city.prepareVehicle(i); 

        city.addVehicle(vehicle);
    }
}

void Simulation::run(){
    while(running){
        city.update();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

Simulation::~Simulation(){
    city.stopVehicles(); //Stop the vehicles when destroying the simulation
}

City& Simulation::getCity(){
    return city;
}