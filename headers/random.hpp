#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random {
    private:
        std::random_device rd;
    
    public:
        Random();
        ~Random();

        int randomBinaryChoice();
        float randomHeight(sf::Vector2u windowSize, float ballRadius);
};

#endif