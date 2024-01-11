#include "state.hpp"

State::State(std::string stateName) {
    print("base constructor called");
    this->stateName = stateName;
}

State::~State() {
    print("base destructor called");
}

void State::onEnter() {
    print("base on enter called");
}

void State::handleEvents() {
    print("base handle events called");
}

void State::update() {
    print("base update called");
}

void State::render() {
    print("base render called");
}

void State::pause() {
    print("base pause called");
}

void State::resume() {
    print("base resume called");
}

void State::onExit() {
    print("base on exit called");
}

std::string State::getStateName() {
    return this->stateName;
}