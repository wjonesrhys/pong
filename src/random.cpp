#include <random.hpp>

//why is that the reason for sf being ok
#include <SFML/Main.hpp>

Random::Random() {

}

Random::~Random() {

}

int Random::randomBinaryChoice() {
    return rd() * 2 / RAND_MAX;
}

float Random::randomHeight(sf::Vector2u windowSize, float ballRadius) {
    int randNum = rd() * 2 / RAND_MAX;

    //calculate the y component of screen vector to the corner - considering radius
    float yScreenComponent = (windowSize.y/2 - ballRadius/2) / (windowSize.x/2 - ballRadius);

    if (randNum == 0) {
        return rand() * yScreenComponent / RAND_MAX;
    } 

    return rand() * yScreenComponent * -1 / RAND_MAX;
}