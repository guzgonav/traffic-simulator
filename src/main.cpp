#include <iostream>
#include "Simulation.hpp"
#include "Graphics/Graphics.hpp"

int main(){
    Simulation sim;
    Graphics graphics(sim.getCity());

    std::thread simThread([&]() { sim.run(); });  
    graphics.run();

    simThread.join();
    return 0;
}