#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <menu.hpp>
#include <vector>

class MenuSelector {
    private:
        sf::RectangleShape background;

        sf::Texture texture;
        sf::RenderWindow &window;

    public:
        Menu menu;

        MenuSelector(sf::RenderWindow &window, std::string menuType);
        ~MenuSelector();

        void draw();
        void setUpBackground();
        void loadMenu(std::string menuType);
        void setUpPauseMenu();
        void setUpAboutMenu();
        void setUpOptionsMenu();
        void setUpMainMenu();
};