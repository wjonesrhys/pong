#pragma once
#include "SFML/Graphics.hpp"

class Util {
    public:

        static void print(std::string msg);
        static void print(int number);
        static void print(float number);
        static void print(double number);
        
        static float randFloatBetween(int lower, int higher);
        static int zeroOrOne();

};