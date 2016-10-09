#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Strategy Game v0.1");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //Menu menu(window.getSize().x, window.getSize().y);
    Game game;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        game.Run();

        //window.draw(shape);
        //menu.Draw(window);
        window.display();
    }

    return 0;
}