#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Map.h"
#include <iostream>
#include <string>

using namespace sf;

enum Players {Player1, Player2};


int main()
{
    RenderWindow window(VideoMode(800, 600), "Strategy Game v0.1");

    //Menu menu(window.getSize().x, window.getSize().y);
    int rows = 5;
    int cols = 5;
    Map *map = new Map(rows, cols);


    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        // error
    }
    sf::Text input;
    input.setFont(font);
    input.setOutlineColor(sf::Color::Red);
    input.setFillColor(sf::Color::White);
    input.setCharacterSize(12);
    input.setPosition(sf::Vector2f(20.0f, 20.0f));
    input.setString("");

    std::string savedText;

    bool valueSet = false;
    int PlayerX = NULL;
    int PlayerY = NULL;

    Players Turn = Player1;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;

            case Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                break;
            }
            case Event::TextEntered:
                std::cout << savedText.empty() << std::endl;
                savedText = input.getString();
                if (event.text.unicode == '\b') {
                    if (!savedText.empty()) {
                        savedText.erase(savedText.size() - 1, 1);
                        input.setString(savedText);
                    }
                } else if (event.text.unicode == 13) {
                    if(!savedText.empty()) {
                        valueSet = true;
                        input.setString("");
                    }
                } else if (event.text.unicode < 128) {
                    
                    input.setString(savedText + static_cast<char>(event.text.unicode));
                }
                break;
            }
        }

        window.clear();
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                window.draw(map->getTile(i, j).getSprite());
            }
        }

        if (valueSet) {
            if (PlayerX == NULL) {
                PlayerX = std::stoi(savedText);
                if (PlayerX < 1 || PlayerX > rows) {
                    PlayerX = NULL;
                };
            } else if (PlayerY == NULL) {
                PlayerY = std::stoi(savedText);
                if (PlayerY < 1 || PlayerY > cols) {
                    PlayerY = NULL;
                };
            }
            valueSet = false;
        }

        
        if (PlayerX != NULL && PlayerY != NULL) {
            if (Turn == Player1) {
                map->PaintTile(PlayerX, PlayerY, BLUE_BASE);
                Turn = Player2;
                PlayerX = NULL;
                PlayerY = NULL;
            } else {
                map->PaintTile(PlayerX, PlayerY, RED_BASE);
                Turn = Player1;
                PlayerX = NULL;
                PlayerY = NULL;
            }
        }        

        RectangleShape inputRectangle;        
        inputRectangle.setFillColor(Color::Black);
        inputRectangle.setOutlineColor(Color::Green);
        inputRectangle.setOutlineThickness(3.0f);
        inputRectangle.setSize(Vector2f(800,20));
        inputRectangle.setPosition(sf::Vector2f(0, 19.0f));
        window.draw(inputRectangle);

        window.draw(input);
        window.display();
    }

    return 0;
}