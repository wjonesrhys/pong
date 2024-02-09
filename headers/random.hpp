#ifndef RANDOM_H
#define RANDOM_H

#include <SFML/System/Vector2.hpp>
#include <random>

class Random {
    private:
        static std::random_device rd;

    public:
        static int randomBinaryChoice();
        static int randomLeftOrRight();
        static float randomHeight(sf::Vector2u windowSize, float ballRadius);
};

#endif