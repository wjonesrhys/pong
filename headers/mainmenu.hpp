#pragma once
#include <SFML/Graphics.hpp>
#include <menu.hpp>

class MainMenu : public Menu {
    private: 
        
    public:
        MainMenu(sf::RenderWindow &window, int maxItems);
        ~MainMenu();

};