#include <iostream>
#include "state.hpp"

State::State(std::string stateName) {
    std::cout << "base constructor called" << std::endl;
    this->stateName = stateName;
}

State::~State() {
    std::cout << "base destructor called" << std::endl;
}

void State::onEnter() {
    std::cout << "base on enter called" << std::endl;
}

void State::handleEvents() {
    std::cout << "base handle events called" << std::endl;
}

void State::update() {
    std::cout << "base update called" << std::endl;
}

void State::render() {
    std::cout << "base render called" << std::endl;
}

void State::pause() {
    std::cout << "base pause called" << std::endl;
}

void State::resume() {
    std::cout << "base resume called" << std::endl;
}

void State::onExit() {
    std::cout << "base on exit called" << std::endl;
}

std::string State::getStateName() {
    return this->stateName;
}