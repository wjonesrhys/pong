#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Menu {
    private:
        int menuSelected;
        int maxItems;
        sf::Font font;
        std::vector<sf::Text> menuItems;

    public:
        sf::RenderWindow &window;


        Menu(sf::RenderWindow &window, int maxItems);
        ~Menu();

        void draw(sf::RenderWindow& window);
        void addItem(std::string text, bool isOn, sf::Vector2f position);

        void MoveUp();
        void MoveDown();

        int MenuPressed();
        void SetMenuSelected(int index); 
};