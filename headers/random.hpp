#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <SFML/System/Vector2.hpp>

class Random {
    private:
        static std::random_device rd;
    
    public:
        Random();
        ~Random();

        static int randomBinaryChoice();
        static float randomHeight(sf::Vector2u windowSize, float ballRadius);
};

#endif