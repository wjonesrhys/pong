#pragma once
#include <SFML/Graphics.hpp>
#include <menu.hpp>

class PauseMenu : public Menu {
    private: 
        
    public:
        PauseMenu(sf::RenderWindow &window, int maxItems);
        ~PauseMenu();

        void draw();
};