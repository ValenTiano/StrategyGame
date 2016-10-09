#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Map.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Strategy Game v0.1");

    //Menu menu(window.getSize().x, window.getSize().y);
    int rows = 5;
    int cols = 5;
    Map map(rows,cols);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                std::cout << map.getTile(i, j).getSprite().getPosition().x << " " << map.getTile(i, j).getSprite().getPosition().y << std::endl;
                window.draw(map.getTile(i, j).getSprite());
                

            }
        }
        window.display();
    }

    return 0;
}