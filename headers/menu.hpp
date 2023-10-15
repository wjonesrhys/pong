#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_MAIN_MENU 4

class Menu {
    private:
        int menuSelected;
        sf::Font font;
        sf::Text menu[MAX_MAIN_MENU];

    public:
        Menu(float width, float height);
        ~Menu();

        void draw(sf::RenderWindow& window);

        void MoveUp();
        void MoveDown();

        int MenuPressed();
};