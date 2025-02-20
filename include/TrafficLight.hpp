#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <iostream>

enum class LightState {
    RED,
    GREEN
};

class TrafficLight {
    private:
        LightState state;
        int timer; 
    public:
        TrafficLight();
        void update();
        LightState getState() const { return state; }
};

#endif