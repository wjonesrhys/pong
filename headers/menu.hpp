#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Menu {
    private:
        sf::Font font;
        int menuSelected;        
        std::vector<sf::Text> optionTexts;
        std::vector<sf::Text> staticTexts;
        std::vector<sf::Shape*> shapes;
        

    public:
        Menu();
        ~Menu();

        std::vector<sf::Text> getOptionTexts();
        std::vector<sf::Text> getStaticTexts();
        std::vector<sf::Shape*> getShapes();

        void addShape(sf::Shape* shape);
        void addText(std::string text, sf::Vector2f position, std::string vectorName);

        void moveUp();
        void moveDown();

        int menuPressed();

        void clearColouredText();
        void colourMenuSelected();
        
        void setMenuSelected(int index);
};