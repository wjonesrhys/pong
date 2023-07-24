#include <iostream>
#include <string>

#include "collision.hpp"

#include <SFML/Graphics.hpp>

Collision::Collision() {

}

Collision::~Collision() {

}

bool Collision::intersectsTop(sf::FloatRect rect) {
    if (rect.top < 0) {
        std::cout << "intersects top" << std::endl;
        return true;
    }
    return false;
}

bool Collision::intersectsBottom(sf::FloatRect rect, int height) {
    if (rect.top + rect.height > height) {
        std::cout << "intersects bottom" << std::endl;
        return true;
    }
    return false;
}

bool Collision::intersects(sf::FloatRect rect1, sf::FloatRect rect2) {
    std::cout << "left: " << rect1.left << std::endl;
    std::cout << "top: " << rect1.top << std::endl;
    std::cout << "height: " << rect1.height << std::endl;
    std::cout << "width: " << rect1.width << std::endl;

    

    return false;
}

bool Collision::intersects(sf::RectangleShape rect1, sf::RectangleShape rect2) {
    std::cout << "left: " << rect1.getGlobalBounds().left << std::endl;
    std::cout << "top: " << rect1.getGlobalBounds().top << std::endl;
    std::cout << "height: " << rect1.getGlobalBounds().height << std::endl;
    std::cout << "width: " << rect1.getGlobalBounds().width << std::endl;

    return true;
}

bool Collision::intersects(sf::CircleShape circle1, sf::CircleShape circle2) {
    return true;
}

bool Collision::intersects(sf::RectangleShape rect, sf::CircleShape circle) {
    return true;
}


