#include "TrafficLight.hpp"

TrafficLight::TrafficLight() : state(LightState::RED) , timer(0){}

void TrafficLight::update(){
    timer++;
    if (timer % 5 == 0){
        state = (state == LightState::RED) ? LightState::GREEN : LightState::RED;
        std::cout << "Traffic light state: " << (state == LightState::RED ? "RED" : "GREEN") << std::endl;
    }
}