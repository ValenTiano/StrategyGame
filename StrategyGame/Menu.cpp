#include "Menu.h"



Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("arial.ttf")) {
        // error
    }
    _width = width;
    _height = height;
    menu[0].setString("Player VS Player");
    menu[1].setString("Player VS Player 2");
    menu[2].setString("Player VS Player 3");


}

Menu::~Menu()
{
}

void Menu::Draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        menu[i].setFont(font);
        menu[i].setOutlineColor(sf::Color::Red);
        menu[i].setFillColor(sf::Color::White);
        menu[i].setCharacterSize(36);
        menu[i].setPosition(sf::Vector2f(_width / 3, _height / (MAX_NUMBER_OF_ITEMS + 1) * (i+1)));
        window.draw(menu[i]);
    }
}

