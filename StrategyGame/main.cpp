#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Map.h"
#include <iostream>
#include <string>

using namespace sf;

enum Players {Player1, Player2};


int main()
{
    RenderWindow window(VideoMode(800, 600), "Strategy Game v0.1"); //створюємо вікно 800х800 з заголовком ...

    //Menu menu(window.getSize().x, window.getSize().y);  //малоб створювати меню, але воно ше недороблене

	// на разі задаємо розміри в ручну, але має працювати нвіть коли вводити в вікні
    int rows = 5;
    int cols = 5;

	//створюємо посилання на новий тип який ми створили, тобто карту
    Map *map = new Map(rows, cols);

	//задаємо шрифт тексту
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) { //якшо шрифт не загрузиться то буде писати помилку в консоль
        // error. так тут пусто нічо не відбувається але якшо шось то можна сюди вписати
    }
    sf::Text input; //робимо новий тестовий тип де будем зберігати введений текст
    input.setFont(font); //назначаємо шрифт
    input.setFillColor(sf::Color::White); //колір тесту
    input.setCharacterSize(12); //розмір в пікселях
    input.setPosition(sf::Vector2f(20.0f, 20.0f)); //координати на полі 0,0 верній лівий кут... +x -> вправо; +y -> вниз
    input.setString(""); //чистимо поле вводу

    std::string savedText; //робимо змінну шоб зберігати введений текст

	//змінні для вводу координа TODO:придумати шось краще
    bool valueSet = false; 
    int PlayerX = NULL;
    int PlayerY = NULL;

	//змінна для черги 
    Players Turn = Player1;

    while (window.isOpen()) { //поки відкрите вікно то робимо наступе
        Event event;
        while (window.pollEvent(event)) { //беремо дію яка виконується в вікні
            switch (event.type) { //якшо тип дії:
            case Event::Closed: //нажати на хрестик то
                window.close(); //закрити вікно
                break;

            case Event::KeyPressed: //нажата кнопка:
            {
                if (event.key.code == sf::Keyboard::Escape) { //якшо код кнопки ESC то
                    window.close(); //закрити вікно
                }
                break;
            }
            case Event::TextEntered: //ведений текст
                savedText = input.getString(); //зберігаємо введений тескт в змінну
                if (event.text.unicode == '\b') { //якшо нажата кнопка Backspace
                    if (!savedText.empty()) { //якшо текст не порожній (не зводити, бо буде писати непотрібні символи)
                        savedText.erase(savedText.size() - 1, 1); //стерти останню літеру в нашій змінній
                        input.setString(savedText); //переписуємо нашу стрічку
                    }
                } else if (event.text.unicode == 13) { //інакше якшо нажати Ентер 
                    if(!savedText.empty()) { // і якшо текст не пустий
                        valueSet = true; //сказати шо текст був введений
                        input.setString(""); //змінити ввідну стрічку на пусту, для нового введення
                    }
                } else if (event.text.unicode < 128) {// інакше якшо сод тексту по таблиці unicode менший 128 (там якийсь символ)
                    input.setString(savedText + static_cast<char>(event.text.unicode)); // додати до введеного тексту введений символ
                }
                break;
            }
        }

        window.clear(); //очистити вікно

		//задати нову карту
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                window.draw(map->getTile(i, j).getSprite());
            }
        }

		//якшо було введене дані, то присвоїти їх в X якшо він пустий
		//або в Y якшо X не пустий. TODO: теж придумати шось краще
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

        //якшо введені Х і Y, то перевіряємо чия черга 
		//і замальовуєм потрібний квадратик потрібним кольором
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

		//створюємо квадратик шоб було видно шо ми там вводили
        RectangleShape inputRectangle;        
        inputRectangle.setFillColor(Color::Black);
        inputRectangle.setOutlineColor(Color::Green);
        inputRectangle.setOutlineThickness(3.0f);
        inputRectangle.setSize(Vector2f(800,20));
        inputRectangle.setPosition(sf::Vector2f(0, 19.0f));
        window.draw(inputRectangle); //малюємо його


        window.draw(input);//малюємо текст
        window.display();//показуємо то всьо шо намалювали??
    }

    return 0;
}