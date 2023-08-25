#include <iostream>
#include "util.hpp"

using namespace std;

void Util::print(std::string msg) {
    cout << msg << endl;
}

void Util::print(int number) {
    cout << number << endl;
}

void Util::print(float number) {
    cout << number << endl;
}

void Util::print(double number) {
    cout << number << endl;
}

float Util::randFloatBetween(int lower, int higher) {
    return 0;
}

int Util::zeroOrOne() {
    int randNum = rand() * 2 / RAND_MAX;

    if (randNum == 0) {
        return -1;
    } 
    return 1;
}

