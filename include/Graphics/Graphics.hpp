#ifndef GRAPHICS_H
#define GRAPHICS_H 

#include <SFML/Graphics.hpp>
#include "City.hpp"
#include <iostream>

class Graphics {
    private: 
        sf::RenderWindow window;
        City& city; 
    public:
        Graphics(City& city);
        void run();
};

#endif