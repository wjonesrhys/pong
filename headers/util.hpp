#ifndef UTIL_HPP
#define UTIL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Util {
    private:
        
    public:
        Util();
        ~Util();

        static void print(std::string string, const sf::Vector2f& v1);     
        static void print(std::string string, const float& f);     
        static void print(std::string string);

};
#endif