#include "Graphics/Graphics.hpp"

Graphics::Graphics(City& city) : window(sf::VideoMode(800, 600), "Traffic Simulator"), city(city){}

void Graphics::run(){
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        //Clean window
        window.clear(sf::Color::Black);

        //Draw traffic light
        sf::CircleShape light(20); 
        light.setPosition(700, 230); 
        light.setFillColor(city.getTrafficLightState() == LightState::RED ? sf::Color::Red : sf::Color::Green);
        window.draw(light);

        //Draw roads
        for (auto& road : city.getRoads()){
            sf::RectangleShape roadShape(sf::Vector2f(800, road.getNumLanes() * 40));
            roadShape.setPosition(0, road.getYPosition());  // Cada carretera en una fila diferente
            roadShape.setFillColor(sf::Color(50, 50, 50));
            window.draw(roadShape);
            // Dibujar líneas discontinuas entre carriles
            for (int i = 1; i < road.getNumLanes(); ++i) {
                float yPos = road.getYPosition() + i * 40; // Posición en Y del carril

                // Create segments of uncontinued lines
                for (float x = 0; x < 800; x += 40) {  // Space between segments
                    sf::RectangleShape laneSegment(sf::Vector2f(20, 3));  // Size of each segment
                    laneSegment.setPosition(x, yPos);
                    laneSegment.setFillColor(sf::Color::White);
                    window.draw(laneSegment);
                }
            }
        }

        //Draw vehicles
        for (auto& vehicle : city.getVehicles()){
            sf::RectangleShape car(sf::Vector2f(40, 20));

            //Obtain the road in which the vehicle is
            const Road& road = city.getRoadByName(vehicle->getRoadName()); 

            //Determine the position in Y 
            float y_position = road.getYPosition() + vehicle->getLane() * 40 + 10;
            car.setPosition(vehicle->getPosition(), y_position); 
            car.setFillColor(vehicle->getColor());
            window.draw(car);
        }

        //Update window
        window.display();
    }
}